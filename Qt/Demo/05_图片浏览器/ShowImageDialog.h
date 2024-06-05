#ifndef SHOWIMAGEDIALOG_H
#define SHOWIMAGEDIALOG_H

#include <QDialog>
#include <QImage>   // 图片类
#include <QPainter> // 画家类

QT_BEGIN_NAMESPACE
namespace Ui {
class ShowImageDialog;
}
QT_END_NAMESPACE

class ShowImageDialog : public QDialog
{
    Q_OBJECT

public:
    ShowImageDialog(QWidget *parent = nullptr);
    ~ShowImageDialog();

protected:
    // 绘图事件处理函数
    void paintEvent(QPaintEvent *event);

private slots:
    void on_btnPrev_clicked();

    void on_btnNext_clicked();

    void on_btnClose_clicked();

private:
    Ui::ShowImageDialog *ui;
    int m_index; // 图片索引
};
#endif // SHOWIMAGEDIALOG_H
