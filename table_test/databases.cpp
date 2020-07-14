#include "databases.h"
#include <QDebug>



Databases::Databases(QString& str)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(str);

    if(!db.open()){
        qDebug()<<"Error!!!"<<db.lastError();
    }
}

void Databases::ConnectBase()
{

}

void Databases::CreateTable()
{
    QSqlQuery query(db);

    if(!db.tables().contains("Book"))
    {
      query.exec(
            "CREATE TABLE Book"
            "("
            " id INTEGER PRIMARY KEY NOT NULL     ,"
            " name               VARCHAR(30)      ,"
            " last_name          VARCHAR(30)      ,"
            " email              VARCHAR(30)      ,"
            " tel                CHAR(14)         ,"
            " children           DESIMAL           "
            ");"
            );
    }
}

const QSqlDatabase Databases::Getdb()
{
    return  db;
}
