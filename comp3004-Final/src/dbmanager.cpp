#include "dbmanager.h"
#include <QDir>

DBManager::DBManager()
{
    // Initialize the database but don't open yet
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
}

DBManager::~DBManager()
{
    closeDB();
}

bool DBManager::openDB()
{
    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Database connection failed:" << db.lastError().text();
        return false;
    }
    
    // Create tables if they don't exist
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, name TEXT)")) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return false;
    }
    
    return true;
}

void DBManager::closeDB()
{
    if (db.isOpen()) {
        db.close();
    }
} 