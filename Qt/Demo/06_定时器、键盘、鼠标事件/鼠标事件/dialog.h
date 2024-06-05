#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    // 鼠标移动事件处理函数
    void mouseMoveEvent(QMouseEvent *event);
    // 鼠标按键按下事件处理函数
    void mousePressEvent(QMouseEvent *event);
    // 鼠标按键松开事件处理函数
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Dialog *ui;

    bool m_drag;
    QPoint m_pos;
};
#endif // DIALOG_H
