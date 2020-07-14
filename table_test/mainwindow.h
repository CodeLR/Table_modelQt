#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QCloseEvent>
#include "databases.h"
#include "frame.h"
#include "checkboxdelegate.h"
#include "validatordelegate.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Databases* myDB;
    Frame * myframe;
    QSqlTableModel* model;
    CheckBoxDelegate*delegate;
    ValidatorDelegate*validatorDelegate;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent* event);
public slots:
    void slotAddRow();
    void slotDelRow();
    void modelReset();
};
#endif // MAINWINDOW_H
