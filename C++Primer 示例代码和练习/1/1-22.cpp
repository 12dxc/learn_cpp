#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total; // ����͵ı���
    // �����һ�����׼�¼����ȷ�������ݿ��Դ���
    if (std::cin >> total)
    {
        Sales_item trans; // ������һ�����׼�¼�ı���
        // ���벢����ʣ�ཻ�׼�¼
        while (std::cin >> trans)
        {
            // ������ڴ�����ͬ����
            if (total.isbn() == trans.isbn())
                // �������۶�
                total += trans;
            // �����ӡǰһ����Ľ��
            else
            {
                std::cout << total << std::endl;
                total = trans; // total ��ʾ��һ��������۶�
            }
        }
        std::cout << total << std::endl; // ��ӡ���һ����Ľ��
    }
    else
    {
        // �����룬��������
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
