#include "ShowImageDialog.h"
#include "ui_ShowImageDialog.h"

ShowImageDialog::ShowImageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowImageDialog)
{
    ui->setupUi(this);

    m_index = 0;

    // ui->btnPrev->setEnabled(false);
}

ShowImageDialog::~ShowImageDialog()
{
    delete ui;
}

// 绘图事件处理函数
void ShowImageDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    // 1) 创建画家类对象
    QPainter painter(this);
    // 2) 获取绘图区域
    QRect rect = ui->frame->frameRect();
    // 坐标系平移
    rect.translate(ui->frame->pos());
    // 3) 构建一张要绘制的图片
    QImage image(":/images/" + QString::number(m_index) + ".jpg");
    // 4) 使用painter绘制图片
    painter.drawImage(rect, image);
}

// 上一页
void ShowImageDialog::on_btnPrev_clicked()
{
    // 到边界循环
    if (--m_index < 0)
        m_index = 7;

    // 到边界禁用
    // if (m_index == 1)
    //     ui->btnPrev->setEnabled(false);
    // else if (m_index == 7)
    //     ui->btnNext->setEnabled(true);
    // --m_index;

    this->update(); // 触发绘图事件的产生 --> 调用绘图事件处理函数
}

// 下一页
void ShowImageDialog::on_btnNext_clicked()
{
    // 到边界循环
    if (++m_index > 7)
        m_index = 0;

    // 到边界禁用
    // if (m_index == 6)
    //     ui->btnNext->setEnabled(false);
    // else if (m_index == 0)
    //     ui->btnPrev->setEnabled(true);
    // ++m_index;
    this->update();
}

// 关闭按钮
void ShowImageDialog::on_btnClose_clicked()
{
    this->close();
}
