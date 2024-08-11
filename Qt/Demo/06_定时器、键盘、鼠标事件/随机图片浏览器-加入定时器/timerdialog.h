#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QDir>
#include <QImage>
#include <QPainter>
#include <QTime>
#include <QVector> // 向量

QT_BEGIN_NAMESPACE
namespace Ui {
class TimerDialog;
}
QT_END_NAMESPACE

class TimerDialog : public QDialog
{
    Q_OBJECT

public:
    TimerDialog(QWidget *parent = nullptr);
    ~TimerDialog();
private slots:
    void on_btnTimer_clicked();

private:
    // 将图片加载到容器中
    void loadImages(QString const &path);
    // 绘图事件处理函数
    void paintEvent(QPaintEvent *);
    // 定时器事件处理函数
    void timerEvent(QTimerEvent *event);

private:
    Ui::TimerDialog *ui;

    QVector<QImage> m_images; // 保存图片的容器
    int m_index;              // 图片在向量中的索引
    int m_timerID;            // 定时器ID
    bool isStarted;           // true -- 切换图片  false -- 停止
};
#endif // TIMERDIALOG_H
