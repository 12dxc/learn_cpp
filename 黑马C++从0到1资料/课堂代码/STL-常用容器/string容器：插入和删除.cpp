#include <iostream>
using namespace std;
#include <string>

// �ַ��� �����ɾ��

void test01()
{
    string str = "hello";

    // ����
    str.insert(1, "111");

    cout << "str = " << str << endl; // h111ello

    // ɾ��
    str.erase(1, 3);
    cout << "str = " << str << endl; // hello
}

int main()
{
    test01();

    system("pause");
    return 0;
}