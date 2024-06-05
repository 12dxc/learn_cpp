#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QDoubleValidator> // 数字验证器
#include <QHBoxLayout>      // 水平布局器
#include <QLabel>
#include <QLineEdit> //单行编辑器
#include <QPushButton>
#include <QTextStream>

class CalculatorDialog : public QDialog
{
    Q_OBJECT
public:
    CalculatorDialog();
public slots:
    // 计算并显示结果
    void calc();
    // 使能'='按钮
    void enableButton();

private:
    QLineEdit *m_editA;    // 左操作数
    QLineEdit *m_editB;    // 右操作数
    QLineEdit *m_editC;    // 结果
    QLabel *m_label;       // "+"
    QPushButton *m_button; // "="
};

#endif // CALCULATORDIALOG_H
