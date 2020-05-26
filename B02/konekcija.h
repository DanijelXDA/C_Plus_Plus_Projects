#ifndef KONEKCIJA_H
#define KONEKCIJA_H

#include <QtSql>

class Konekcija
{
public:
    Konekcija();
    bool dbOpen();
    void dbClose();

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPutanja = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
            + "/Baze Podataka/b02.db";
};

#endif // KONEKCIJA_H
