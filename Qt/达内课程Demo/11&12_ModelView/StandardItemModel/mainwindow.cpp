#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->splitter);

    model = new QStandardItemModel(2, COLUMNCOUNT, this);                  // 创建数据模型
    selection = new QItemSelectionModel(model);                            // 创建选择模型
    ui->tableView->setModel(model);                                        // 设置数据模型
    ui->tableView->setSelectionModel(selection);                           // 设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); // 设置选择模式
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);   // 设置选择行为

    initUi(); // 初始化状态栏

    connect(selection,
            SIGNAL(currentChanged(QModelIndex, QModelIndex)),
            this,
            SLOT(on_CurrentChanged(QModelIndex, QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 初始化状态栏，即三个Label
void MainWindow::initUi()
{
    labelCurFile = new QLabel("当前文件：");
    labelCurFile->setMinimumWidth(400);
    ui->statusbar->addWidget(labelCurFile);

    labelCellPos = new QLabel("当前单元格：");
    labelCellPos->setMinimumWidth(200);
    ui->statusbar->addWidget(labelCellPos);

    labelCellText = new QLabel("单元格文本：");
    labelCellText->setMinimumWidth(200);
    ui->statusbar->addWidget(labelCellText);
}

// 更新状态栏
void MainWindow::on_CurrentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous)
    if (current.isValid()) {
        labelCellPos->setText(
            QString::asprintf(" 当前单元格：%d 行,%d 列", current.row(), current.column()));
        QStandardItem *item = model->itemFromIndex(current); // 获取当前单元项
        labelCellText->setText("单元格文本：" + item->text());
        QFont font = item->font();
        ui->actFontBold->setCheckable(font.bold()); // 如果单元项是粗体则状态栏也显示粗体
    }
}

// "打开"
void MainWindow::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "打开文件",
                                                    curPath,
                                                    "学生信息文件(*.txt);;所有文件(*.*)");
    if (fileName.isEmpty())
        return;
    QStringList fileContent;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 打开文件
        QTextStream stream(&file);                          // 用文本流读取文件
        stream.setEncoding(QStringConverter::Utf8);
        ui->plainTextEdit->clear();
        while (!stream.atEnd()) {
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fileContent.append(str);
        }
        file.close();
        labelCurFile->setText("当前文件: " + fileName); // 状态栏显示

        initModelFromStringList(fileContent);
    }
}

void MainWindow::initModelFromStringList(QStringList &fileContent)
{
    int rowCnt = fileContent.count(); // 文本行数  第一行是表头
    model->setRowCount(rowCnt - 1);
    // 设置表头
    QString header = fileContent.at(0); // "学号	姓名	出生日期	性别	联系方式"
    QStringList headerList = header.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    model->setHorizontalHeaderLabels(headerList);

    // 设置内容
    QStandardItem *item;
    QStringList tmpList;
    for (int i = 1; i < rowCnt; i++) {
        QString lineText = fileContent.at(i);
        tmpList = lineText.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        for (int j = 0; j < COLUMNCOUNT; j++) {
            item = new QStandardItem(tmpList.at(j));
            model->setItem(i - 1, j, item); // 为模型的某个行列位置设置item
        }
    }
}

// "添加行"
void MainWindow::on_actAppend_triggered()
{
    QList<QStandardItem *> itemList; // 项的列表
    QStandardItem *item;
    for (int i = 0; i < COLUMNCOUNT; i++) {
        item = new QStandardItem(""); // 创建item
        itemList << item;
    }
    model->insertRow(model->rowCount(), itemList); // 在尾端插入一行
    QModelIndex index = model->index(model->rowCount() - 1, 0);
    selection->clearSelection();
    selection->setCurrentIndex(index, QItemSelectionModel::Select);
}

// "插入行"
void MainWindow::on_actInsert_triggered()
{
    QList<QStandardItem *> itemList; // 项的列表
    QStandardItem *item;
    for (int i = 0; i < COLUMNCOUNT; i++) {
        item = new QStandardItem(""); // 创建item
        itemList << item;
    }
    QModelIndex index = selection->currentIndex(); // 获取当前选中项的模型索引
    model->insertRow(index.row(), itemList);
    selection->clearSelection();
    selection->setCurrentIndex(index, QItemSelectionModel::Select);
}

