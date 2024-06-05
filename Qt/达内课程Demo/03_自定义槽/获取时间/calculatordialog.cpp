#include "calculatordialog.h"

CalculatorDialog::CalculatorDialog()
{
    // 窗口初始化
    this->setWindowTitle("计算器");

    // 左操作数
    m_editA = new QLineEdit(this);
    m_editA->setAlignment(Qt::AlignRight);             // 设置文本右对齐
    m_editA->setValidator(new QDoubleValidator(this)); // 设置数字验证器：只能输入数字

    // 右操作数
    m_editB = new QLineEdit(this);
    m_editB->setAlignment(Qt::AlignRight);             // 设置文本右对齐
    m_editB->setValidator(new QDoubleValidator(this)); // 设置数字验证器：只能输入数字

    // 结果
    m_editC = new QLineEdit(this);
    m_editC->setAlignment(Qt::AlignRight); // 设置文本右对齐
    m_editC->setReadOnly(true);            // 设置为只读

    // "+"
    m_label = new QLabel("+", this);

    // "="
    m_button = new QPushButton("=", this);
    m_button->setEnabled(false); // 设置为禁用

    // 创建布局器
    QHBoxLayout *layout = new QHBoxLayout(this);
    // 按水平方向，依次把控件添加到布局器中
    layout->addWidget(m_editA);
    layout->addWidget(m_label);
    layout->addWidget(m_editB);
    layout->addWidget(m_button);
    layout->addWidget(m_editC);
    // 设置窗口的布局器
    this->setLayout(layout);

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
