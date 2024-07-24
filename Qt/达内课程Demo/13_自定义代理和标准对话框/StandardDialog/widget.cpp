#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>   // 文件对话框
#include <QColorDialog>  // 颜色对话框
#include <QFontDialog>   // 字体对话框
#include <QInputDialog>  // 输入对话框
#include <QMessageBox>   // 消息提示框

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

// "打开一个文件"
void Widget::on_btnOpenFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(this,"打开一个文件",
                  curPath,"头文件(*.h);;源文件(*.c *.cpp);;所有文件(*.*)");
    if(!fileName.isEmpty())
        ui->plainTextEdit->appendPlainText(fileName);
}
// "打开多个文件"
void Widget::on_btnOpenFiles_clicked()
{
    QString curPath = QDir::currentPath();
    QStringList fileNames = QFileDialog::getOpenFileNames(this,"打开多个文件",
                   curPath,"头文件(*.h);;源文件(*.c *.cpp);;所有文件(*.*)");
    for(int i=0;i<fileNames.count();i++)
        ui->plainTextEdit->appendPlainText(fileNames.at(i));
}
// "选择已有目录"
void Widget::on_btnExistingDir_clicked()
{
     QString curPath = QDir::currentPath();
     QString selectedDir = QFileDialog::getExistingDirectory(this,"选择已有目录",
                  curPath);
     if(!selectedDir.isEmpty())
         ui->plainTextEdit->appendPlainText(selectedDir);
}
// "保存文件"
void Widget::on_btnSaveFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getSaveFileName(this,"保存文件",curPath,
                         "头文件(*.h);;源文件(*.c *.cpp);;所有文件(*.*)" );
    if(!fileName.isEmpty())
        ui->plainTextEdit->appendPlainText(fileName);
}
// "选择颜色"
void Widget::on_btnColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor initColor = pal.color(QPalette::Text); // 获取现有的文本颜色
    QColor color = QColorDialog::getColor(initColor,this,"选择颜色");
    if(color.isValid()){
        pal.setColor(QPalette::Text,color);
        ui->plainTextEdit->setPalette(pal);
    }
}
// "选择字体"
void Widget::on_btnFont_clicked()
{
    QFont initFont = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok,initFont,this,"选择字体");
    if(ok)
        ui->plainTextEdit->setFont(font);
}
// "输入字符串"
void Widget::on_btnInputText_clicked()
{
    QString dlgTitle = "输入文字对话框";
    QString txtLabel = "请输入文件名";
    QString defaultInput = "新建文件.txt";
    QLineEdit::EchoMode  echoMode = QLineEdit::Normal;
//  QLineEdit::EchoMode  echoMode = QLineEdit::Password; // 密码输入
    bool ok = false;
    QString text = QInputDialog::getText(this,dlgTitle,txtLabel,echoMode,
                      defaultInput,&ok);
    if(ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}
// "输入整数"
void Widget::on_btnInputInt_clicked()
{
    QString dlgTitle = "输入整数对话框";
    QString txtLabel = "设置字体大小";
    int defaultValue = ui->plainTextEdit->font().pointSize(); // 字号
    int min = 8,max = 48, step = 1;
    bool ok = false;
    int inputValue = QInputDialog::getInt(this,dlgTitle,txtLabel,
            defaultValue,min,max,step,&ok);
    if(ok){
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(inputValue);
        ui->plainTextEdit->setFont(font);
    }
}
// "输入浮点数"
void Widget::on_btnInputFloat_clicked()
{
    QString dlgTitle = "输入浮点数对话框";
    QString txtLabel = "输入一个浮点数";
    double defaultValue = 1.23;
    double min = 0,max = 1000;
    int decimals = 2;
    bool ok = false;
    double inputValue = QInputDialog::getDouble(this,dlgTitle,txtLabel,
            defaultValue,min,max,decimals,&ok);
    if(ok){
        QString str = QString::asprintf("输入了一个浮点数: %.2f",inputValue);
        ui->plainTextEdit->appendPlainText(str);
    }
}
// "条目选择输入"
void Widget::on_btnInputItem_clicked()
{
    QString dlgTitle = "条目选择对话框";
    QString txtLabel = "请选择级别";
    QStringList items;
    items << "优秀" << "良好" << "中等" << "及格" << "不及格";
    bool ok = false;
    QString text = QInputDialog::getItem(this,dlgTitle,txtLabel,items,0,
                    false,&ok);
    if(ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}
// "information"
void Widget::on_btnInformation_clicked()
{
    QString dlgTitle = "information消息框";
    QString strInfo = "文件已经打开，字体大小已设置";
    QMessageBox::information(this,dlgTitle,strInfo);
}
// "关于"
void Widget::on_btnAbout_clicked()
{
    QString dlgTitle = "anout消息框";
    QString strInfo = "标准对话框 V1.0 \n 版权所有：达内";
    QMessageBox::about(this,dlgTitle,strInfo);
}
// "question"
void Widget::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::question(this,"question消息框",
          "文件已被修改，是否保存修改？",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if(ret == QMessageBox::Yes)
        ui->plainTextEdit->appendPlainText("question消息框：Yes按钮被点击");
    else if(ret == QMessageBox::No)
        ui->plainTextEdit->appendPlainText("question消息框：No按钮被点击");
    else if(QMessageBox::Cancel)
        ui->plainTextEdit->appendPlainText("question消息框：Cancel按钮被点击");
    else
        ui->plainTextEdit->appendPlainText("question消息框：无选择");
}
