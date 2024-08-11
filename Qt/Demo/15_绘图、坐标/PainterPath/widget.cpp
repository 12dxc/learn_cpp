#include "widget.h"
#include "ui_widget.h"
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QPainter坐标变换");
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);

    resize(600,300);   // 设置窗口大小
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint); // 设置窗口大小固定
}

Widget::~Widget()
{
    delete ui;
}
// 绘图事件处理函数
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    // 创建画家类对象
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing); // 抗锯齿
    // 生成五角星的5个顶点的坐标（假设原点在五角星中心）
    qreal r = 100;  // 半径
    const qreal Pi = 3.14159;  // π
    qreal deg = Pi*72/180;     // 72°对应的弧度
    QPointF points[5] = {
        QPointF(r,0),
        QPoint(r*cos(deg),-r*sin(deg)),
        QPoint(r*cos(2*deg),-r*sin(2*deg)),
        QPoint(r*cos(3*deg),-r*sin(3*deg)),
        QPoint(r*cos(4*deg),-r*sin(4*deg))
    };
    // 设置画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(170,20,20));
    pen.setStyle(Qt::SolidLine);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    // 设置字体
    QFont font;
    font.setPointSize(12);
    font.setBold(false);
    font.setFamily("隶书");
    painter.setFont(font);

    // 设计绘制五角星的QPainterPath,以便重复使用
    QPainterPath starPath;
    starPath.moveTo(points[0]); // 设置第一个点为当前点
    starPath.lineTo(points[2]); // 从当前点到参数指定的点(points[2])绘制一条直线，同时把参数设置为新的当前点
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath(); // 闭合路径
    // 显示顶点编号
    for(int i=0;i<5;i++)
        starPath.addText(points[i],font,QString::number(i));

    // 绘图
    painter.save();               // 保存坐标状态
    painter.translate(100,150);   // 平移
    painter.drawPath(starPath);   // 绘制五角星
    painter.drawText(0,0,"S1");
    painter.restore();            // 恢复坐标状态

    painter.translate(290,150);   // 平移
    painter.scale(0.8,0.8);       // 缩放(缩小)
    painter.rotate(90);           // 旋转(顺时针旋转90°)
    painter.drawPath(starPath);
    painter.drawText(0,0,"S2");

    painter.resetTransform();     // 复位所有坐标变换
    painter.translate(480,150);
    painter.rotate(-135);
    painter.drawPath(starPath);
    painter.drawText(0,0,"S3");
}












