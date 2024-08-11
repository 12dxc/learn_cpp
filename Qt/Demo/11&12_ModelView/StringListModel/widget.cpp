#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList strList;
    strList << "北京"
            << "上海"
            << "天津"
            << "重庆"
            << "河北"
            << "江苏"
            << "山东"
            << "浙江";
    model = new QStringListModel(this); // 创建数据模型
    model->setStringList(strList);      // 导入strList中的内容
    ui->listView->setModel(model);      // 设置数据模型
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked
                                  | QAbstractItemView::SelectedClicked);
}

Widget::~Widget()
{
    delete ui;
}

// "添加项"
void Widget::on_btnItemAppend_clicked()
{
    model->insertRow(model->rowCount());                         // 在尾部插入一行
    QModelIndex index = model->index(model->rowCount() - 1, 0);  // 获取末尾行号
    model->setData(index, "New Appended Item", Qt::DisplayRole); // 设置指定索引项的内容
    ui->listView->setCurrentIndex(index);                        // 设置当前选中的行
}

// "插入项"
void Widget::on_btnItemInsert_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->insertRow(index.row()); // 在指定位置插入一行
    model->setData(index, "New Inserted Item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

// "删除当前项"
void Widget::on_btnItemDelete_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

// "清除列表"
void Widget::on_btnListClear_clicked()
{
    model->removeRows(0, model->rowCount());
}

// "恢复列表"
void Widget::on_btnListInit_clicked()
{
    QStringList strList;
    strList << "北京"
            << "上海"
            << "天津"
            << "重庆"
            << "河北"
            << "江苏"
            << "山东"
            << "浙江";
    model->setStringList(strList); // 导入strList中的内容
}

// 显示数据模型的StringList
void Widget::on_btnModelData_clicked()
{
    QStringList tmpList = model->stringList();
    ui->plainTextEdit->clear();
    for (int i = 0; i < tmpList.count(); i++)
        ui->plainTextEdit->appendPlainText(tmpList.at(i));
}

// "清空文本"
void Widget::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}

// 点击listView时，获取当前项的行列号
void Widget::on_listView_clicked(const QModelIndex &index)
{
    ui->labelCurItem->setText(
        QString::asprintf("当前条目：row=%d, column=%d", index.row(), index.column()));
}
