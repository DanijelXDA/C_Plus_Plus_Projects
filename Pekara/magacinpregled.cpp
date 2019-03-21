#include "magacinpregled.h"
#include "ui_magacinpregled.h"
#include "konekcija.h"

magacinPregled::magacinPregled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::magacinPregled)
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

magacinPregled::~magacinPregled()
{
    delete ui;
}

void magacinPregled::on_izlazDugme_clicked()
{
    this -> close();
}

void magacinPregled::on_pregledDugme_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();

    baza.dbOpen();

    QSqlQuery upit;

    upit.exec("SELECT *FROM magacinSirovina");
    modal->setQuery(upit);

    ui -> prikazMagacina -> setModel(modal);

    baza.dbClose();
}