// "删除行"
void MainWindow::on_actDelete_triggered()
{
    QModelIndex index = selection->currentIndex(); // 获取当前选中项的模型索引
    if (index.row() == model->rowCount() - 1)      // 最后一行
        model->removeRow(index.row());             // 删除一行
    else {
        model->removeRow(index.row());
        selection->setCurrentIndex(index, QItemSelectionModel::Select);
    }
}

// "居左"
void MainWindow::on_actAlignLeft_triggered()
{
    if (!selection->hasSelection())
        return;
    // 获取选择的单元的模型索引，可以是多选
    QModelIndexList selectedIndexes = selection->selectedIndexes();
    for (int i = 0; i < selectedIndexes.count(); i++) {
        QModelIndex index = selectedIndexes.at(i);
        QStandardItem *item = model->itemFromIndex(index);        // 通过索引获得项
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter); // 设置文本对齐方式
    }
}

// "居中"
void MainWindow::on_actAlignCenter_triggered()
{
    if (!selection->hasSelection())
        return;
    // 获取选择的单元的模型索引，可以是多选
    QModelIndexList selectedIndexes = selection->selectedIndexes();
    for (int i = 0; i < selectedIndexes.count(); i++) {
        QModelIndex index = selectedIndexes.at(i);
        QStandardItem *item = model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignCenter); // 设置文本对齐方式
    }
}
// "右对齐"
void MainWindow::on_actAlignRight_triggered()
{
    if (!selection->hasSelection())
        return;
    // 获取选择的单元的模型索引，可以是多选
    QModelIndexList selectedIndexes = selection->selectedIndexes();
    for (int i = 0; i < selectedIndexes.count(); i++) {
        QModelIndex index = selectedIndexes.at(i);
        QStandardItem *item = model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 设置文本对齐方式
    }
}

// "粗体"
void MainWindow::on_actFontBold_triggered(bool checked)
{
    if (!selection->hasSelection())
        return;
    // 获取选择的单元的模型索引，可以是多选
    QModelIndexList selectedIndexes = selection->selectedIndexes();
    for (int i = 0; i < selectedIndexes.count(); i++) {
        QModelIndex index = selectedIndexes.at(i);
        QStandardItem *item = model->itemFromIndex(index); // 获取项
        // 设置字体属性
        QFont font = item->font();
        font.setBold(checked); // 设置字体是否为粗体
        item->setFont(font);
    }
}

// "另存文件"
void MainWindow::on_actSave_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "保存文件",
                                                    curPath,
                                                    "学生信息文件(*.txt);;所有文件(*.*)");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!(file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
        return; // 以读写、文本、覆盖的方式打开文件
    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8);
    QStandardItem *item;
    QString str;
    ui->plainTextEdit->clear();
    // 获取表头文本
    for (int i = 0; i < COLUMNCOUNT; i++) {
        item = model->horizontalHeaderItem(i); // 获取表头的项数据
        str = str + item->text() + "\t";
    }
    stream << str << "\n";
    ui->plainTextEdit->appendPlainText(str);
    // 获取数据区文本
    for (int i = 0; i < model->rowCount(); i++) {
        str = "";
        for (int j = 0; j < COLUMNCOUNT; j++) {
            item = model->item(i, j);
            str = str + item->text() + "\t";
        }
        stream << str << "\n";
        ui->plainTextEdit->appendPlainText(str);
    }
    file.close();
}

// "模型数据预览"
void MainWindow::on_actModelData_triggered()
{
    QStandardItem *item;
    QString str;
    ui->plainTextEdit->clear();
    // 获取表头文本
    for (int i = 0; i < COLUMNCOUNT; i++) {
        item = model->horizontalHeaderItem(i); // 获取表头的项数据
        str = str + item->text() + "\t";
    }
    ui->plainTextEdit->appendPlainText(str);
    // 获取数据区文本
    for (int i = 0; i < model->rowCount(); i++) {
        str = "";
        for (int j = 0; j < COLUMNCOUNT; j++) {
            item = model->item(i, j);
            str = str + item->text() + "\t";
        }
        ui->plainTextEdit->appendPlainText(str);
    }
}
