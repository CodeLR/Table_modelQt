#include "validatordelegate.h"
#include <QLineEdit>
ValidatorDelegate::ValidatorDelegate(QObject* parent): QItemDelegate(parent)
{

}

QWidget *ValidatorDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);

    QLineEdit *editor=new QLineEdit(parent);
    editor->setValidator(new QIntValidator);
    return  editor;

}

void ValidatorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value=index.model()->data(index,Qt::EditRole).toString();
    QLineEdit* line=static_cast<QLineEdit*>(editor);
    line->setText(value);
}

void ValidatorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    model->setData(index, value,Qt::EditRole);

}

void ValidatorDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    editor->setGeometry(option.rect);
}
