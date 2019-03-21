#include "proizvodpregled.h"
#include "ui_proizvodpregled.h"
#include "konekcija.h"

proizvodPregled::proizvodPregled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::proizvodPregled)
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

proizvodPregled::~proizvodPregled()
{
    delete ui;
}

void proizvodPregled::on_izlazDugme_clicked()
{
    this -> close();
}

void proizvodPregled::on_pregledDugme_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();

    baza.dbOpen();

    QSqlQuery upit;

    upit.exec("SELECT *FROM magacinProizvoda");
    modal->setQuery(upit);

    ui -> prikazMagacina -> setModel(modal);

    baza.dbClose();
}
