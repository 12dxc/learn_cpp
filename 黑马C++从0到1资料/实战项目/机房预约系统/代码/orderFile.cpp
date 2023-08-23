#include "orderFile.h"

// 截取字符串并追加在map容器中
void addMap(int pos, string data, map<string, string>& m)
{
    string key;
    string value;
    if (pos != -1)
    {
        key = data.substr(0, pos);
        value = data.substr(pos + 1, data.size() - pos - 1); // 截的个数为字符串长度减pos+1}
        m.insert(make_pair(key, value));
    }
}

// 构造函数
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;     // 日期
    string interval; // 时间段
    string stuId;    // 学生编号
    string stuName;  // 学生姓名
    string roomId;   // 机房编号
    string status;   // 预约状态

    this->m_Size = 0; // 记录条数

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {

        map<string, string> m;

        int pos = date.find(":"); // 4
        addMap(pos, date, m);

        pos = interval.find(":");
        addMap(pos, interval, m);

        pos = stuId.find(":");
        addMap(pos, stuId, m);

        pos = stuName.find(":");
        addMap(pos, stuName, m);

        pos = roomId.find(":");
        addMap(pos, roomId, m);

        pos = status.find(":");
        addMap(pos, status, m);

        // 将小的map容器放入到大的map容器中
        m_orderData.insert(make_pair(this->m_Size, m));
        // 增加条数
        this->m_Size++;
    }
    ifs.close();
}
// 更新预约记录
void OrderFile::updateOrder()
{
    if (this->m_Size == 0)
    {
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out | ios::trunc);

    for (int i = 0; i < this->m_Size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }

    ofs.close();
}