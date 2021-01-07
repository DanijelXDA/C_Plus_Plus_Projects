#include "kasa.h"
#include "ui_kasa.h"

#include "db/conn.h"

#include <QMessageBox>
#include <QDebug>

kasa::kasa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kasa)
{
    ui->setupUi(this);
    refresh();
}

kasa::~kasa()
{
    delete ui;
}

void kasa::refresh()
{
        Konekcija baza;

        // QSqlQueryModel *modal = new QSqlQueryModel();
        baza.dbOpen();
        QSqlQuery query;

        query.exec("SELECT sifra, naziv, cena FROM proizvod ORDER BY sifra ASC");
        /*
         * modal->setQuery(upit);
        ui -> listing -> setModel(modal);
*/
        query.first(); // ne prikzuje prvi item!!!
            while(query.next()) {
                int sifra = query.record().indexOf("sifra");
                int naziv = query.record().indexOf("naziv");
                int cena = query.record().indexOf("cena");
                QString a = query.value(sifra).toString();
                QString b = query.value(naziv).toString();
                QString c = query.value(cena).toString();

                QString n = a + " - " + b + " - " + c;
                ui->listing->addItem(n);
                qDebug() << n;
            }
        baza.dbClose();
}

void kasa::on_addp_clicked()
{
    if(ui -> kolicina -> text().isEmpty())
    {
        QMessageBox::warning(this, "Obaveštenje", "Popunite sva polja!");
        return;
    }
    else
    {
        Konekcija baza;
        // QSqlQueryModel *modal = new QSqlQueryModel();
        baza.dbOpen();
        QSqlQuery query;

        // get sifra
        int indeks = ui -> listing -> currentIndex(); indeks++;
        query.exec("SELECT sifra, naziv, cena FROM proizvod where sifra=" + QString::number(indeks));
        query.first();

        int sifra = query.record().indexOf("sifra");
        int naziv = query.record().indexOf("naziv");
        int cena = query.record().indexOf("cena");
        QString a = query.value(sifra).toString();
        QString b = query.value(naziv).toString();
        QString c = query.value(cena).toString();
        QString d = ui -> kolicina -> text();

        query.prepare("INSERT INTO temp values(:p1, :p2, :p3, :p4, :p5)");
        query.bindValue(":p1", a.toInt());
        query.bindValue(":p2", b);
        query.bindValue(":p3", c.toInt());
        query.bindValue(":p4", d.toInt());
        query.bindValue(":p5", (d.toInt() * c.toInt()));
        query.exec();

        // prikaz temp
        QSqlQueryModel *modal = new QSqlQueryModel();
        query.exec("SELECT naziv as NAZIV, cena as CENA, kolicina as KOLICINA, sum(cena*kolicina) as UKUPNO FROM temp GROUP by sifra");
        modal -> setQuery(query);
        ui -> prikaz -> setModel(modal);

        QString cenaUkupna;
        query.exec("SELECT sum(suma) FROM temp");
        query.first();
        cenaUkupna = query.value(0).toString();
        ui -> znp -> setText(cenaUkupna + " RSD");
// test case
        QItemSelectionModel *select = ui->prikaz->selectionModel();
        qDebug()<<select->selectedRows(0).value(0).data().toString();
        qDebug()<<select->selectedRows(1).value(0).data().toString();
        qDebug()<<select->selectedRows(2).value(0).data().toString();
        qDebug()<<select->selectedRows(3).value(0).data().toString();

        baza.dbClose();
    }
}

void kasa::on_delp_clicked()
{
    Konekcija baza;
    // QSqlQueryModel *modal = new QSqlQueryModel();
    baza.dbOpen();
    QSqlQuery query;

    // get sifra
    int indeks = ui -> listing -> currentIndex(); indeks++;
    query.exec("DELETE FROM temp where sifra=" + QString::number(indeks));

    // prikaz temp
    QSqlQueryModel *modal = new QSqlQueryModel();
    query.exec("SELECT naziv as NAZIV, cena as CENA, kolicina as KOLICINA, sum(cena*kolicina) as UKUPNO FROM temp GROUP by sifra");
    modal -> setQuery(query);
    ui -> prikaz -> setModel(modal);

    QString cenaUkupna;
    query.exec("SELECT sum(suma) FROM temp");
    query.first();
    cenaUkupna = query.value(0).toString();
    ui -> znp -> setText(cenaUkupna + " RSD");

    baza.dbClose();
}

void kasa::on_novaM_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Prelazak na novu mušteriju?", "Da li ste sigurni da ste završili sa trenutnom mušterijom?",
                                    QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        Konekcija baza;
        baza.dbOpen();
        QSqlQuery query;

        // azuriraj u proizvodima samo prodatu kolicinu


        // obrisi temp
        query.exec("DELETE FROM temp where 1");
        // prikaz temp
        QSqlQueryModel *modal = new QSqlQueryModel();
        query.exec("SELECT naziv as NAZIV, cena as CENA, kolicina as KOLICINA, sum(cena*kolicina) as UKUPNO FROM temp GROUP by sifra");
        modal -> setQuery(query);
        ui -> prikaz -> setModel(modal);

        ui -> znp -> setText("0 RSD");
        ui -> listing -> setCurrentIndex(0);
        ui -> kolicina -> clear();

        baza.dbClose();
    }
    else
        return;
}
