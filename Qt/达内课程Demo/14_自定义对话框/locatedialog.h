#ifndef LOCATEDIALOG_H
#define LOCATEDIALOG_H

#include <QDialog>

namespace Ui {
class LocateDialog;
}

class LocateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LocateDialog(QWidget *parent = nullptr);
    ~LocateDialog();
    // 设置对话框窗口spinBox的最大值
    void setSpinMax(int rowCnt,int columnCnt);
public slots:
    // 根据主窗口中选中的单元格设置spinBox的当前值
    void setSpinValue(int rowNo,int colNo);
signals:
    // 点击"设定文字"按钮时发射
    void changeCellText(int row,int column,QString& text);
    // 对话框窗口显示或关闭时发射
    void changeActionEnable(bool en);
private slots:
    void on_btnSetText_clicked();

private:
    // 窗口的关闭事件处理函数
    void closeEvent(QCloseEvent *event);
    // 窗口的显示事件处理函数
    void showEvent(QShowEvent *event);
private:
    Ui::LocateDialog *ui;
};

#endif // LOCATEDIALOG_H
