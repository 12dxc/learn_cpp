#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <execution>
using namespace std;
using namespace chrono;

static const char base16[] = "0123456789abcdef";

void Base16Encode(const unsigned char *data, int size, unsigned char *out)
{
    for (int i = 0; i < size; i++)
    {
        unsigned char d = data[i];
        char a = base16[d >> 4];   // 高位映射
        char b = base16[d & 0x0F]; // 低位映射
        out[i * 2] = a;
        out[i * 2 + 1] = b;
    }
}
// C++11 多核base16编码
void Base16EncodeThread(const vector<unsigned char> &data, vector<unsigned char> &out)
{
    int size = data.size();
    int th_count = thread::hardware_concurrency(); // 系统支持的线程核心数
    // 切片数据
    int slice_count = size / th_count; // 余数丢弃
    if (size < th_count)               // 只切一片
    {
        th_count = 1;
        slice_count = size;
    }

    // 准备好线程
    vector<thread> ths;
    ths.resize(th_count);

    // 任务分配到各个线程
    for (int i = 0; i < th_count; i++)
    {
        int offset = i * slice_count;
        int count = slice_count;

        // 最后一个线程
        if (th_count > 1 && i == th_count - 1)
        {
            count = slice_count + size % th_count;
        }
        // cout << offset << ":" << count << endl;
        ths[i] = thread(Base16Encode, data.data() + offset, count, out.data());
    }
    // 等待所有线程处理结束
    for (auto &th : ths)
    {
        th.join();
    }
}
int main()
{
    string test_data = "测试base16编码";
    unsigned char out[1024] = {0};
    Base16Encode((unsigned char *)test_data.data(), test_data.size(), out);
    // cout << "base16: " << out << endl;

    // 初始化测试数据
    vector<unsigned char> in_data;
    in_data.resize(1024 * 1024 * 10); // 10M数据量
    for (int i = 0; i < in_data.size(); i++)
    {
        in_data[i] = i % 256;
    }
    vector<unsigned char> out_data;
    out_data.resize(in_data.size() * 2);

    // 测试单线程base16编码效率
    {
        cout << "单线程base16 开始计算" << endl;
        auto start = system_clock::now();
        Base16Encode(in_data.data(), in_data.size(), out_data.data());
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start); // 转换为毫秒
        cout << "编码: " << in_data.size() << "字节数据花费"
             << duration.count() << "毫秒" << endl;
        // cout << out_data.data() << endl;
    }

    // 测试C++11 多线程Base16编码
    {
        cout << "C++11 多线程Base16 开始计算" << endl;
        auto start = system_clock::now();
        Base16EncodeThread(in_data, out_data);
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start); // 转换为毫秒
        cout << "编码: " << in_data.size() << "字节数据花费"
             << duration.count() << "毫秒" << endl;
    }

    // 测试C++17 多核并行计算Base16编码
    {
        cout << "C++17 多核并行计算Base16 开始计算" << endl;
        auto start = system_clock::now();
        unsigned char *idata = in_data.data();
        unsigned char *odata = out_data.data();
        // #include <exception>  C++17
        for_each(std::execution::par, // 并行计算 多核
                 in_data.begin(), in_data.end(),
                 [&](auto &d) { // 多线程进入此函数
                     char a = base16[d >> 4];
                     char b = base16[d & 0x0F];
                     int index = &d - idata;
                     odata[index * 2] = a;
                     odata[index * 2 + 1] = b;
                 });

        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start); // 转换为毫秒
        cout << "编码: " << in_data.size() << "字节数据花费"
             << duration.count() << "毫秒" << endl;
    }
    getchar();

    return 0;
}