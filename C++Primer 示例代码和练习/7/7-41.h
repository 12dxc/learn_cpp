#include <string>
#include <iostream>
using namespace std;

struct Sales_data
{
     friend istream &read(istream &is, Sales_data &item);
     friend ostream &print(ostream &os, const Sales_data &item);
     friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
     // �����Ĺ��캯��
     Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
     {
          cout << "Sales_data(const string &s, unsigned n, double p) ����" << endl;
     }
     Sales_data() : Sales_data(" ", 0, 0)
     {
          cout << "Sales_data() ����" << endl;
     }
     Sales_data(const string &s) : Sales_data(s, 0, 0)
     {
          cout << "Sales_data(const string &s)����" << endl;
     }
     Sales_data(istream &is) : Sales_data()
     {
          read(is, *this);
          cout << "Sales_data(istream &is) ����" << endl;
     }

     // ��Ա����
     // ��ȡ���
     string isbn() const // ��constʹ���ڲ����岻���޸�����
     {
          return this->bookNo;
     }
     // ��һ������ӵ���һ������
     Sales_data &combine(const Sales_data &rhs);
     // ��ȡ�۳��鼮��ƽ���۸�
     double avg_price() const;

     // ���ݳ�Ա
private:
     //  ���
     string bookNo;
     // ����
     unsigned units_sold = 0;
     // ���۶�
     double revenue = 0.0;
};

// ��Ա�������ⶨ��  ��ָ��������
inline double Sales_data::avg_price() const
{
     if (units_sold)
     {
          return revenue / units_sold;
     }
     else
     {
          return 0;
     }
}
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
     units_sold += rhs.units_sold;
     revenue += rhs.revenue;
     return *this;
}
// ������صķǳ�Ա����
//  ��Ӳ���
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
     Sales_data sum = lhs; // ��lhs�����ݳ�Ա������sum
     sum.combine(rhs);
     return sum;
}
// �������
istream &read(istream &is, Sales_data &item)
{
     // ���õ���
     double price = 0;
     is >> item.bookNo >> item.units_sold >> price;
     // Ϊ���۶ֵ  ������ĵ��� * ����
     item.revenue = price * item.units_sold;

     return is;
}
// �������
ostream &print(ostream &os, const Sales_data &item)
{
     os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price() << endl;
     return os;
}
