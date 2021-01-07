#include "presek_stanja.h"
#include "ui_presek_stanja.h"

presek_stanja::presek_stanja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::presek_stanja)
{
    ui->setupUi(this);
    //refresh();
    prikaz();
}

presek_stanja::~presek_stanja()
{
    delete ui;
}
/*
void presek_stanja::refresh()
{
        Konekcija baza;
        baza.dbOpen();
        QSqlQuery query;

        if(query.exec("SELECT sifra, naziv, cena FROM proizvod") )
        {
            query.first();
            while(query.next()){
                int sifra = query.record().indexOf("sifra");
                int naziv = query.record().indexOf("naziv");
                int cena = query.record().indexOf("cena");
                QString a = query.value(sifra).toString();
                QString b = query.value(naziv).toString();
                QString c = query.value(cena).toString();

                QString n = a + " - " + b + " - " + c;
                ui -> listing -> addItem(n);
            }
        }
        if(query.exec("SELECT sum(cena*prodato) as ukupno FROM proizvod"))
        {
            query.first();
            ui -> znp -> setText(query.value(0).toString() + " RSD");
        }
        baza.dbClose();
} */

void presek_stanja::prikaz()
{
    Konekcija baza;
       QSqlQueryModel *modal = new QSqlQueryModel();

       baza.dbOpen();

       QSqlQuery upit;

       upit.exec("SELECT naziv as NAZIV, cena as CENA, prodato as PRODATO, stanje as STANJE, sum(cena*prodato) as UKUPNO FROM proizvod GROUP by sifra");
       modal->setQuery(upit);

       ui -> prikaz -> setModel(modal);

       if(upit.exec("SELECT sum(cena*prodato) as ukupno FROM proizvod"))
       {
           upit.first();
           if(upit.value(0).toString().isEmpty())
                ui -> znp -> setText("0 RSD");
           else
                ui -> znp -> setText(upit.value(0).toString() + " RSD");
       }
       baza.dbClose();
}
