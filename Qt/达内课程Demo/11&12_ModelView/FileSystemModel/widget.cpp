#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);      // 创建数据模型
    model->setRootPath(QDir::currentPath()); // 设置根目录

    // 设置视图控件的数据模型
    ui->treeView->setModel(model);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

// 点击treeView时，在窗口底部显示当前目录(文件)的信息
void Widget::on_treeView_clicked(const QModelIndex &index)
{
    ui->ckbIsDir->setChecked(model->isDir(index));      // 是否是目录
    ui->labelFileName->setText(model->fileName(index)); // 文件名
    ui->labelFilePath->setText(model->filePath(index)); // 文件路径
    ui->labelType->setText(model->type(index));         // 类型
    qint64 sz = model->size(index);                     // 大小：byte
    if (sz < 1024)
        ui->labelSize->setText(QString("%1 Byte").arg(sz));
    else if (sz < (1024 * 1024))
        ui->labelSize->setText(QString::asprintf("% .1f KB", sz / 1024.0));
    else
        ui->labelSize->setText(QString::asprintf("% .1f MB", sz / 1024.0 / 1024.0));
}
