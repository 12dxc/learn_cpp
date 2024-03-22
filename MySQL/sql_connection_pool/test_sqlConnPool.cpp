#include <iostream>
#include "sql_connection_pool.h"

// sql指令
std::string sql = std::format("insert into score(name, \
      math,english,chinese) value('{}',{},{},{})", "zhangSan", 90, 78, 60);
void mysql_update();

int main()
{
    // 单连接测试
    /*Connection conn;
    conn.connect("127.0.0.1", "root", "root", "test", 3306);
    conn.update(sql);*/

    clock_t begin = clock();

    // 单线程连接对比
#if 0 
    ConnectionPool* cp = ConnectionPool::getConnectionPool();  // 线程池单例
    for (int i = 0; i < 10000; ++i)
    {
        // 批量单连接测试
        /*Connection conn;
        conn.connect("127.0.0.1", "root", "root", "test", 3306);
        conn.update(sql);*/

        // 使用连接池测试
        std::shared_ptr<Connection> sp = cp->getConnection();
        sp->update(sql);
    }
#endif
    // 四线程连接对比
#if 1
    std::thread t1(mysql_update);
    std::thread t2(mysql_update);
    std::thread t3(mysql_update);
    std::thread t4(mysql_update);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
#endif

    clock_t end = clock();
    cout << std::format("{}ms", end - begin) << endl;;

    return 0;
}

void mysql_update()
{
    ConnectionPool* cp = ConnectionPool::getConnectionPool();  // 线程池单例
    for (int i = 0; i < 2500; ++i)
    {
        // 批量单连接测试
        /*Connection conn;
        conn.connect("127.0.0.1", "root", "root", "test", 3306);
        conn.update(sql);*/

        // 使用连接池测试
        std::shared_ptr<Connection> sp = cp->getConnection();
        sp->update(sql);
    }
}