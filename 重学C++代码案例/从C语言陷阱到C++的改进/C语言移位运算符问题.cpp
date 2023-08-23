#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // C语言的移位运算
    /*
        // 逻辑移位，直接对数据所有位进行移动，空位补0
        char a1 = 0x63; // 0110 0011
        a1 = (a1 << 4); // 0011 0000
        printf("0x%x\n", a1);

        a1 = 0x63;      // 0110 0011
        a1 = (a1 >> 4); // 0000 0110
        printf("0x%x\n", a1);

        char a2 = 0x95; // 1001 0101
        a2 = (a2 << 4); // 0101 0000
        printf("0x%x\n", a2);

        // 算术移位：
        // 对于无符号型值，算术移位等同于逻辑移位。
        // 而对于有符号型值 ，算术左移等同于逻辑左移，算术右移补的是符号位，正数补0，负数补1。
        a2 = 0x95;      // 1001 0101
        a2 = (a2 >> 4); // 1111 1001  //最左位是1 所以是负数，会采用算术右移，移除的空位补1
        printf("0x%x\n", a2);

        // C语言并未给出算术右移冲突问题的解决，所有只能使用无符号类型
        unsigned a3 = 0x95; // 1001 0101
        a3 = (a3 >> 4);     // 0000 1001
        printf("0x%x\n", a3);


        // 移位运算要大于0，小于位数
        unsigned char piv = 0xFF; // 1111 1111
        // unsigned char super = (1 << 8);   //超过最大位数，会直接将值置0
        unsigned char super = (1 << 7);
        unsigned char user = (1 << 6);

        if (super & piv)
        {
            cout << "你是管理员权限" << endl;
        }
        if (user & piv)
        {
            cout << "你是用户权限" << endl;
        }
    */

    // C++的移位运算符  bitset
    // bitset<位数> 变量名
    bitset<10> Permissions = 0xFF; // 我的权限
    bitset<10> super = (1 << 7);
    bitset<10> user = (1 << 6);

    // 用bitset创建的变量可以直接输出
    cout << Permissions << endl;
    cout << super << endl;
    cout << user << endl;

    if ((Permissions & super) == super) // 通过按位与可判断某一位是否为1
    {
        cout << "你是管理员权限" << endl;
    }
    if ((Permissions & user) == user)
    {
        cout << "你是用户权限" << endl;
    }

    return 0;
}