#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include"globalFile.h"


class OrderFile
{
public:
    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录预约条数
    int m_Size;

    //记录所有的预约信息的容器
    map<int, map<string, string>>m_orderData;
};

