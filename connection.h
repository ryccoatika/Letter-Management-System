#ifndef CONNECTION_H
#define CONNECTION_H

#include "QtSql"
#include <sstream>
#include <string>
#include <QCryptographicHash>

using std::string;
using std::stringstream;

class connection
{
public:
    QCryptographicHash * hash;
    QSqlDatabase db;
    bool ok;
    connection();
    ~connection();
};

#endif // CONNECTION_H
