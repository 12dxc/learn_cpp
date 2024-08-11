#ifndef WIDGET_H
#define WIDGET_H

#include <QStringListModel>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnItemAppend_clicked();

    void on_btnItemInsert_clicked();

    void on_btnItemDelete_clicked();

    void on_btnListClear_clicked();

    void on_btnListInit_clicked();

    void on_btnTextClear_clicked();

    void on_btnModelData_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QStringListModel *model;
};
#endif // WIDGET_H
