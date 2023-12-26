#include <string>
#include <iostream>
using namespace std;

struct Sales_data
{
     // �����Ĺ��캯��
     Sales_data() = default;
     Sales_data(const string &s) : bookNo(s) {}
     Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
     Sales_data(istream &);

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
     //  ���
     string bookNo;
     // ����
     unsigned units_sold = 0;
     // ���۶�
     double revenue = 0.0;
};

// ��Ա�������ⶨ��  ��ָ��������
double Sales_data::avg_price() const
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
// ��������ʼ�����캯��
Sales_data::Sales_data(istream &is)
{
     read(is, *this);
}
