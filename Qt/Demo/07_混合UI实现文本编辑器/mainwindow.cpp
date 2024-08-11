#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->textEdit); // 设置为中心控件

    initUi();

    // 信号和槽函数的连接
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
    connect(cmbFont,
            SIGNAL(currentIndexChanged(QString)),
            this,
            SLOT(on_cmbFont_currentIndexChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
    // 状态栏
    labelCurFile = new QLabel("当前文件: ");
    labelCurFile->setMinimumWidth(350);
    ui->statusbar->addWidget(labelCurFile);

    // 工具栏
    spinBox = new QSpinBox;
    spinBox->setRange(8, 48); // 设置字体大小的范围
    spinBox->setValue(ui->textEdit->font().pointSize());
    spinBox->setMinimumWidth(50);

    cmbFont = new QFontComboBox;
    cmbFont->setMinimumWidth(150);

    ui->toolBar->addWidget(new QLabel(" 字体大小 "));
    ui->toolBar->addWidget(spinBox);
    ui->toolBar->addWidget(new QLabel(" 字体 "));
    ui->toolBar->addWidget(cmbFont);
}

// "粗体"
void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if (checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

// "斜体"
void MainWindow::on_actFontItalci_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

// "下划线"
void MainWindow::on_actFontUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

// 更新cut、copy、paste的enabled属性
void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}

// 更新 粗体、斜体、下划线的checked属性
void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    // 判断是否符合某种字符格式
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontItalci->setChecked(fmt.fontItalic());
    ui->actFontUnderline->setChecked(fmt.fontUnderline());
}

// 改变字体大小
void MainWindow::on_spinBox_valueChanged(int fontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(fontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

// 选择字体
void MainWindow::on_cmbFont_currentIndexChanged(QString const &font)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(font);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

// "显示工具栏文本标签"
void MainWindow::on_actToolbarLab_triggered(bool checked)
{
    if (checked)
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    else
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
}
