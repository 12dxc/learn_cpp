#include <iostream>
#include <vector>
using namespace std;

// �Ƚ����������Ƿ����
bool compare(int *pb1, int *pe1, int *pb2, int *pe2)
{
    // �ȱȽϳ��ȣ������������αȽ�ÿ��Ԫ��
    if ((pe1 - pb1) != (pe2 - pb2))
    {
        return false;
    }
    else
    {
        for (auto i = pb1, j = pb1; (i != pe1) && (j != pe2); i++, j++)
        {
            if (*i != *j)
                return false;
        }
        return true;
    }
}

int main()
{

    // array
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
    {
        cout << "�������" << endl;
    }
    else
    {
        cout << "���鲻���" << endl;
    }

    cout << "===========================" << endl;

    // �Ա���������
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    if (v1 == v2)
    {
        cout << "�������" << endl;
    }
    else
    {
        cout << "���鲻���" << endl;
    }

    return 0;
}
