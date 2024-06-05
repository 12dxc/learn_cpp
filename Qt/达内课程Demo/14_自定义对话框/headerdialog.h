#ifndef HEADERDIALOG_H
#define HEADERDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class HeaderDialog;
}

class HeaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeaderDialog(QWidget *parent = nullptr);
    ~HeaderDialog();

    // 初始化对话框窗口的listView
    void setHeaderList(QStringList& headers);
    // 返回字符串列表
    QStringList headerList();
private:
    Ui::HeaderDialog *ui;

    QStringListModel* headerModel;
};

#endif // HEADERDIALOG_H
