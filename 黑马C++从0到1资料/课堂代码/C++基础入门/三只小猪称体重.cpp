#include<iostream>
using namespace std;

int main() {
	//三只小猪称体重，判断那只最重
	
	//1、创建三只小猪的体重变量
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;


	//2、让用户输入三只小猪的重量
	cout << "请输入三只小猪的体重，他们名字分别是A、B、C" << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;


	//3、判断那只最重
	//判断A和B的重量
	if (num1 > num2) {  // A比B重
		if (num1 > num3) {  // A比C重
			cout << "小猪A最重" << endl;
		}
		else {  // C比A重
			cout << "小猪C最重" << endl;

		}
	}
	else{   // B比A重
		if (num2 > num3) {  // B比C重
			cout << "小猪B最重" << endl;

		}
		else {  // C比B重
			cout << "小猪C最重" << endl;

		}
	}

	system("pause");

	return 0;
}