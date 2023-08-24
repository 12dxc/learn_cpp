#include <iostream>
using namespace std;


int main()
{
    /*使用场景：
    *   1、switch只支持常量值固定相等的分支判断
    *   2、if还可以判断区间范围
    *   3、用switch能做的，用if也能做，反过来则不行
    * 性能比较：
    *   1、分支少时，差别不是很大；分支多时，switch性能较高
    *   2、if开始处几个分支效果高，之后效率递减
    *   3、switch所有的case的速度几乎一样
    */

    system("pause");
    return 0;
}