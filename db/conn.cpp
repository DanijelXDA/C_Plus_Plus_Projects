#include "conn.h"

Konekcija::Konekcija()
{

}

void Konekcija::dbOpen()
{
    db.setDatabaseName(dbPutanja);
    db.open();

    QSqlQuery upit;
    upit.exec("PRAGMA foreign_key = ON;");
}

void Konekcija::dbClose()
{
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}