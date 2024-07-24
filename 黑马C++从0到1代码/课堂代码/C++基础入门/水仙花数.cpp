#include<iostream>
using namespace std;

int main() {
	//1、先打印所有的三位数字
	int nums = 100;
	while (nums <= 999) {
		//2、从所有数中找到水仙花数
		int a = nums % 10;       //个位
		int b = nums / 10 % 10;  //十位
		int c = nums / 100;      //百位
		//是水仙花才打印
		if (a*a*a + b*b*b + c*c*c == nums) {
			cout << nums << endl;
		}
		nums++;
	}
	
	system("pause");

	return 0;
}