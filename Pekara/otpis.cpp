#include "otpis.h"
#include "ui_otpis.h"
#include "konekcija.h"

otpis::otpis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otpis)
{
    ui->setupUi(this);

    // setovanje elemenata
    ui -> jedMereLE -> setReadOnly(true);

    QPalette *palette3 = new QPalette();
    palette3 -> setColor(QPalette::Base, "#F0F0F0");
    palette3 -> setColor(QPalette::Text,Qt::black);
    ui -> jedMereLE -> setPalette(*palette3);

    ui -> errLabel -> setStyleSheet("QLabel { color : red; }");
    ui -> succLabel -> setStyleSheet("QLabel { color : 	#228B22; }");

    // Podešavanje pozadinske slike
    QPixmap pixmap;
    pixmap.load(":/Resursi/Dialozi/trebovanje.png");

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    on_dugmeUcitajAz_clicked();
}

otpis::~otpis()
{
    delete ui;
}

void otpis::on_nazivSirovineComboBox_currentIndexChanged()
{
    Konekcija b;
    b.dbOpen();

    QString trenutniIndeks = ui -> nazivSirovineComboBox -> currentText();
    QSqlQuery upit;

    upit.prepare("SELECT Jed_Mere, Kolicina FROM gotoviProizvodi WHERE Sifra = :trenutno");
    upit.bindValue(":trenutno", (ui -> nazivSirovineComboBox -> currentIndex()) + 301);

    if( upit.exec() )
    {
        while( upit.next() )
        {
            ui -> lineEdit_kolicina -> setText(upit.value(1).toString());
            ui -> jedMereLE -> setText(upit.value(0).toString());
         }
    }

    b.dbClose();
}

void otpis::on_dugmeUcitajAz_clicked()
{
    Konekcija baza;
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery upit, cbUpit;

    baza.dbOpen();

    upit.exec("SELECT Naziv FROM gotoviProizvodi");
    modal -> setQuery(upit);
    ui -> nazivSirovineComboBox -> setModel(modal);

    baza.dbClose();
}

void otpis::on_trebuj_2_clicked()
{
    this -> close();
}

void otpis::on_otpisi_clicked()
{
    Konekcija baza;
    QSqlQuery upit;
    QString ime, prezime;

    baza.dbOpen();

    ime = ui -> imeLE -> text();
    prezime = ui -> prezimeLE -> text();

    // provera vrednosti
    QString sOtpisa = ui -> sifraOtpisaLE -> text();

    ui -> succLabel -> setText("");

    if( (ui -> sifraOtpisaLE -> text().isEmpty()) ||
            (ui -> imeLE -> text().isEmpty()) || (ui -> prezimeLE -> text().isEmpty())
            || (ui -> lineEdit_kolicina -> text().isEmpty()) )
    {
        ui -> errLabel -> setText("Popunite sva polja!");
    }
    else
    {
        int sifraSirovine = ui -> nazivSirovineComboBox -> currentIndex();
        sifraSirovine += 301;

        upit.prepare("SELECT Kolicina FROM gotoviProizvodi WHERE Sifra = :sifra");
        upit.bindValue(":sifra", sifraSirovine);
        upit.exec();

        upit.first();

        float kolicinaUMagacinu = upit.value(0).toFloat();

        if( (ui -> lineEdit_kolicina -> text().toFloat() ) > kolicinaUMagacinu)
            ui -> errLabel -> setText("Nema dovoljno proizvoda u magacinu za otpis!");
        else if((ui -> lineEdit_kolicina -> text().toFloat()) < 0.0f)
            ui -> errLabel -> setText("Ne možete otpisati negativnu količinu proizvoda!");
        else
        {
            upit.prepare("UPDATE gotoviProizvodi SET Kolicina = :Kolicina WHERE Sifra = :sifra");
            upit.bindValue(":Kolicina", kolicinaUMagacinu - (ui -> lineEdit_kolicina -> text().toFloat()));
            upit.bindValue(":sifra", (ui -> nazivSirovineComboBox -> currentIndex()) + 301);
            upit.exec();

            ui -> errLabel -> setText("");
            ui -> succLabel -> setText("Otpis proizvoda uspešan!");

            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString datum, vreme, Datum, Opis;

            datum = cd.toString();
            vreme = ct.toString();

            Datum = datum + " " + vreme;
            Opis = "Otpisan proizvod: " + ui -> nazivSirovineComboBox -> currentText() + ", otpisana količina: "
                    + ui -> lineEdit_kolicina -> text() + ", jedinica mere: " + ui -> jedMereLE -> text() +
                    "\n" + "Otpisao: " + ui -> imeLE -> text() + " " + ui -> prezimeLE -> text() + ", Šifra otpisa: " + ui -> sifraOtpisaLE -> text();

            QSqlQuery izmena;

            izmena.prepare("INSERT INTO istorijaIzmena(Datum, Opis) VALUES(:Datum, :Opis)");

            izmena.bindValue(":Datum", Datum);
            izmena.bindValue(":Opis", Opis);

            izmena.exec();

            ui -> sifraOtpisaLE -> clear();
            ui -> imeLE -> clear();
            ui -> prezimeLE -> clear();

            on_dugmeUcitajAz_clicked();
        }
    }

    baza.dbClose();
}
