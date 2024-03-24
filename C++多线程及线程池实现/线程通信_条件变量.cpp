#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <list>
#include <sstream>
#include <condition_variable>
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

protected:
    bool is_exit_ = false;

private:
    // 线程入口
    virtual void Main() = 0;
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
        lock.unlock();
        cv_.notify_one(); // 通知信号
    }
    void Stop() override
    {
        is_exit_ = true;
        cv_.notify_all();
        Wait();
    }

private:
    // 处理消息的线程入口函数
    void Main() override
    {
        while (!is_exit())
        {
            unique_lock<mutex> lock(mux_);
            cv_.wait(lock, [this]()
                     { 
                        cout<<"wait cv"<<endl;
                        if(is_exit())return true;
                        return !msgs_.empty(); }); // 等待信号
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

    condition_variable cv_;
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
    cout << "server stoped!" << endl;

    return 0;
}