/* http服务器 可解析http请求和php脚本 */

#include <cstdlib>
#include <thread>
#include <string>
#include <regex>
using namespace std;

#include "Tcp.h"

class TcpThread
{
public:
    void Main()
    {
        char buf[10000] = {0}; // 存储消息头
        while (true)
        {
            // 接受http客户端请求
            int recvLen = client.recv(buf, sizeof(buf) - 1);
            if (recvLen <= 0)
            {
                Close();
                return;
            }
            buf[recvLen] = '\0';
            printf("========> recv <========\n%s================\n", buf);

            // 通过正则表达式分析http请求
            string src = buf;
            string pattern = "^([A-Z]+) /([a-zA-Z0-9]*([.][a-zA-Z]*)?)[?]?(.*) HTTP/1"; // 定义正则表达式

            regex r(pattern);          // 字符串转为正则表达式对象
            smatch mas;                // 存储正则匹配的结果
            regex_search(src, mas, r); // 在参1中检索，符合正则的存入mas集中
            if (mas.size() == 0)
            {
                printf("%s failed!\n", pattern.c_str());
                Close();
                return;
            }
            // 匹配成功  分别取出http请求所带的信息
            string type = mas[1]; // 请求类型
            string path = "/";
            path += mas[2];           // 文件路径
            string filetype = mas[3]; // 文件类型
            string query = mas[4];    // 文件请求后缀 id=1
            if (filetype.size() > 0)
                filetype = filetype.substr(1, filetype.size() - 1);  // 截取文件类型前面的'.'
            printf("type:[%s]\npath:[%s]\nfiletype[%s]\nquery[%s]\n",
                   type.c_str(), path.c_str(),
                   filetype.c_str(), query.c_str());
            if (type != "GET") // 目前只处理GET请求
            {
                printf("Not GET!!!\n");
                Close();
                return;
            }
            string filename = path; // 存储请求文件路径
            if (path == "/")        // 未请求文件，则给默认值
            {
                filename = "/index.html";
            }
            string filepath = "www" + filename; // 本地文件路径

            // 处理php脚本
            // php-cgi www/index.php id=1 name=dxc > www/index.php.html
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
            }

            FILE *fp = fopen(filepath.c_str(), "rb");
            if (fp == NULL) // 未找到，应返回404，现不完成
            {
                printf("open file %s \n failed!\n", filepath.c_str());
                Close();
                return;
            }
            // 获取文件大小
            fseek(fp, 0, SEEK_END);
            long filesize = ftell(fp); // 可能会溢出，超出int存储
            fseek(fp, 0, 0);
            printf("file size is %ld\n", filesize);

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
                        fseek(fp, 3, SEEK_CUR);  // 跳过可能的 "\r\n\n"
                        headsize += 3;
                        break;
                    }
                }
                filesize -= headsize;  // 减去头的大小，只发送响应体
            }

            // 响应http  GET请求
            string msg = "";
            // 组装http消息头
            msg = "HTTP/1.1 200 OK\r\n";
            msg += "Servevr: HttpServer\r\n";
            msg += "Content-Type: text/html\r\n";
            msg += "Content-Length: ";
            // msg += "10\r\n";
            msg += to_string(filesize) + "\r\n";
            msg += "\r\n";
            // 发送消息头
            client.send(msg.c_str(), msg.size());
            printf("========> send <========\n%s================\n", msg.c_str());
            // 发送正文
            while (true)
            {
                int len = fread(buf, 1, sizeof(buf), fp);
                if (len <= 0)
                    break;
                int re = client.send(buf, len);
                if (re <= 0) // 对方已关闭
                    break;
            }
        }
        Close();
    }
    void Close()
    {
        client.close();
        delete this;
    }
    Tcp client;
};

int main(int argc, char *argv[])
{
    unsigned short port = 8080;
    if (argc > 1)
        port = atoi(argv[1]);

    Tcp server;
    server.createSocket();
    server.bind(port);
    while (true)
    {
        Tcp client = server.accept();

        TcpThread *th = new TcpThread();
        th->client = client;
        thread sth(&TcpThread::Main, th);
        sth.detach();
    }
    server.close();

    getchar();
    return 0;
}
