#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QTableView>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QObject>
#include <QPushButton>
#include <QHBoxLayout>
class Frame:public QFrame
{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QTableView* table;

    QPushButton* butAdd;
    QPushButton* butDelete;


public:
    Frame(QWidget* parent=nullptr);
    QTableView* GetTable();
signals:
    void signal_butAdd();
    void signal_butDel();

public slots:
    void slot_add();
    void slot_del();


};

#endif // FRAME_H
