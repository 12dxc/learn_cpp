#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <list>
#include <sstream>
using namespace std;
using namespace this_thread;

// 线程基类
class XThread
{
public:
    // 启动线程
    virtual void Start()
    {
        is_exit_ = false;
        th_ = thread(&XThread::Main, this);
    }
    // 设置线程退出标志  并等待
    virtual void Stop()
    {
        is_exit_ = true;
        Wait();
    }
    // 等待线程退出（阻塞）
    virtual void Wait()
    {
        if (th_.joinable())
            th_.join();
    }
    // 线程是否退出
    bool is_exit()
    {
        return is_exit_;
    }

private:
    // 线程入口
    virtual void Main() = 0;
    bool is_exit_ = false;
    thread th_;
};

class XMsgServer : public XThread
{
public:
    // 给当前线程发消息
    void SendMsg(string msg)
    {
        unique_lock<mutex> lock(mux_);
        msgs_.push_back(msg);
    }

private:
    // 处理消息的线程入口函数
    void Main() override
    {
        while (!is_exit())
        {
            sleep_for(10ms);
            unique_lock<mutex> lock(mux_);
            if (msgs_.empty())
                continue;
            while (!msgs_.empty())
            {
                // 消息处理业务逻辑
                cout << "recv: " << msgs_.front() << endl;
                msgs_.pop_front();
            }
        }
    }

    // 消息队列缓存
    list<string> msgs_;

    // 互斥访问消息队列
    mutex mux_;
};
int main()
{
    XMsgServer server;
    server.Start();
    for (int i = 0; i < 10; i++)
    {
        stringstream ss;
        ss << " msg : " << i + 1;
        server.SendMsg(ss.str());
        sleep_for(500ms);
    }
    server.Stop();

    return 0;
}