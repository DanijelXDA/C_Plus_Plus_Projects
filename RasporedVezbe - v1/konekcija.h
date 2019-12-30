#ifndef KONEKCIJA_H
#define KONEKCIJA_H

#include <QtSql/QtSql>

class Konekcija
{
    public:
        Konekcija();
        void dbOpen();
        void dbClose();

    private:
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbPutanja = "C:/Users/Danijel/Desktop/raspored.db";  // Obavezno podesiti adresu baze!!!
    };

#endif // KONEKCIJA_H
