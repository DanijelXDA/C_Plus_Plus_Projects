#include "pocetna.h"
#include "ui_pocetna.h"
#include "konekcija.h"
#include <QMessageBox>
#include <QProgressDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

Pocetna::Pocetna(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pocetna)
{
    ui->setupUi(this);
}

Pocetna::~Pocetna()
{
    delete ui;
}


void Pocetna::on_pushButton_clicked()
{
    this -> close();
}

void Pocetna::on_upisUBazu_clicked()
{
    Konekcija baza;
    baza.dbOpen(); // PRIPREMA BAZE PODATAKA

    // PRIKUPLJANJE PODATAKA
    int brojKabineta = (ui -> brKabineta -> text().isEmpty() == true)
                       ? 0 : (ui -> brKabineta -> text().toInt());
    QString profesor = ui -> imeProf -> text();
    int brojCasova = ui -> brojCasova -> text().toInt();
    int razred = ui -> razredCb -> currentText().toInt();
    int odeljenje = ui -> odeljenje -> text().toInt();
    QString grupa = ui -> grupaCb -> currentText();

    // UPIS PODATAKA U BAZU
    QSqlQuery upit;

    upit.prepare("INSERT INTO SPISAK VALUES(:bk, :prof, :brc, :r, :o, :g)");
    upit.bindValue(":bk", brojKabineta);
    upit.bindValue(":prof", profesor);
    upit.bindValue(":brc", brojCasova);
    upit.bindValue(":r", razred);
    upit.bindValue(":o", odeljenje);
    upit.bindValue(":g", grupa);


    if(upit.exec())
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("UPIS U BAZU USPEŠAN!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("UPIS U BAZU NEUSPEŠAN!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }

    baza.dbClose();
}

void Pocetna::on_prikaziRaspored_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery upit;

    baza.dbOpen();

    // PRIKAZ PODATAKA IZ BAZE
    switch (ui -> dan -> currentIndex())
    {
    case 0:
        upit.exec("SELECT *FROM PONEDELJAK;");
        break;
    case 1:
        upit.exec("SELECT *FROM UTORAK;");
        break;
    case 2:
        upit.exec("SELECT *FROM SREDA;");
        break;
    case 3:
        upit.exec("SELECT *FROM ČETVRTAK;");
        break;
    case 4:
        upit.exec("SELECT *FROM PETAK;");
        break;
    }

    modal -> setQuery(upit);
    ui -> prikaz -> setModel(modal);

    baza.dbClose();
}

void Pocetna::on_generisanjeBtn_clicked()
{
    // GENERISANJE RASPOREDA
    Konekcija baza;
    baza.dbOpen();
    QSqlQuery upit;

    // LOGIKA - RASPOREDJUJ PRIORITETNE KABINETE
    // PRI UNOSU BROJA KABINETA AKO JE 0, BILO GDE
    // GDE IMA SLOBODNO, NEKI BROJ, IDE TO PRVO
    upit.exec("SELECT COUNT(BrojKabineta) FROM spisak");
    upit.first(); // POZICIONIRANJE
    int len = upit.value(0).toInt();

    upit.exec("SELECT *FROM spisak ORDER BY BrojKabineta DESC");
    upit.first();
    // QString dani[5] = {"PONEDELJAK", "UTORAK", "SREDA", "ČETVRTAK", "PETAK"};
    // 56A
    // 56 - BROJ KABINETA
    // A - PONEDELJAK; B - UTORAK; C - SREDA; D - ČETVRTAK; E - PETAK
    int popunjeno = 0;
    QString brKDan;

    for(int i = 1; i <= len; i++)
    {
        QString kab = upit.value(0).toString(),
                prof = upit.value(1).toString(),
                brojCasova = upit.value(2).toString(),
                raz = upit.value(3).toString(),
                od = upit.value(4).toString(),
                grupa = upit.value(5).toString();

        QString string = prof + " " + raz + "-" + od + " (Grupa: " + grupa + ")";

    }
    upit.next(); // SLEDEĆI RED U TABELI SPISAK

    baza.dbClose();
}

void Pocetna::on_deleteSpisakBtn_clicked()
{
    // ISPRAZNI TABELU SPISAK
    Konekcija baza;
    QSqlQuery upit;

    baza.dbOpen();

    QMessageBox msgBox;

    msgBox.setWindowTitle("Upozorenje!");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Brisanje podataka iz baze je NEPOVRATNO!\nNastaviti brisanje svih unosa?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        if(upit.exec("DELETE FROM spisak WHERE 1;") )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("SVI UPISI SU OBRISANI!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();
        }
        else
        {
            qDebug() << upit.lastError();
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("UPISI NISU OBRISANI!");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
    }

    baza.dbClose();
}

void Pocetna::on_deleteRasporedBtn_clicked()
{
    // ISPRAZNI TABELE RASPORED PO DANIMA (PONEDELJAK, ...)
    Konekcija baza;
    QSqlQuery upit;

    baza.dbOpen();

    QMessageBox msgBox;

    msgBox.setWindowTitle("Upozorenje!");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Brisanje podataka iz baze je NEPOVRATNO!\nNastaviti brisanje svih unosa?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        if( upit.exec("DELETE FROM PONEDELJAK WHERE 1;") && upit.exec("DELETE FROM UTORAK WHERE 1;")
                && upit.exec("DELETE FROM SREDA WHERE 1;") && upit.exec("DELETE FROM ČETVRTAK WHERE 1;")
                && upit.exec("DELETE FROM PETAK WHERE 1;") )
        {
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("SVI UPISI SU OBRISANI!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();
        }
        else
        {
            qDebug() << upit.lastError();
            QMessageBox msgBox;

            msgBox.setWindowTitle("Obaveštenje");
            msgBox.setText("UPISI NISU OBRISANI!");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
    }

    baza.dbClose();
}
