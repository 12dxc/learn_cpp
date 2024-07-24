#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnOpenFile_clicked();

    void on_btnOpenFiles_clicked();

    void on_btnExistingDir_clicked();

    void on_btnSaveFile_clicked();

    void on_btnColor_clicked();

    void on_btnFont_clicked();

    void on_btnInputText_clicked();

    void on_btnInputInt_clicked();

    void on_btnInputFloat_clicked();

    void on_btnInputItem_clicked();

    void on_btnInformation_clicked();

    void on_btnAbout_clicked();

    void on_btnQuestion_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
