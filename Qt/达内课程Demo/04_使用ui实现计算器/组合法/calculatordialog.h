#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDoubleValidator> // 数字验证器
#include "ui_CalculatorDialog.h"

// 2、组合方式
class CalculatorDialog : public QDialog
{
    Q_OBJECT
public:
    CalculatorDialog();
    ~CalculatorDialog();
public slots:
    // 计算并显示结果
    void calc();
    // 使能'='按钮
    void enableButton();

private:
    Ui::CalcukatorDialog *ui; // 将来通过ui访问界面类的成员
};

#endif // CALCULATORDIALOG_H
