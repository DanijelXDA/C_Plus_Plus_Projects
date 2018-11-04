#include "prijava_na_sistem.h"
#include "ui_prijava_na_sistem.h"
#include <QMessageBox>
#include <QPixmap>

Prijava_Na_Sistem::Prijava_Na_Sistem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Prijava_Na_Sistem)
{
    ui->setupUi(this); // NE MENJATI!
    // Pozadinska slika
    QPixmap bkgnd("://data/bg.jpg");
        //bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

Prijava_Na_Sistem::~Prijava_Na_Sistem()
{
    delete ui;
}

void Prijava_Na_Sistem::on_pushButton_Login_clicked()
{
    // CUVANJE UNESENIH PODATAKA
    QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_password -> text();

    if( username == "Danijel" && password == "12345678" ) // Provera
    {
        QMessageBox::information(this, "Prijava", "Prijava uspešna!");

        hide();
        Pocetna *newmain= new Pocetna();
        newmain -> show();

    }
    else if(username == "" && password == "")
    {
        QMessageBox::warning(this, "Prijava", "Polja ne mogu biti prazna!");
    }
    else
    {
        QMessageBox::warning(this, "Prijava", "Prijava neuspešna!");
    }

}
