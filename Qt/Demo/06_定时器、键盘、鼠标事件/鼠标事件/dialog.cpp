#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_drag = false;
}

Dialog::~Dialog()
{
    delete ui;
}

// 鼠标移动事件处理函数
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(m_drag){
        // 计算label要移动到的位置
        QPoint newPos = event->pos() + m_pos;

        QSize s1 = this->size();  // 获取窗口的大小
        QSize s2 = ui->label->size();  // 获取label的大小

        // 0<=x <= 窗口宽-label宽
        if(newPos.x() < 0)
            newPos.setX(0);
        else if(newPos.x() > s1.width() - s2.width())
            newPos.setX(s1.width() - s2.width());

        // 0<=y <= 窗口高-label高
        if(newPos.y() < 0)
            newPos.setY(0);
        else if(newPos.y() > s1.height() - s2.height())
            newPos.setY(s1.height() - s2.height());

        // 移动
        ui->label->move(newPos);
    }
}
// 鼠标按键按下事件处理函数
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){ // 按下的是鼠标左键
        // 获取label所在的矩形区域
        QRect rect = ui->label->frameRect();
        // 坐标平移
        rect.translate(ui->label->pos());
        // 判断鼠标光标是否在rect内
        if(rect.contains(event->pos())){
            m_drag = true;
            m_pos =ui->label->pos() - event->pos();
        }
    }
}
// 鼠标按键松开事件处理函数
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_drag = false;
    }
}
