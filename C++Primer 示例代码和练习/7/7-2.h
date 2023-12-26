#include <string>
using namespace std;

struct Sales_data
{
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
