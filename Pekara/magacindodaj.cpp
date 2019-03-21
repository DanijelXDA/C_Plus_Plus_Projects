#include "magacindodaj.h"
#include "ui_magacindodaj.h"
#include "konekcija.h"
#include <QMessageBox>
#include <QDateTime>

magacinDodaj::magacinDodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::magacinDodaj)
{
    ui->setupUi(this);

    // Podešavanje pozadinske slike
    QPixmap pixmap;
    pixmap.load(":/Resursi/Dialozi/dodaj.png");

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);
}

magacinDodaj::~magacinDodaj()
{
    delete ui;
}

void magacinDodaj::on_izlazDugme_clicked()
{
    this -> close();
}

void magacinDodaj::on_dodajDugme_clicked()
{
    Konekcija baza;
    baza.dbOpen();
    QString Naziv, kol, JedinicaMere;
    float Kolicina, NabavnaCena;

    if( ui -> lineEdit_naziv_dodaj -> text().isEmpty() )
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("Polje ne sme biti PRAZNO!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();

    }
    else
    {
        Naziv = ui -> lineEdit_naziv_dodaj -> text();

        if( ui -> lineEdit_kolicina_dodaj -> text().isEmpty() )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Polje ne sme biti PRAZNO!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();

        }
        else if( ui -> lineEdit_nabavnaCena -> text().isEmpty() )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Polje ne sme biti PRAZNO!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();

        }
        else if( ui -> LE_Sifra -> text().isEmpty() )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Polje ne sme biti PRAZNO!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();

        }
        else
        {
            kol = ui -> lineEdit_kolicina_dodaj -> text();
            Kolicina = kol.toFloat();

            JedinicaMere = ui -> magacinIzbor -> currentText();

            QString NC = ui -> lineEdit_nabavnaCena -> text();
            NabavnaCena = NC.toFloat();

            QString sif = ui -> LE_Sifra -> text();
            float sifra = sif.toInt();

            QSqlQuery upit;
            QMessageBox msgBox;

            upit.prepare("INSERT INTO magacinSirovina(Sifra, Naziv, Jed_Mere, Kolicina, Cena) VALUES(:Sifra, :Naziv, :JedinicaMere, :Kolicina, :NabavnaCena)");

            upit.bindValue(":Sifra", sifra); // dodavanje nasih vrednosti
            upit.bindValue(":Naziv", Naziv); // dodavanje nasih vrednosti
            upit.bindValue(":JedinicaMere", JedinicaMere); // dodavanje nasih vrednosti
            upit.bindValue(":Kolicina", Kolicina); // dodavanje nasih vrednosti
            upit.bindValue(":NabavnaCena", NabavnaCena); // dodavanje nasih vrednosti

            // PORUKA O USPESNOM DODAVANJU
            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("Proizvod uspešno dodat u magacin!");
            msgBox.setIcon(QMessageBox::Information);

            upit.exec();
            msgBox.exec();

            ui -> lineEdit_naziv_dodaj -> clear();
            ui -> lineEdit_kolicina_dodaj -> clear();
            ui -> lineEdit_nabavnaCena -> clear();
            ui -> LE_Sifra -> clear();
            ui -> magacinIzbor -> setCurrentIndex(0);

            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString datum, vreme, Datum, Opis;

            datum = cd.toString();
            vreme = ct.toString();

            Datum = datum + " " + vreme;
            Opis = "Dodata sirovina " + Naziv + ", količina " + kol + " " + JedinicaMere.toLower() + ", po ceni od " + NC + " dinara. ";

            QSqlQuery izmena;

            izmena.prepare("INSERT INTO istorijaIzmena(Datum, Opis) VALUES(:Datum, :Opis)");

            izmena.bindValue(":Datum", Datum);
            izmena.bindValue(":Opis", Opis);

            izmena.exec();
        }
    }

    baza.dbClose();
}
