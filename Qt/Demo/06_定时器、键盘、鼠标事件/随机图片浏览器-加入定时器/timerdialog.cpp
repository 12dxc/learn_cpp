#include "timerdialog.h"
#include "ui_timerdialog.h"
#include <stdlib.h>

TimerDialog::TimerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimerDialog)
{
    ui->setupUi(this);
    m_index = 0;
    isStarted = false;
    // 设置随机种子
    srand(QTime::currentTime().msec());
    loadImages("../Timer/images");
    qDebug() << "加载图片数量: " << m_images.size();
}

TimerDialog::~TimerDialog()
{
    delete ui;
}

// 从指定路径加载图片，保存到向量容器中
void TimerDialog::loadImages(const QString &path)
{
    QDir dir(path);
    // 遍历目录下的所有图片
    QStringList list1;

    // 遍历当前所有文件并分出图片文件
    QFileInfoList fIList = dir.entryInfoList(QDir::Files);
    for (int i = 0; i < fIList.size(); i++)
        if (fIList[i].suffix() == "jpg" || fIList[i].suffix() == "png"
            || fIList[i].suffix() == "jpeg")
            list1.append(fIList[i].fileName());

    // 构造qImage类代表一个图片文件加入容器中
    for (int i = 0; i < list1.size(); i++) {
        QImage image(path + "/" + list1.at(i));
        m_images.push_back(image);
    }

    // 递归遍历子目录中的图片
    QStringList list2 = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i < list2.size(); i++)
        loadImages(path + "/" + list2.at(i));
}

// 绘图事件处理函数
void TimerDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect = ui->frame->rect();
    rect.translate(ui->frame->pos());

    painter.drawImage(rect, m_images[m_index]);
}

// 定时器事件处理函数
void TimerDialog::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    m_index = rand() % m_images.size();
    this->update();
}

// 定时器的启动和停止
void TimerDialog::on_btnTimer_clicked()
{
    if (!isStarted) {
        isStarted = true;
        m_timerID = startTimer(500);
        ui->btnTimer->setText("停止");
    } else {
        isStarted = false;
        killTimer(m_timerID);
        ui->btnTimer->setText("开始");
    }
}
