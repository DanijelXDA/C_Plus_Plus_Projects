#include "konekcija.h"

Konekcija::Konekcija()
{

}

bool Konekcija::dbOpen()
{
    QFileInfo datoteka(Konekcija::dbPutanja);

    if(datoteka.exists() && datoteka.isFile())
    {
        db.setDatabaseName(dbPutanja);
        if(!db.open())
        {
            qDebug() << "PROVERI PUTANJU BAZE PODATAKA!";
            return false;
        }
        QSqlQuery upit;
        if(!upit.exec("PRAGMA foreign_key = ON;"))
        {
            qDebug() << "Ne radi foreign key!";
            return false;
        }
        else
        {
            qDebug() << "PROGRAM POVEZAN SA BAZOM PODATAKA!";
            return true;
        }
    }
    else
    {
        qDebug() << "PROVERITE DA LI POSTOJI TRAZENA BAZA PODATAKA!";
        return false;
    }

}

void Konekcija::dbClose()
{
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}
