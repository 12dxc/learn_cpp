#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

int main(int argc, char **argv)
{
    // 创建应用程序对象
    QApplication app(argc, argv);

    // 创建父窗口
    QDialog parent;
    parent.move(500, 400);
    parent.resize(300, 150);

    QLabel label("点击按钮关闭标签", &parent);
    label.setText("标签1"); // 调用槽函数
    label.move(60, 30);

    QLabel label2("标签2", &parent);
    label2.move(180, 30);

    QPushButton button("关闭", &parent);
    button.move(40, 90);
    button.resize(90, 30);

    QPushButton button2("退出", &parent);
    button2.move(170, 90);
    button2.resize(90, 30);

    parent.show();

    // 信号和槽函数的连接
    // 信号和槽函数的参数不匹配：错误
    //  QObject::connect(&button,SIGNAL(clicked()),&label, SLOT(setText(QString)));
    //  // 信号和槽函数的参数一致：正确
    QObject::connect(&button, SIGNAL(clicked()), &label, SLOT(close()));
    // 信号的参数多于槽函数的参数：正确
    //  QObject::connect(&button,SIGNAL(clicked(bool)),&label, SLOT(close()));

    //  QObject::connect(&button2,SIGNAL(clicked()),&label2,SLOT(close()));

    // 信号的级联
    //  QObject::connect(&button,SIGNAL(clicked()),&button2,SIGNAL(clicked()));
    //  QObject::connect(&button2,SIGNAL(clicked()),&label, SLOT(close()));

    // 思考：如果通过点击 第二个按钮，实现关闭所有窗口(退出应用用程序)？
    //  QObject::connect(&button2,SIGNAL(clicked()),&app,SLOT(closeAllWindows()));
    QObject::connect(&button2, SIGNAL(clicked()), &parent, SLOT(close()));

    // 进入主事件循环
    return app.exec();
}
