#include "gproizvodpregled.h"
#include "ui_gproizvodpregled.h"
#include "konekcija.h"
#include <QMessageBox>

gProizvodPregled::gProizvodPregled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gProizvodPregled)
{
    ui->setupUi(this);

    on_pregledDugme_clicked();

    // Podešavanje pozadinske slike
    QPixmap pixmap;
    pixmap.load(":/Resursi/Dialozi/pregled.png");

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);
}

gProizvodPregled::~gProizvodPregled()
{
    delete ui;
}

void gProizvodPregled::on_izlazDugme_clicked()
{
    this -> close();
}

void gProizvodPregled::on_pregledDugme_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();

    baza.dbOpen();

    QSqlQuery upit;

    upit.exec("SELECT *FROM gotoviProizvodi");
    modal->setQuery(upit);

    ui -> prikazMagacina -> setModel(modal);

    baza.dbClose();
}
