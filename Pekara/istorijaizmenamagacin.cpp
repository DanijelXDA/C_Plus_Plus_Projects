#include "istorijaizmenamagacin.h"
#include "ui_istorijaizmenamagacin.h"
#include "konekcija.h"
#include <QMessageBox>

istorijaIzmenaMagacin::istorijaIzmenaMagacin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::istorijaIzmenaMagacin)
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

istorijaIzmenaMagacin::~istorijaIzmenaMagacin()
{
    delete ui;
}

void istorijaIzmenaMagacin::on_izlazDugme_clicked()
{
    this -> close();
}

void istorijaIzmenaMagacin::on_pregledDugme_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();

    baza.dbOpen();

    QSqlQuery upit;

    upit.exec("SELECT *FROM istorijaIzmena");
    modal->setQuery(upit);

    ui -> prikazMagacina -> setModel(modal);

    baza.dbClose();
}
