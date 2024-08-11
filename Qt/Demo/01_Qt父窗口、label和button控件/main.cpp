#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

int main(int argc, char **argv)
{
    // 创建Qt应用程序对象
    QApplication app(argc, argv);

    // 创建父窗口并设置位置和大小，这三个类都可做父窗口
    // QWidget parent;
    QMainWindow parent;
    // QDialog parent;

    parent.move(500, 400);
    parent.resize(300, 150);

    // 创建标签控件
    QLabel label("我是一个子窗口 :)", &parent);
    label.move(70, 30);
    label.resize(160, 30);
    // label.show();  // 显示标签

    // 创建按钮控件
    QPushButton btn("退出", &parent);
    btn.move(90, 90);
    btn.resize(120, 30);
    // btn.show();

    // 显示父窗口，其子控件也会显示
    parent.show();

    // 进入主事件循环并等待exit()被调用
    return app.exec();
}
