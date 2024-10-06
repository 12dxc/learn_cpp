#include<iostream>
using namespace std;

int main() {
	//敲桌子案例
	//1、先输出1~100的数字
	for (int i = 1; i <= 100; i++)
	{
		//2、从100个数字在找到特殊数字，然后敲桌子
		//如果是7的倍数、个位有7、十位有7，打印敲桌子
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7) {
			cout << "敲桌子" << endl;
		}
		else{
			cout << i << endl;
		}
	}

	system("pause");

	return 0;
}