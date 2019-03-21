#include "glavniprozor.h"
#include "ui_glavniprozor.h"

#include "magacindodaj.h"
#include "magacinazuriraj.h"
#include "magacinpregled.h"
#include "trebovanjemagacin.h"

#include "istorijaizmenamagacin.h"

#include "proizvoddodaj.h"
#include "proizvodukloni.h"
#include "proizvodazuriraj.h"
#include "proizvodpregled.h"

#include "gproizvoddodaj.h"
#include "gproizvodazuriraj.h"
#include "gproizvodukloni.h"


#include "gproizvodpregled.h"
#include "otpis.h"

#include "trebovanjegproizvod.h"

#include "prodajamaloprodaja.h"

#include "izborprodavca.h"

#include "konekcija.h"

GlavniProzor::GlavniProzor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GlavniProzor)
{
    ui->setupUi(this);

    // Podešavanje pozadinske slike
    QPixmap pixmap;
    pixmap.load(":/Resursi/pozadina.jpg");

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);
}

GlavniProzor::~GlavniProzor()
{
    delete ui;
}

void GlavniProzor::on_actionDodaj_u_magacin_triggered()
{
    magacinDodaj *m = new magacinDodaj(this);
    m -> setModal(true);
    m -> show();
}

void GlavniProzor::on_azuriranjeMagacin_triggered()
{
    magacinAzuriraj *m = new magacinAzuriraj(this);
    m -> setModal(true);
    m -> show();
}

void GlavniProzor::on_isprazniMagacin_triggered()
{
    Konekcija baza;
    baza.dbOpen();
    QSqlQuery isprazni;

    QMessageBox msgBox;

    msgBox.setWindowTitle("Obaveštenje");
    msgBox.setText("Da li ste sigurni da želite da ispraznite Magacin?\nOva operacija TRAJNO briše sadržaj magacina!");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        isprazni.exec("DELETE FROM magacinSirovina WHERE 1");
        isprazni.exec("UPDATE SQLITE_SEQUENCE SET seq = 600 WHERE name = 'magacinSirovina'"); // setovanje sifre na 101

        QMessageBox infoMsgBox;

        infoMsgBox.setWindowTitle("Obaveštenje");
        infoMsgBox.setText("Magacin je uspešno ispražnjen!");
        infoMsgBox.setIcon(QMessageBox::Information);
        infoMsgBox.exec();
    }

    baza.dbClose();
}

void GlavniProzor::on_isprazniProizvode_triggered()
{
    Konekcija baza;
    baza.dbOpen();
    QSqlQuery isprazni;

    QMessageBox msgBox;

    msgBox.setWindowTitle("Obaveštenje");
    msgBox.setText("Da li ste sigurni da želite da ispraznite Magacin?\nOva operacija TRAJNO briše sadržaj magacina!");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        isprazni.exec("DELETE FROM magacinProizvoda WHERE 1");
        isprazni.exec("UPDATE SQLITE_SEQUENCE SET seq = 200 WHERE name = 'magacinProizvoda'"); // setovanje sifre na 201

        QMessageBox infoMsgBox;

        infoMsgBox.setWindowTitle("Obaveštenje");
        infoMsgBox.setText("Magacin je uspešno ispražnjen!");
        infoMsgBox.setIcon(QMessageBox::Information);
        infoMsgBox.exec();
    }

    baza.dbClose();
}

void GlavniProzor::on_isprazniGotoveProizvode_triggered()
{
    Konekcija baza;
    baza.dbOpen();
    QSqlQuery isprazni;

    QMessageBox msgBox;

    msgBox.setWindowTitle("Obaveštenje");
    msgBox.setText("Da li ste sigurni da želite da ispraznite Magacin?\nOva operacija TRAJNO briše sadržaj magacina!");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        isprazni.exec("DELETE FROM gotoviProizvodi WHERE 1");
        isprazni.exec("UPDATE SQLITE_SEQUENCE SET seq = 300 WHERE name = 'gotoviProizvodi'"); // setovanje sifre na 201

        QMessageBox infoMsgBox;

        infoMsgBox.setWindowTitle("Obaveštenje");
        infoMsgBox.setText("Magacin je uspešno ispražnjen!");
        infoMsgBox.setIcon(QMessageBox::Information);
        infoMsgBox.exec();
    }

    baza.dbClose();
}

