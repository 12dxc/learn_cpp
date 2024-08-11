#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->splitter);

    // 为QToolButton的按钮设置QAction
    ui->tBtnListInit->setDefaultAction(ui->actListInit);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnItemInsert->setDefaultAction(ui->actItemInsert);
    ui->tBtnItemAppend->setDefaultAction(ui->actItemAppend);
    ui->tBtnItemDelete->setDefaultAction(ui->actItemDelete);

    ui->tBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->tBtnSelNone->setDefaultAction(ui->actSeleNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);

    // 创建下拉菜单
    QMenu* menuSelection = new QMenu(this);  // 创建项选择弹出式菜单
    menuSelection->addAction(ui->actSelAll);
    menuSelection->addAction(ui->actSeleNone);
    menuSelection->addAction(ui->actSelInvs);

    // tBtnSelectionItem
    ui->tBtnSelectionItem->setPopupMode(QToolButton::MenuButtonPopup); // 菜单弹出模式
    ui->tBtnSelectionItem->setDefaultAction(ui->actSelPopup); // 关联的QAction
    ui->tBtnSelectionItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);// 按钮显示样式
    ui->tBtnSelectionItem->setMenu(menuSelection);

    // 工具栏添加带有下拉菜单的按钮
    QToolButton* btn = new QToolButton(this);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn->setPopupMode(QToolButton::DelayedPopup);
    btn->setDefaultAction(ui->actSelPopup);
    btn->setMenu(menuSelection);

    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(btn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// "初始化列表"
void MainWindow::on_actListInit_triggered()
{
    QListWidgetItem* item;  // 每一行是一个QListWidgetItem
    QIcon icon(":/icons/check.ico");
    bool chk = ui->ckbEditable->isChecked();  // 是否可编辑
    ui->listWidget->clear();  // 清空listWidget
    for(int i=0;i<10;i++){
        QString str = QString::asprintf("Item %d",i);
        item = new QListWidgetItem;
        item->setText(str);
        item->setIcon(icon);
        item->setCheckState(Qt::Checked);  // 设置为选中状态
        if(chk)
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled |Qt::ItemIsUserCheckable
                           |Qt::ItemIsEditable);
        else
           item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);

        ui->listWidget->addItem(item);
    }
}
// "插入项"
void MainWindow::on_actItemInsert_triggered()
{
    QIcon icon(":/icons/check.ico");
    bool chk = ui->ckbEditable->isChecked();  // 是否可编辑
    QListWidgetItem* item = new QListWidgetItem(icon,"New Insert Item");
    item->setCheckState(Qt::Checked);  // 设置为选中状态
    if(chk)
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled |Qt::ItemIsUserCheckable
                       |Qt::ItemIsEditable);
    else
       item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
    ui->listWidget->insertItem(ui->listWidget->currentRow(),item);
}
// "添加项"
void MainWindow::on_actItemAppend_triggered()
{
    QIcon icon(":/icons/check.ico");
    bool chk = ui->ckbEditable->isChecked();  // 是否可编辑
    QListWidgetItem* item = new QListWidgetItem(icon,"New Append Item");
    item->setCheckState(Qt::Checked);  // 设置为选中状态
    if(chk)
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled |Qt::ItemIsUserCheckable
                       |Qt::ItemIsEditable);
    else
       item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
    ui->listWidget->addItem(item);
}
// "删除当前项"
void MainWindow::on_actItemDelete_triggered()
{
    int rowNo = ui->listWidget->currentRow();  // 当前行的行号
    QListWidgetItem* item = ui->listWidget->takeItem(rowNo);
    delete item;
}
// "清除列表"
void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}
// "全选"
void MainWindow::on_actSelAll_triggered()
{
    int cnt = ui->listWidget->count();  // 获取listWidget中的项的数量
    for(int i=0;i<cnt;i++){
        QListWidgetItem* item = ui->listWidget->item(i);  // 获取一项
        item->setCheckState(Qt::Checked);  // 设为选中状态
    }
}
// "全不选"
void MainWindow::on_actSeleNone_triggered()
{
    int cnt = ui->listWidget->count();  // 获取listWidget中的项的数量
    for(int i=0;i<cnt;i++){
        QListWidgetItem* item = ui->listWidget->item(i);  // 获取一项
        item->setCheckState(Qt::Unchecked);  // 设为未选中状态
    }
}
// "反选"
void MainWindow::on_actSelInvs_triggered()
{
    int cnt = ui->listWidget->count();  // 获取listWidget中的项的数量
    for(int i=0;i<cnt;i++){
        QListWidgetItem* item = ui->listWidget->item(i);  // 获取一项
        if(item->checkState() == Qt::Checked)
             item->setCheckState(Qt::Unchecked);  // 设为未选中状态
        else if(item->checkState() == Qt::Unchecked)
            item->setCheckState(Qt::Checked);
    }
}
// 当前项发生变化时：currentItemChanged(..)
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if(current != NULL){
        if(previous == NULL)
            str = "当前项：" + current->text();
        else
            str = "前一项：" + previous->text() + ", 当前项：" + current->text();
        ui->editCurItem->setText(str);
    }
}
// "可编辑"
void MainWindow::on_ckbEditable_clicked(bool checked)
{
    QListWidgetItem* item;
    int cnt = ui->listWidget->count();
    for(int i=0;i<cnt;i++){
        item = ui->listWidget->item(i);
        if(checked)
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled |Qt::ItemIsUserCheckable
                           |Qt::ItemIsEditable);
        else
           item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
    }
}
// "项选择"
void MainWindow::on_actSelPopup_triggered()
{
    QMessageBox::information(this,"QToolButton","点击了项选择");
}
