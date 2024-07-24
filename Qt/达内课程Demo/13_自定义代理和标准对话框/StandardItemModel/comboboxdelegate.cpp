#include "comboboxdelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate()
{}

// 创建代理编辑器控件
QWidget* ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QComboBox* editor  = new QComboBox(parent);
    editor->addItem("男");
    editor->addItem("女");
    return editor;
}
// 从数据模型获取数据，显示在代理控件中
void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* cmb = static_cast<QComboBox*>(editor);
    QString str = index.model()->data(index,Qt::EditRole).toString();
    cmb->setCurrentText(str);
}
// 将代理控件中的数据保存到数据模型中
void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* cmb = static_cast<QComboBox*>(editor);
    QString str = cmb->currentText();
    model->setData(index,str,Qt::EditRole);
}
// 设置控件大小
void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
