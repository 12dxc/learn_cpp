#include <iostream>
using namespace std;

void print_range(int lnum, int rnum)
{
    if (lnum > rnum) // ���������������������򽻻����Σ���Χ��������
    {
        print_range(rnum, lnum);
        return;
    }
    int num;
    while (lnum <= rnum) // ������С�ڵ�������ʱ����ζ���ѵõ�����֮���������
    {
        cout << lnum << " ";
        ++lnum;
    }
    cout << endl;
}

int main()
{
    cout << "��������������:" << endl;
    int lnum = 0, rnum = 0;
    cin >> lnum >> rnum;

    print_range(lnum, rnum);

    return 0;
}
