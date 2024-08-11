#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SizeDialog;
}

class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = nullptr);
    ~SizeDialog();
    // 初始化对话框窗口的两个spinBox
    void setRowColumn(int row,int col);
    // 返回对话框输入的行数
    int rowCnt();
    // 返回对话框输入的列数
    int columnCnt();
private:
    Ui::SizeDialog *ui;
};

#endif // SIZEDIALOG_H
