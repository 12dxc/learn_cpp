#include "timedialog.h"

TimeDialog::TimeDialog()
{
    this->setWindowTitle("获取系统时间");

    m_label = new QLabel(this);
    m_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);     // 设置边框样式
    m_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 设置水平垂直居中
    // 设置字体
    QFont font;
    font.setPointSize(20);
    m_label->setFont(font);

    m_button = new QPushButton("获取系统时间", this);
    m_button->setFont(font);

    // 布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_button);
    this->setLayout(layout);

    connect(m_button, SIGNAL(clicked()), this, SLOT(getTime()));
}

// 获取系统当前时间的槽函数
void TimeDialog::getTime()
{
    QTime time = QTime::currentTime(); // 获取当前时间
    QString str = time.toString("hh:mm:ss");
    m_label->setText(str);
}
