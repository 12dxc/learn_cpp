#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->dateEdit->setDate(QDate::currentDate());
}

Widget::~Widget()
{
    delete ui;
}

// "读取当前日期时间"
void Widget::on_btnGetDatetime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime(); // 获取当前日期时间

    ui->timeEdit->setTime(curDateTime.time()); // 设置时间控件的值
    ui->dateEdit->setDate(curDateTime.date()); // 设置日期控件的值
    ui->dateTimeEdit->setDateTime(curDateTime);// 设置日期时间控件的值

    ui->lineEditTime->setText(curDateTime.time().toString("hh:mm:ss"));
    ui->lineEditDate->setText(curDateTime.date().toString("yyyy年MM月dd日"));
    ui->lineEditDatetime->setText(curDateTime.toString("yyyy/MM/dd hh:mm:ss"));

}
// "设置时间"
void Widget::on_btnSetTime_clicked()
{
    QString str = ui->lineEditTime->text();
    str = str.trimmed(); // "  16:23:30  " ==> "16:23:30"
    if(!str.isEmpty()){
        QTime time = QTime::fromString(str,"hh:mm:ss");
        if(time.isValid())
            ui->timeEdit->setTime(time);
        else
           QMessageBox::warning(this,"设置时间","格式: hh:mm:ss");
    }
}
// "设置日期"
void Widget::on_btnSetDate_clicked()
{
    QString str = ui->lineEditDate->text().trimmed();
    if(!str.isEmpty()){
        QDate date = QDate::fromString(str,"yyyy-M-d");
        if(date.isValid())
            ui->dateEdit->setDate(date);
        else
            QMessageBox::warning(this,"设置日期","格式: yyyy-M-d");
    }
}
// "设置日期时间"
void Widget::on_btnSetDatetime_clicked()
{
    QString str = ui->lineEditDatetime->text().trimmed();
    if(!str.isEmpty()){
        QDateTime dateTime = QDateTime::fromString(str,"yyyy-M-d h:m:s");
        if(dateTime.isValid())
            ui->dateTimeEdit->setDateTime(dateTime);
        else
            QMessageBox::warning(this,"设置日期时间","格式: yyyy-M-d h:m:s");
    }
}
// 选择一个日期
void Widget::on_calendarWidget_selectionChanged()
{
    QDate curDate = ui->calendarWidget->selectedDate();
    QString str = curDate.toString("yyyy 年 MM 月 dd 日");
    ui->lineEditSelectedDate->setText(str);
}
