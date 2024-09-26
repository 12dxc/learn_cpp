#include "ThreadPool/ThreadPool.h"
#include <iostream>
#include <sstream>
using namespace std;

// 命令行视频转码工具
// 使用ffmpeg工具，完成此需求： 
// 1、用户输入 视频源 输出视频尺寸
// 2、在线程池中执行转码任务
// 3、转码任务调用ffmpeg

// 继承线程池的任务类
class XVideoTask :public XTask
{
public:
    string in_path;
    string out_path;
    int width = 0;
    int height = 0;
private:
    int Run()
    {
        // 转码指令：ffmpeg -y -i test.mp4 -s 400x300 400.mp4 >log.txt 2>&1 
        stringstream ss;
        ss << "ffmpeg -y -i " << in_path << " ";
        if (width > 0 && height > 0)
            ss << " -s " << width << "x" << height << " ";
        ss << out_path;
        ss << " >" << this_thread::get_id() << ".txt 2>&1";
        return system(ss.str().c_str());
    }
};
int main()
{
    XThreadPoll pool;
    pool.Init(16);
    pool.Start();

    this_thread::sleep_for(200ms);
    while (true)
    {
        this_thread::sleep_for(200ms);
        cout << "=====================================\n" << endl;
        auto task = make_shared<XVideoTask>();
        cout << "请输入命令（v e l）："; //v 输入参数执行，e 为退出，l 为重新输入
        string cmd;
        cin >> cmd;
        if (cmd == "e")
            break;
        else if (cmd == "l")
            continue;
        cout << "视频源：";
        cin >> task->in_path;
        cout << "目标：";
        cin >> task->out_path;
        cout << "输出宽：";
        cin >> task->width;
        cout << "输出高：";
        cin >> task->height;
        pool.AddTask(task);
    }
    pool.Stop();


    return 0;
}