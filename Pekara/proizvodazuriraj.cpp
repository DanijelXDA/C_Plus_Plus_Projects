#include "proizvodazuriraj.h"
#include "ui_proizvodazuriraj.h"
#include "konekcija.h"
#include <QMessageBox>
#include <QDateTime>

proizvodAzuriraj::proizvodAzuriraj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::proizvodAzuriraj)
{
    ui->setupUi(this);
    on_dugmeUcitajAz_clicked();

    // Podešavanje pozadinske slike
    QPixmap pixmap;
    pixmap.load(":/Resursi/Dialozi/azuriraj.png");

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);
}

proizvodAzuriraj::~proizvodAzuriraj()
{
    delete ui;
}

void proizvodAzuriraj::on_dugmeIzlazAz_clicked()
{
    this -> close();
}


void proizvodAzuriraj::on_dugmeUcitajAz_clicked()
{
    Konekcija baza;

    QSqlQueryModel *modal = new QSqlQueryModel();

    baza.dbOpen();

    QSqlQuery upit;

    upit.exec("SELECT Sifra FROM magacinProizvoda");
    modal->setQuery(upit);

    ui -> comboBoxID -> setModel(modal);

    baza.dbClose();
}

void proizvodAzuriraj::on_comboBoxID_currentIndexChanged()
{
    Konekcija baza;
    QString trenutniIndeks = ui -> comboBoxID -> currentText();
    QString jedMere;
    QSqlQuery upit;

    baza.dbOpen();

    upit.exec("SELECT Naziv, Jed_Mere, Kolicina, Cena FROM magacinProizvoda WHERE Sifra = '" + trenutniIndeks + "'");

    if( upit.exec() )
    {
        while( upit.next() )
        {
            ui -> lineEdit_naziv_az -> setText(upit.value(0).toString());
            ui -> lineEdit_kolicina_az -> setText(upit.value(2).toString());
            ui -> lineEdit_nbCena -> setText(upit.value(3).toString());

            jedMere = upit.value(1).toString();
            // setovanje indeksa comboBox-a za jedinicu mere
            if(jedMere == "Gram")
                ui -> magacinIzbor_az -> setCurrentIndex(0);
            else if(jedMere == "Kilogram")
                ui -> magacinIzbor_az -> setCurrentIndex(1);
            else if(jedMere == "Komad")
                ui -> magacinIzbor_az -> setCurrentIndex(2);
            else
                ui -> magacinIzbor_az -> setCurrentIndex(3);
         }
    }

    baza.dbClose();
}

void proizvodAzuriraj::on_azurirajDugme_clicked()
{
    Konekcija baza;
    baza.dbOpen();
    QString Naziv, kol, JedinicaMere;
    float Kolicina, cena;

    if( ui -> lineEdit_naziv_az -> text().isEmpty() )
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("Polje ne sme biti PRAZNO!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();

    }
    else if( ui -> lineEdit_nbCena -> text().isEmpty() )
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("Polje ne sme biti PRAZNO!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();

    }
    else
    {
        Naziv = ui -> lineEdit_naziv_az -> text();

        if( ui -> lineEdit_kolicina_az -> text().isEmpty() )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Polje ne sme biti PRAZNO!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();

        }
        else
        {
            QString trenutniIndeks = ui -> comboBoxID -> currentText();
            kol = ui -> lineEdit_kolicina_az -> text();
            Kolicina = kol.toFloat();

            QString Cena = ui -> lineEdit_nbCena -> text();
            cena = Cena.toFloat();

            JedinicaMere = ui -> magacinIzbor_az -> currentText();

            QSqlQuery upit;
            QMessageBox msgBox;

            upit.prepare("UPDATE magacinProizvoda SET Naziv = :Naziv, Kolicina = :Kolicina, Jed_Mere = :JedinicaMere, Cena = :Cena WHERE Sifra = :Indeks");

            //upit.bindValue(":ID", 1); // dodavanje nasih vrednosti
            upit.bindValue(":Naziv", Naziv); // dodavanje nasih vrednosti
            upit.bindValue(":Kolicina", Kolicina); // dodavanje nasih vrednosti
            upit.bindValue(":JedinicaMere", JedinicaMere); // dodavanje nasih vrednosti
            upit.bindValue(":Indeks", trenutniIndeks); // dodavanje nasih vrednosti
            upit.bindValue(":Cena", cena); // dodavanje nasih vrednosti

            // PORUKA O USPESNOM DODAVANJU
            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Proizvod je uspešno ažuriran!");
            msgBox.setIcon(QMessageBox::Information);

            upit.exec();
            msgBox.exec();

            ui -> lineEdit_naziv_az -> clear();
            ui -> lineEdit_kolicina_az -> clear();
            ui -> magacinIzbor_az -> setCurrentIndex(0);

            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString datum, vreme, Datum, Opis;

            datum = cd.toString();
            vreme = ct.toString();

            Datum = datum + " " + vreme;
            Opis = "Ažurirano " + Naziv + ", nova količina " + kol + " " + JedinicaMere + ", nova cena od " + Cena + " dinara. ";

            QSqlQuery izmena;

            izmena.prepare("INSERT INTO istorijaIzmena(Datum, Opis) VALUES(:Datum, :Opis)");

            izmena.bindValue(":Datum", Datum);
            izmena.bindValue(":Opis", Opis);

            izmena.exec();

            on_dugmeUcitajAz_clicked(); // ponovo ucitaj podatke

         }
    }

    baza.dbClose();
}
