#include "calculatordialog.h"

CalculatorDialog::CalculatorDialog()
    : ui(new Ui::CalcukatorDialog)
{
    ui->setupUi(this);

    ui->m_editA->setValidator(new QDoubleValidator(this)); // 设置数字验证器：只能输入数字
    ui->m_editB->setValidator(new QDoubleValidator(this));

    // 信号和槽的链接
    connect(ui->m_editA, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));
    connect(ui->m_editB, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));

    connect(ui->m_button, SIGNAL(clicked()), this, SLOT(calc()));
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

// 计算并显示结果
void CalculatorDialog::enableButton()
{
    bool bAOk, bBOk;
    ui->m_editA->text().toDouble(&bAOk);
    ui->m_editB->text().toDouble(&bBOk);

    //当左右操作数都正确输入，按钮可用
    ui->m_button->setEnabled(bAOk && bBOk);
}

// 使能'='按钮
void CalculatorDialog::calc()
{
    double_t res = ui->m_editA->text().toDouble() + ui->m_editB->text().toDouble();
    QString str = QString::number(res, 'g'); //QString 转数字
    ui->m_editC->setText(str);               //将结果显示在文本框
}
