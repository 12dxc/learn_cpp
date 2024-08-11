#include "locatedialog.h"
#include "ui_locatedialog.h"
#include <QMessageBox>

LocateDialog::LocateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LocateDialog)
{
    ui->setupUi(this);
}

LocateDialog::~LocateDialog()
{
    QMessageBox::information(this,"定位单元格","定位单元格对话框窗口被销毁");
    delete ui;
}
// 窗口的关闭事件处理函数: 当对话框窗口关闭时，发射信号 使能actLocate
void LocateDialog::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    emit changeActionEnable(true);
}
// 窗口的显示事件处理函数: 当对话框窗口显示时，发射信号 禁用actLocate
void LocateDialog::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    emit changeActionEnable(false);
}
// 设置对话框窗口spinBox的最大值
void LocateDialog::setSpinMax(int rowCnt,int columnCnt)
{
    ui->spinRow->setRange(0,rowCnt-1);
    ui->spinColumn->setRange(0,columnCnt-1);
}
// 根据主窗口中选中的单元格设置spinBox的当前值
void LocateDialog::setSpinValue(int rowNo,int colNo)
{
    ui->spinRow->setValue(rowNo);
    ui->spinColumn->setValue(colNo);
}
// "设定文字"
void LocateDialog::on_btnSetText_clicked()
{
    int rowNo = ui->spinRow->value();
    int colNo = ui->spinColumn->value();
    QString text = ui->editCellText->text();
    emit changeCellText(rowNo,colNo,text);
}