void GlavniProzor::on_pregledMagacina_triggered()
{
    magacinPregled *m = new magacinPregled(this);
    m -> setModal(true);
    m -> show();
}


// proizvod dodaj
void GlavniProzor::on_actionProizvodDodaj_triggered()
{
    proizvodDodaj *p = new proizvodDodaj(this);
    p -> setModal(true);
    p -> show();
}


// proizvod azuriraj
void GlavniProzor::on_actionAzurirajProizvod_triggered()
{
    proizvodAzuriraj *p = new proizvodAzuriraj(this);
    p -> setModal(true);
    p -> show();
}

// proizvod ukloni
void GlavniProzor::on_actionProizvodUkloni_triggered()
{
    proizvodukloni *p = new proizvodukloni(this);
    p -> setModal(true);
    p -> show();
}


// magacin gotovih proizvoda
void GlavniProzor::on_DodajGProizvod_triggered()
{
    gProizvodDodaj *g = new gProizvodDodaj(this);
    g -> setModal(true);
    g -> show();
}

// magacin gotovih proizvoda
void GlavniProzor::on_azurirajGProizvod_triggered()
{
    gProizvodAzuriraj *g = new gProizvodAzuriraj(this);
    g -> setModal(true);
    g -> show();
}

// magacin gotovih proizvoda
void GlavniProzor::on_ukloniGProizvod_triggered()
{
    gProizvodUkloni *g = new gProizvodUkloni(this);
    g -> setModal(true);
    g -> show();
}

// magacin gotovih proizvoda
void GlavniProzor::on_gProizvodPregled_triggered()
{
    gProizvodPregled *g = new gProizvodPregled(this);
    g -> setModal(true);
    g -> show();
}

void GlavniProzor::on_actionPregledProizvod_triggered()
{
    proizvodPregled *p = new proizvodPregled(this);
    p -> setModal(true);
    p -> show();
}

void GlavniProzor::on_istorijaIzmenaMagacin_triggered()
{
    istorijaIzmenaMagacin *i = new istorijaIzmenaMagacin(this);
    i -> setModal(true);
    i -> show();
}

void GlavniProzor::on_trebovanjeMagacin_triggered()
{
    trebovanjeMagacin *t = new trebovanjeMagacin(this);
    t -> setModal(true);
    t -> show();
}

void GlavniProzor::on_trebovanjeGProizvoda_triggered()
{
    trebovanjeGProizvod *t = new trebovanjeGProizvod(this);
    t -> setModal(true);
    t -> show();
}

void GlavniProzor::on_otpisProizvoda_triggered()
{
    otpis *o = new otpis(this);
    o -> setModal(true);
    o -> show();
}

// prodaja maloprodaja
void GlavniProzor::on_actionProdaja_triggered()
{
    prodajaMaloprodaja *p = new prodajaMaloprodaja(this);
    p -> setModal(true);
    p -> show();
}

void GlavniProzor::on_actionIzlaz_triggered()
{
    this -> close();
}


void GlavniProzor::on_izborProdavca_triggered()
{
    izborProdavca *p = new izborProdavca(this);
    p -> setModal(true);
    p -> show();
}


void GlavniProzor::on_actionOaplikaciji_triggered()
{
    QMessageBox::about(this, tr("Aplikacija Pekara | O aplikaciji"),
    tr("<h1>Pekara 1.1.9</h1>"
    "<h3>Copyright &copy; 2019 Danijel Jovanović"
    "<h3>Apikacija Pekara je mala aplikacija koja služi za rad sa: </h3>"
    "<h3> -> Trebovanjem Pekare, <br/> -> Magacinima Pekare, <br/> -> Manipulacijom Magacina, "
    "<br/> -> Kontrolom Ulaza/Izlaza Magacina, <br/> -> Upravljanje sirovinama, <br/> -> Upravljanje proizvodima, i ostalim "
    "poslovima Pekare.</h3>"));
}
