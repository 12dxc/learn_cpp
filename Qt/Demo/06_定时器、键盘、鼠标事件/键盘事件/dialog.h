#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QKeyEvent>

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
    // 键盘按键的按下事件处理函数
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
