#include<iostream>
using namespace std;

int main() {

	//1���ַ��ͱ���������ʽ
	char ch = 'a';
	cout << ch << endl;

	//2���ַ��ͱ�����ռ�ڴ��С
	cout << "char�ַ��ͱ�����ռ�ڴ棺" << sizeof(char) << endl;

	//3���ַ��ͱ�����������
	//char ch2 = "b";  �����ַ��ͱ���ʱ��Ҫ�õ�����
	//char ch2 = 'abcde'; �����ַ��ͱ���ʱ����������ֻ����һ���ַ�
	
	//4���ַ��ͱ�������ASCII����
	//a - 97
	//A - 65
	cout << (int)ch << endl; //ǿת�����Σ��Ϳɲ鿴�ַ�ASCII��

	system("pause");

	return 0;
}