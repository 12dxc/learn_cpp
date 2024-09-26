#include<iostream>
using namespace std;
#include<ctime>
int main() {
	//生成随机数种子 利用当前系统时间生成随机数，防止随机数相同
	srand((unsigned int)time(NULL));


	//1、系统生成随机数
	int num = rand() % 100 + 1;  // 生成 0+1~99+1 的随机数
	//cout << num << endl;
	//2、玩家进行猜测
	cout << "请输入0~99来进行游戏" << endl;
	int val = 0;
	while (1) {
		cin >> val;
		//3、判断玩家的猜测
		//猜对了  退出游戏
	    //猜错  提示猜的结构 或大或小，重新返回第二步
		if (val < num) {
			cout << "猜小了" << endl;
		}
		else if (val > num) {
			cout << "猜大了" << endl;
		}
		else {
			cout << "猜对了" << endl;	
			break;
		}
	}
	

	system("pause");

	return 0;
}