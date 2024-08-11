#include "widget.h"
#include "ui_widget.h"
#include <QMap>
#include <QTextDocument>
#include <QTextBlock>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
// "初始化列表"
void Widget::on_btnListInit_clicked()
{
    QIcon icon(":/icons/unit.ico"); // 图标
    ui->cmbSimple->clear();
    for(int i=0;i<15;i++){
        ui->cmbSimple->addItem(icon,QString::asprintf("Item %d",i));  // 有图标
//      ui->cmbSimple->addItem(QString::asprintf("Item %d",i));  // 没有图标
    }
/*
    QStringList lst;
    lst << "北京市" <<"上海市" << "天津市" << "重庆市" << "河北省" << "江苏省""" << "辽宁省";
    ui->cmbSimple->addItems(lst);
*/
}
// "初始化城市 + 区号"
void Widget::on_btnCityZone_clicked()
{
    QMap<QString,int> cityZone;
    cityZone.insert("北京",10);
    cityZone.insert("广州",20);
    cityZone.insert("上海",21);
    cityZone.insert("天津",22);
    cityZone.insert("重庆",23);
    cityZone.insert("沈阳",24);
    cityZone.insert("南京",25);
    cityZone.insert("武汉",27);
    cityZone.insert("成都",28);
    cityZone.insert("西安",29);
    ui->cmbCityZone->clear();
    foreach(const QString& str, cityZone.keys())
        ui->cmbCityZone->addItem(str,cityZone.value(str));
}
// 简单组合框选项变化时
void Widget::on_cmbSimple_currentIndexChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}
// 城市+区号 组合框选项变化时
void Widget::on_cmbCityZone_currentIndexChanged(const QString &arg1)
{
     QString zone = ui->cmbCityZone->currentData().toString();  // 当前项关联的用户数据
     ui->plainTextEdit->appendPlainText(arg1 + ": " + zone);
}
// "可编辑"
void Widget::on_ckbEditable_clicked(bool checked)
{
    ui->cmbSimple->setEditable(checked);
}
// "清除列表"
void Widget::on_btnListClear_clicked()
{
    ui->cmbSimple->clear();
}
// "文本框内容添加到ComboBox"
void Widget::on_btnTextToCmb_clicked()
{
    QTextDocument* doc = ui->plainTextEdit->document();  // 文档对象
    int blockCnt = doc->blockCount();   // 回车符就是一个block
    QIcon icon(":/icons/aim.ico");
    ui->cmbSimple->clear();
    for(int i=0;i<blockCnt;i++){
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->cmbSimple->addItem(icon,str);
    }
}
// "清空文本"
void Widget::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}
// "Read Only"
void Widget::on_ckbReadOnly_clicked(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}
// 右键菜单
void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos)
    // 创建菜单
    QMenu* menu = new QMenu;
    // 添加菜单项
    menu->addAction(ui->actUndo);
    menu->addAction(ui->actRedo);
    menu->addSeparator();  // 分隔线
    menu->addAction(ui->actCut);
    menu->addAction(ui->actCopy);
    menu->addAction(ui->actPaste);
    menu->addSeparator();
    menu->addAction(ui->actSelectAll);
    // 显示菜单
    menu->exec(QCursor::pos());
}




















