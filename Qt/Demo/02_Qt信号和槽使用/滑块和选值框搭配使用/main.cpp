#include <QApplication>
#include <QDialog>
#include <QSlider>  // 滑块
#include <QSpinBox> // 选值框

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // 创建父窗口，并设置位置和大小
    QDialog parent;
    parent.move(500, 400);
    parent.resize(400, 100);

    // 滑块
    QSlider slider(Qt::Horizontal, &parent);
    slider.move(50, 35);
    slider.resize(180, 30);
    slider.setRange(0, 200); // 设置滑块控件的取值范围

    // 选值框
    QSpinBox spinBox(&parent);
    spinBox.move(270, 35);
    spinBox.resize(80, 30);
    spinBox.setRange(0, 200); // 设置选值框控件的取值范围

    // 显示父窗口
    parent.show();

    // 信号和槽函数的连接   valueChanged，值发生更改  setValue，设置值
    QObject::connect(&slider, SIGNAL(valueChanged(int)), &spinBox, SLOT(setValue(int)));
    QObject::connect(&spinBox, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));

    // 进入主事件循环
    return app.exec();
}
