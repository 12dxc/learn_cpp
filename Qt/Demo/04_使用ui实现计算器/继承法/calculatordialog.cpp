#include "calculatordialog.h"

CalculatorDialog::CalculatorDialog()
{
    // 界面初始化
    this->setupUi(this);

    m_editA->setValidator(new QDoubleValidator(this)); // 设置数字验证器：只能输入数字
    m_editB->setValidator(new QDoubleValidator(this));

    // 信号和槽的链接
    connect(m_editA, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));
    connect(m_editB, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));

    connect(m_button, SIGNAL(clicked()), this, SLOT(calc()));
}

// 计算并显示结果
void CalculatorDialog::enableButton()
{
    bool bAOk, bBOk;
    m_editA->text().toDouble(&bAOk);
    m_editB->text().toDouble(&bBOk);

    //当左右操作数都正确输入，按钮可用
    m_button->setEnabled(bAOk && bBOk);
}

// 使能'='按钮
void CalculatorDialog::calc()
{
    double_t res = m_editA->text().toDouble() + m_editB->text().toDouble();
    QString str = QString::number(res, 'g'); //QString 转数字
    m_editC->setText(str);                   //将结果显示在文本框
}
