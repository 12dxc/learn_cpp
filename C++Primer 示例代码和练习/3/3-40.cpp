#include <iostream>
#include <cstring>
using namespace std;

const char cstr1[] = "hello";
const char cstr2[] = "world";

int main()
{
    char largeStr[20];
    // ����һ�����������copy������������
    strcpy(largeStr, cstr1);
    // �������������һ���ո�
    strcat(largeStr, " ");
    // ���ڶ������鸽������������
    strcat(largeStr, cstr2);

    return 0;
}
