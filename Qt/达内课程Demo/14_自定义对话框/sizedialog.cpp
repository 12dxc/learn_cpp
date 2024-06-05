#include "sizedialog.h"
#include "ui_sizedialog.h"
#include <QMessageBox>

SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog)
{
    ui->setupUi(this);
}

SizeDialog::~SizeDialog()
{
    QMessageBox::information(this,"设置行数列数","设置行数列数对话框被销毁");
    delete ui;
}
// 初始化对话框窗口的两个spinBox
void SizeDialog::setRowColumn(int row,int col)
{
    ui->spinRow->setValue(row);
    ui->spinColumn->setValue(col);
}
// 返回对话框输入的行数
int SizeDialog::rowCnt()
{
    return ui->spinRow->value();
}
// 返回对话框输入的列数
int SizeDialog::columnCnt()
{
    return ui->spinColumn->value();
}
