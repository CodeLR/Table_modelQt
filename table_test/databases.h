#ifndef DATABASES_H
#define DATABASES_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Databases
{
    QSqlDatabase db;
public:
    Databases(QString & str);
    void ConnectBase();
    void CreateTable();
    const  QSqlDatabase Getdb();
};

#endif // DATABASES_H
