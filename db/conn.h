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
        QString dbPutanja = "D:/NetworkDrive/qt/PPPR/Baza.db";
        // QString dbPutanja = "C:/Program Files/PPPR/Baza.db";  // Obavezno podesiti adresu baze!!!
    };

#endif // KONEKCIJA_H
