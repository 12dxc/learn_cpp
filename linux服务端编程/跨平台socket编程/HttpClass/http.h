/* 对httpServer的封装 */

#include <thread>
#include <iostream>
#include <string>
#include <regex>
using namespace std;
#include "Tcp.h"

// http协议响应类
class HttpResPonse
{
public:
    // 处理http请求，且使文件指针指向待发送文件
    bool setRequest(string request)
    {
        string src = request;
        string pattern = "^([A-Z]+) /([a-zA-Z0-9]*([.][a-zA-Z]*)?)[?]?(.*) HTTP/1"; // 定义正则表达式

        regex r(pattern);
        smatch mas;
        regex_search(src, mas, r);
        if (mas.size() == 0)
        {
            printf("%s failed!\n", pattern.c_str());
            return false;
        }
        // 匹配成功  分别取出http请求所带的信息
        string type = mas[1]; // 请求类型
        string path = "/";
        path += mas[2];           // 文件路径
        string filetype = mas[3]; // 文件类型
        string query = mas[4];    // 文件请求后缀 id=1
        if (filetype.size() > 0)
            filetype = filetype.substr(1, filetype.size() - 1); // 截取文件类型前面的'.'

        if (type != "GET") // 目前只处理GET请求
        {
            printf("Not GET!!!\n");
            return false;
        }
        string filename = path; // 存储请求文件路径
        if (path == "/")        // 未请求文件，则给默认值
            filename = "/index.html";

        string filepath = "www" + filename; // 本地文件路径

        // 处理php脚本
        if (filetype == "php")
        {
            string cmd = "php-cgi ";
            cmd += filepath;
            cmd += " ";

            // 处理url参数
            for (char &ch : query)
                if (ch == '&')
                    ch = ' ';
            cmd += query;

            cmd += " > ";
            filepath += ".html";
            cmd += filepath;

            printf("%s\n", cmd.c_str());
            system(cmd.c_str());
            cout << "filepath: " << filepath << endl;
        }

        fp = fopen(filepath.c_str(), "rb"); // 打开客户端请求的文件
        if (fp == NULL)                     // 未找到，应返回404，现不完成
        {
            printf("open file %s \n failed!\n", filepath.c_str());
            return false;
        }
        // 获取文件大小
        fseek(fp, 0, SEEK_END);
        filesize = ftell(fp);
        fseek(fp, 0, 0); // 重置文件偏移指针

        // 截取php-cgi生成的头
        if (filetype == "php")
        {
            char c = 0;
            int headsize = 0;
            while (fread(&c, 1, 1, fp) > 0)
            {
                headsize++;
                if (c == '\r')
                {
                    fseek(fp, 3, SEEK_CUR); // 跳过可能的 "\r\n\n"
                    headsize += 3;
                    break;
                }
            }
            filesize -= headsize; // 减去头的大小，只发送响应体
        }

        return true;
    }
    // 组装响应头信息
    string getHead()
    {
        string msg = "";
        // 组装http消息头
        msg = "HTTP/1.1 200 OK\r\n";
        msg += "Servevr: HttpServer\r\n";
        msg += "Content-Type: text/html\r\n";
        msg += "Content-Length: ";
        msg += to_string(filesize) + "\r\n";
        msg += "\r\n";

        return msg;
    }
    // 读取需发送的文件
    int read(char *buf, int bufsize)
    {
        return fread(buf, 1, bufsize, fp);
    }

private:
    long filesize = 0;
    FILE *fp = nullptr;
};

// http客户端类  处理接收请求
class HttpClient
{
public:
    // 启动客户端  获取Tcp类操作客户端，并开启线程处理
    bool start(Tcp client)
    {
        this->client = client;
        thread sth(&HttpClient::Main, this);
        sth.detach();

        return true;
    }
    // 使用线程处理处理客户端请求  此为入口函数
    void Main()
    {
        char buf[10240] = {0};
        while (true)
        {
            int len = client.recv(buf, sizeof(buf) - 1);
            if (len <= 0)
                break;
            buf[len] = '\0';
            // 解析并处理http请求
            if (!res.setRequest(buf))
                break;
            // 响应http请求
            string head = res.getHead();
            // 发送组装好的http响应消息
            if (client.send(head.c_str(), head.size()) <= 0)
                break;

            // 发送正文，即客户端请求的文件
            int size = sizeof(buf);
            bool error = false;
            for (;;)
            {
                int len = res.read(buf, size); // 这里读的是文件
                if (len < 0)
                {
                    error = true;
                    break;
                }
                else if (len == 0)
                    break;
                if (client.send(buf, len) <= 0) // 将读到的文件发送给客户端
                {
                    error = true;
                    break;
                }
            }
        }
        client.close();
        delete this; // 此类未使用析构，都从堆上开辟，需销毁
    }

private:
    Tcp client;
    HttpResPonse res;
};

// http服务器类  处理连接请求
class HttpServer
{
public:
    // 启动服务器
    bool start(unsigned short port)
    {
        isexit = false;
        server.createSocket();
        if (!server.bind(port))
            return false;
        thread sth(&HttpServer::Main, this);
        sth.detach();
        return true;
    }

    void stop()
    {
        isexit = true;
    }

    // 开一个线程专门处理客户端连接请求
    void Main()
    {
        while (!isexit)
        {
            Tcp client = server.accept();
            if (client.sock <= 0)
                continue;
            // 使用http客户端类专门处理接收请求
            HttpClient *th = new HttpClient(); // 客户端需要挂起，故在堆中开辟
            th->start(client);
        }
    }

private:
    Tcp server;
    bool isexit = false;
};
