#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint); // 不可调整窗口大小

    m_timerID = startTimer(1000);
}

Dialog::~Dialog()
{
    delete ui;
    // 停止定时器
    killTimer(m_timerID);
}

// 定时器事件处理函数
void Dialog::timerEvent(QTimerEvent *)
{
    QTime curTime = QTime::currentTime();
    ui->lcdHour->display(QString::number(curTime.hour()));
    ui->lcdMinute->display(QString::number(curTime.minute()));
    ui->lcdSecond->display(QString::number(curTime.second()));
}
