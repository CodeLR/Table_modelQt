#ifndef VALIDATORDELEGATE_H
#define VALIDATORDELEGATE_H

#include <QItemDelegate>

class ValidatorDelegate:public QItemDelegate
{
    Q_OBJECT
public:
    ValidatorDelegate(QObject* parent=nullptr);
protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // VALIDATORDELEGATE_H
