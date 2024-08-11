#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    void timerEvent(QTimerEvent *);

private:
    Ui::Dialog *ui;
    int m_timerID;
};
#endif // DIALOG_H
