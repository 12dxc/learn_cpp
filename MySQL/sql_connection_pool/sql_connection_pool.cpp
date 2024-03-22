#include <cstdio>
#include <string>
using std::string;
#include "sql_connection_pool.h"

/* -------- 数据库操作类 -------- */

// 初始化数据库连接
Connection::Connection()
{
    conn_ = mysql_init(nullptr);
}

// 释放数据库连接资源
Connection::~Connection()
{
    if (conn_ != nullptr)
        mysql_close(conn_);
}

// 连接数据库
bool Connection::connect(string ip, string user,
    string passwd, string dbname, unsigned short port)
{
    MYSQL* p = mysql_real_connect(conn_, ip.c_str(), user.c_str(),
        passwd.c_str(), dbname.c_str(), port, nullptr, 0);
    return p != nullptr;
}

// 更新操作 insert、delete、update
bool Connection::update(string sql)
{
    if (mysql_query(conn_, sql.c_str()))
    {
        LOG("更新失败" + sql);
        return false;
    }
    return true;
}

// 查询操作 select
MYSQL_RES* Connection::select(string sql)
{
    if (mysql_query(conn_, sql.c_str()))
    {
        LOG("查询失败" + sql);
        return nullptr;
    }
    return mysql_use_result(conn_);
}



/* -------- 数据库连接池类 --------*/

// 获取连接池对象实例  线程安全的懒汉单例模式
ConnectionPool* ConnectionPool::getConnectionPool()
{
    static ConnectionPool pool;  // 静态自动进行lock和unlock
    return &pool;
}

// 从配置文件中加载配置项  
bool ConnectionPool::loadConfigFile()
{
    FILE* pf;
    errno_t err = fopen_s(&pf, "mysql.ini", "r");
    if (pf == nullptr)
    {
        LOG("my");
        return false;
    }

    while (!feof(pf))
    {
        char line[1024] = {};
        fgets(line, 1024, pf);
        string str = line;
        int idx = str.find('=', 0);
        if (idx == -1)   // 无效配置项
            continue;
        int endidx = str.find('\n', idx);
        string key = str.substr(0, idx);
        string val = str.substr(idx + 1, endidx - idx - 1);

        if (key == "ip")
            ip_ = val;
        else if (key == "port")
            port_ = atoi(val.c_str());
        else if (key == "username")
            username_ = val;
        else if (key == "password")
            passwd_ = val;
        else if (key == "dbname")
            dbname_ = val;
        else if (key == "initSize")
            initSize_ = atoi(val.c_str());
        else if (key == "maxSize")
            maxSize_ = atoi(val.c_str());
        else if (key == "maxIdleTime")
            maxIdleTime_ = atoi(val.c_str());
        else if (key == "connectionTimeOut")
            connTimeout_ = atoi(val.c_str());
    }
    return true;
}

// 连接池的构造
ConnectionPool::ConnectionPool()
{
    // 加载配置项了
    if (!loadConfigFile())
    {
        return;
    }

    // 创建初始数量的连接
    for (int i = 0; i != initSize_; ++i)
    {
        Connection* p = new Connection();
        p->connect(ip_, username_, passwd_, dbname_, port_);
        p->refreshAliveTime();  // 刷新开始空闲的起始时间
        connQue_.push(p);
        ++connCnt_;
    }

    // 启动一个新的线程，作为连接的生产者
    std::thread produce(std::bind(&ConnectionPool::produceConnectionTask, this));
    produce.detach();

    // 启动一个新的定时线程，扫描超过maxIdleTime时间的空闲连接，对于多余的连接进行回收
    std::thread scanner(std::bind(&ConnectionPool::scannerConnectionTask, this));
    scanner.detach();

}

// 运行在独立的线程中，专门负责生成新连接
void ConnectionPool::produceConnectionTask()
{
    for (;;)
    {
        std::unique_lock<std::mutex>lock(queMutex_);
        while (!connQue_.empty())
        {
            cv.wait(lock);  // 队列不空，此处生产者线程进入等待状态
        }

        // 连接数量未达到上线，继续创建新连接
        if (connCnt_ < maxSize_)
        {
            Connection* p = new Connection();
            p->connect(ip_, username_, passwd_, dbname_, port_);
            p->refreshAliveTime();
            connQue_.push(p);
            ++connCnt_;
        }

        // 通知消费者线程，可以消费连接了
        cv.notify_all();
    }
}

// 给外部提供接口，从连接池获取一个可用的空闲连接
std::shared_ptr<Connection> ConnectionPool::getConnection()
{
    std::unique_lock<std::mutex>lock(queMutex_);
    while (connQue_.empty())
    {
        if (std::cv_status::timeout == cv.wait_for(lock, std::chrono::milliseconds(connTimeout_))) // 在指定时间内尝试获取连接
        {
            if (connQue_.empty())
            {
                LOG("获取空闲连接超时... 获取连接失败！");
                return nullptr;
            }
        }
    }

    /* shared_ptr智能指针析构时，会把connection资源直接delete掉，相当于
     * 调用connection的析构函数，connection就被close掉了。
     * 这里需要自定义shared_ptr的释放资源的方式，把connection直接归还到queue当中 */
    std::shared_ptr<Connection> sp(connQue_.front(),
        [&](Connection* pcon) {
            // 这里是在服务器应用线程中调用的，所以一定要考虑队列的线程安全操作
            std::unique_lock<std::mutex>lock(queMutex_);
            pcon->refreshAliveTime();
            connQue_.push(pcon);
        });
    connQue_.pop();
    cv.notify_all();  // 消费完连接后，通知生产者线程检查一下，如果队列为空，赶紧生产连接
    return sp;
}

// 扫描超过maxIdleTime时间的空闲连接，对于多余的连接进行回收
void ConnectionPool::scannerConnectionTask()
{
    for (;;)
    {
        // 通过sleep模拟定时效果
        std::this_thread::sleep_for(std::chrono::seconds(maxIdleTime_));
        // 扫描整个队列，释放多余的连接
        std::unique_lock<std::mutex>lock(queMutex_);
        while (connCnt_ > initSize_)
        {
            Connection* p = connQue_.front();
            if (p->getAliveTime() > (maxIdleTime_ * 1000))
            {
                connQue_.pop();
                --connCnt_;
                delete p;   // 调用~Connection()释放连接
            }
            else
            {
                break;  //队头的连接都没超过maxIdleTime_，其他连接肯定也没有
            }
        }
    }
}



