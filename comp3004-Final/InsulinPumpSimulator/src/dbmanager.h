#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DBManager
{
public:
    DBManager();
    ~DBManager();
    
    bool openDB();
    void closeDB();

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H 