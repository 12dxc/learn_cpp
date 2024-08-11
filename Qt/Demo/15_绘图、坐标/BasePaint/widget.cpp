#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("QPainter基本绘图");
    setPalette(QPalette(Qt::white));  // 设置窗口为白色背景
    setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}
// 绘图事件处理函数
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    // 创建QPainter对象
    QPainter painter(this);
    // 获取绘图区域
    int w = this->width();  // 窗口宽
    int h = this->height(); // 窗口高
    QRect rect(w/4,h/4,w/2,h/2);  // 窗口中间区域
    // 设置画笔
    QPen pen;
    pen.setWidth(3);                 // 线宽
    pen.setColor(Qt::cyan);          // 线的颜色
    pen.setStyle(Qt::SolidLine);     // 线型
    pen.setCapStyle(Qt::RoundCap);   // 线的端点样式
    pen.setJoinStyle(Qt::BevelJoin); // 线的连接点样式
    painter.setPen(pen);
    // 设置画刷
    QBrush brush;
//  brush.setColor(Qt::yellow);        // 画刷的颜色
//  brush.setStyle(Qt::SolidPattern);  // 填充样式

    QPixmap texturePixmap(":/1.png");
    brush.setStyle(Qt::TexturePattern);
    brush.setTexture(texturePixmap);

    painter.setBrush(brush);
    // 绘图
//  painter.drawRect(rect);         // 绘制矩形
//  painter.drawEllipse(rect);      // 绘制椭圆
//  painter.drawEllipse(QPoint(w/2,h/2),w/4,h/4);
//  painter.drawArc(rect,30*16,120*16);  // 绘制弧线
//  painter.drawChord(rect,30*16,120*16); // 绘制弦
//  painter.drawPie(rect,30*16,120*16);   // 绘制扇形
    QPoint points[6] = {
        QPoint(w/4,h/2),QPoint(3*w/8,h/4),QPoint(5*w/8,h/4),
        QPoint(3*w/4,h/2),QPoint(5*w/8,3*h/4),QPoint(3*w/8,3*h/4)
    };
//  painter.drawPolygon(points,6);    // 绘制多边形
    painter.drawPolyline(points,6);   // 绘制折线
}









