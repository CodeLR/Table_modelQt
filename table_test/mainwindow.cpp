#include "mainwindow.h"
#include <QStandardPaths>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Book");
    QString path(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/db.db");
    myDB=new Databases(path);
    myDB->ConnectBase();
    myDB->CreateTable();
    myframe=new Frame(this);
    model=new QSqlTableModel(this,myDB->Getdb());
    model->setTable("Book");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    delegate=new CheckBoxDelegate();
    myframe->GetTable()->setModel(model);
    validatorDelegate=new ValidatorDelegate();
    myframe->GetTable()->setItemDelegateForColumn(4,validatorDelegate);
    myframe->GetTable()->setItemDelegateForColumn(5,delegate);
    emit modelReset();
    setCentralWidget(myframe);
    setMinimumSize(QSize(900,500));
    setMaximumSize(QSize(900,500));





    connect(myframe,SIGNAL(signal_butAdd()),this,SLOT(slotAddRow()));

    connect(model,SIGNAL(modelReset()),this,SLOT(modelReset()));

    connect(myframe,SIGNAL(signal_butDel()),this,SLOT(slotDelRow()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    model->submitAll();
    model->deleteLater();
}

void MainWindow::slotAddRow()
{
    model->insertRow(model->rowCount());
    model->submitAll();
}

void MainWindow::slotDelRow()
{
    model->removeRow(model->rowCount()-1);
    model->submitAll();
}


void MainWindow::modelReset()
{
    myframe->GetTable()->hideColumn(0);
    model->submitAll();
}

