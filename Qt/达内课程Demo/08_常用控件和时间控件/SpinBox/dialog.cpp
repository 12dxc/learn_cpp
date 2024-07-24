#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

// "计算"
void Dialog::on_btnCalc_clicked()
{
    int num = ui->spinNum->value();  // 数量
    double price = ui->spinPrice->value(); // 单价
    double total = num * price;
    ui->editTotal->setText("￥ " +QString::number(total,'f',2));
}
// 十进制 --> 其它进制
void Dialog::on_btnDecToOther_clicked()
{
    int val = ui->spinDec->value();
    ui->spinBin->setValue(val);
    ui->spinHex->setValue(val);
}
// 二进制 --> 其它进制
void Dialog::on_btnBinToOther_clicked()
{
    int val = ui->spinBin->value();
    ui->spinDec->setValue(val);
    ui->spinHex->setValue(val);
}
// 十六进制 --> 其它进制
void Dialog::on_btnHexToOther_clicked()
{
    int val = ui->spinHex->value();
    ui->spinDec->setValue(val);
    ui->spinBin->setValue(val);
}
