#include "connection.h"

connection::connection()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("arsip");
    db.setUserName("root");
    db.setPassword("");
    ok = db.open();
}
connection::~connection()
{
    db.close();
}
