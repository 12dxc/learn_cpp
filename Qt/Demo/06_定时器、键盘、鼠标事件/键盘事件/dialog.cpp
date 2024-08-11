#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

// 键盘按键的按下事件处理函数
void Dialog::keyPressEvent(QKeyEvent *event)
{
    // label当前坐标
    int x = ui->label->pos().x();
    int y = ui->label->pos().y();

    switch(event->key()){
    case Qt::Key_Left:
        x-=5;
        break;
    case Qt::Key_Up:
        y-=5;
        break;
    case Qt::Key_Right:
        x+=5;
        break;
    case Qt::Key_Down:
        y+=5;
        break;
    }

    QSize s1 = this->size();  // 获取窗口的大小
    QSize s2 = ui->label->size();  // 获取label的大小

    // 0<=x <= 窗口宽-label宽
    if(x < 0)
        x = 0;
    else if(x > s1.width() - s2.width())
        x = s1.width() - s2.width();

    // 0<=y <= 窗口高-label高
    if(y < 0)
        y = 0;
    else if(y > s1.height() - s2.height())
        y = s1.height() - s2.height();

    ui->label->move(x,y);
}
