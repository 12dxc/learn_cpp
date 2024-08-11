#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTime>
#include <QVBoxLayout>

class TimeDialog : public QDialog
{
    Q_OBJECT
public:
    TimeDialog();
public slots:
    // 获取系统当前时间的槽函数
    void getTime();

private:
    QLabel *m_label;       // 显示时间标签
    QPushButton *m_button; // 获取时间按钮
};

#endif // TIMEDIALOG_H
