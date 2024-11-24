#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QDate>

void set_db();
void DBExceptionHandler(QString error);
extern QSqlDatabase db;

#endif // DB_H
