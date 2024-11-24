#ifndef DB_CPP
#define DB_CPP
#include "src/h/db.h"

#endif // DB_CPP

QSqlDatabase db;

void set_db(){
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("87.251.74.199");
    db.setPort(5432);
    db.setDatabaseName("hack_db");
    db.setUserName("postgres");
    db.setPassword("sovietchungus");
}

void DBExceptionHandler(QString error){
    QString str = QDate::currentDate().toString("dd.MM.yyyy") + " " + QTime::currentTime().toString() + "\n" + error + "\n\n";
    QDir dir;
    if (dir.mkdir("../logs"));
    QFile f("../logs/RecErr.log");
    if(f.open(QIODevice::Append)){
        f.write(str.toLocal8Bit());
    }
    f.close();
}
