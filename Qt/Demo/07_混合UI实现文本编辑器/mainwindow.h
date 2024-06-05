#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFontComboBox> // 字体组合框
#include <QLabel>
#include <QMainWindow>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_actFontItalci_triggered(bool checked);

    void on_actFontUnderline_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    // 自定义槽函数
    // 改变字体大小
    void on_spinBox_valueChanged(int fontSize);
    // 选择字体
    void on_cmbFont_currentIndexChanged(QString const &font);

    void on_actToolbarLab_triggered(bool checked);

private:
    // 代码方式初始化界面
    void initUi();

private:
    Ui::MainWindow *ui;

    QLabel *labelCurFile;   // 在状态栏显示当前文件的label
    QSpinBox *spinBox;      // 在工具栏 设置字体大小
    QFontComboBox *cmbFont; // 在工具栏 选择字体
};
#endif // MAINWINDOW_H
