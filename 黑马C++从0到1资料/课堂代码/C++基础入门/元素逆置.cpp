#include<iostream>
using namespace std;

int main() {
	//ʵ������Ԫ������
	//1����������
    int arr[] = { 1,3,2,5,4 };
	
	//2��ʵ������
	int start = 0;  //��ʼԪ���±�
	int end = sizeof(arr) / sizeof(arr[0]) - 1;  //ĩβԪ���±�
	while (start < end) {
		//ʵ��Ԫ�ػ���
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		//�±����
		start++;
		end--;
	}

	//3����ӡ���ú������
	cout << "����Ԫ�����ú�" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");

	return 0;
}