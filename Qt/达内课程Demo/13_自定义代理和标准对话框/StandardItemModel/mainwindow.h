#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QLabel>
#include <QFile>
#include <QFileDialog>  // 文件对话框
#include <QTextStream>

#include "comboboxdelegate.h"

#define COLUMNCOUNT 5   // 文件固定为5列

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    // QItemSelectionModel::currentChanged(...)
    void on_CurrentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpen_triggered();

    void on_actAppend_triggered();

    void on_actInsert_triggered();

    void on_actDelete_triggered();

    void on_actAlignLeft_triggered();

    void on_actAlignCenter_triggered();

    void on_actAlignRight_triggered();

    void on_actFontBold_triggered(bool checked);

    void on_actSave_triggered();

    void on_actModelData_triggered();

private:
    void initUi();  // 初始化状态栏
    void initModelFromStringList(QStringList&); // 从QStringList--Model
private:
    Ui::MainWindow *ui;

    QStandardItemModel* model;       // 数据模型
    QItemSelectionModel* selection;  // 选择模型
    QLabel* labelCurFile;      // 状态栏显示  当前文件
    QLabel* labelCellPos;      //            当前单元格
    QLabel* labelCellText;     //            当前单元格文本

    ComboBoxDelegate cmbDelegate;  // 代理类对象(性别列)
};
#endif // MAINWINDOW_H
