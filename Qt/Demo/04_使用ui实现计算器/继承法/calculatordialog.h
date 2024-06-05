#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDoubleValidator> // 数字验证器
#include "ui_CalculatorDialog.h"

// 1、继承方式
class CalculatorDialog : public QDialog, Ui::CalcukatorDialog
{
    Q_OBJECT
public:
    CalculatorDialog();
public slots:
    // 计算并显示结果
    void calc();
    // 使能'='按钮
    void enableButton();
};

#endif // CALCULATORDIALOG_H
