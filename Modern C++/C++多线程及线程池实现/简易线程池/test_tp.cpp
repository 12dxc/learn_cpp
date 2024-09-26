#include "ThreadPool.h"
#include <iostream>
using namespace std;

// 线程池测试

class MyTask : public XTask
{
public:
   int Run()
   {
       cout << "=================================" << endl;
       cout << this_thread::get_id() << " Mytask " << name << endl;
       cout << "=================================" << endl;
       for (int i = 0; i < 10; i++)
       {
           if (is_exit())
               break;
           cout << "." << flush;
           this_thread::sleep_for(500ms);
       }
       return 100;
   }
   string name = "";
};
int main(int argc, char* argv[])
{
   XThreadPoll pool;
   pool.Init(16);
   pool.Start();

   // MyTask task1;
   // task1.name = "test name 001";
   // pool.AddTask(&task1);
   // MyTask task2;
   // task2.name = "test name 002";
   // pool.AddTask(&task2);
   {
       auto task3 = make_shared<MyTask>();
       task3->name = "test name 003";
       pool.AddTask(task3);
       auto re = task3->GetReturn();
       cout << "task3->GetReturn() = " << re << endl;
   }

   this_thread::sleep_for(100ms);
   cout << "task run count = " << pool.task_run_count() << endl;

   this_thread::sleep_for(1s);
   pool.Stop();
   cout << "task run  count = " << pool.task_run_count() << endl;

   getchar();
   return 0;
}