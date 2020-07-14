#include "frame.h"
#include <QHeaderView>
Frame::Frame(QWidget* parent):QFrame(parent)
{
    table=new QTableView(this);
    layout=new QVBoxLayout(this);
    layout->addWidget(table);

    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setFocusPolicy(Qt::NoFocus);
    table->resizeRowsToContents();
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setAcceptDrops(true);





    butAdd=new QPushButton("+",this);
    butAdd->setStyleSheet("font: bold;background-color: green;font-size: 24px;height: 32px;width: 100px;");
    butDelete=new QPushButton("-",this);
    butDelete->setStyleSheet("font: bold;background-color: red;font-size: 24px;height: 32px;width: 100px;");


    QHBoxLayout* layoutH=new QHBoxLayout(this);
    layoutH->addWidget(butAdd);
    layoutH->addWidget(butDelete);
    layout->addLayout(layoutH);
    connect(butAdd,SIGNAL(clicked()),this,SLOT(slot_add()));
    connect(butDelete,SIGNAL(clicked()),this,SLOT(slot_del()));
}

QTableView* Frame::GetTable()
{
    return table;
}

void Frame::slot_add()
{
    emit signal_butAdd();
}

void Frame::slot_del()
{
    emit signal_butDel();
}
