#include<iostream>;
using namespace std;
#include<string>

class C1 {
	int m_A;   //Ĭ��Ȩ��  ˽��
};
struct C2 {
	int m_A;    //Ĭ��Ȩ��  ����
};

int main() {
/*
struct��class����
   struct  Ĭ��Ȩ��Ϊ  ����  public
   class   Ĭ��Ȩ��Ϊ  ˽��  private
*/

	C1 c1;
	//c1.m_A = 100;   ���ɷ��� ����

	C2 c2;
	c2.m_A = 100;   // ���Է���

	system("pause");
	return 0;
}
