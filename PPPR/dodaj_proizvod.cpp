#include "dodaj_proizvod.h"
#include "ui_dodaj_proizvod.h"
#include <QMessageBox>
#include "db/conn.h"

dodaj_proizvod::dodaj_proizvod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodaj_proizvod)
{
    ui->setupUi(this);

    Konekcija k;
    k.dbOpen();

    QSqlQuery q;
    if(q.exec("SELECT sifra FROM proizvod ORDER BY sifra DESC LIMIT 1"))
    {
        q.first();
        int br = q.value(0).toInt();
        br++;
        QString qs = QString::number(br);

        if(!qs.isEmpty())
            ui -> i1 -> setText(qs);
    }
    ui -> i1 -> setDisabled(true);
    k.dbClose();
}

dodaj_proizvod::~dodaj_proizvod()
{
    delete ui;
}

void dodaj_proizvod::on_close_clicked()
{
    this -> close();
}

void dodaj_proizvod::on_addp_clicked()
{
    Konekcija k;
    k.dbOpen();

    QSqlQuery q;
    QString i2, i3, i4;
    i2 = ui -> i2 -> text();
    i3 = ui -> i3 -> text();
    i4 = ui -> i4 -> text();

    if(i2.isEmpty() || i3.isEmpty() || i4.isEmpty())
    {
        QMessageBox::information(this, "Obaveštenje", "Popunite sva polja!");
        return;
    }
    else
    {
        q.prepare("INSERT INTO PROIZVOD VALUES(:p1, :p2, :p3, 0, :p4)");
        q.bindValue(":p1", ui -> i1 -> text());
        q.bindValue(":p2", i2);
        q.bindValue(":p3", i3);
        q.bindValue(":p4", i4);

        if(q.exec())
        {
            QMessageBox::information(this, "Obaveštenje", "Proizvod dodat u šifarnik!");
            ui -> i2 -> clear();
            ui -> i3 -> clear();
            ui -> i4 -> clear();
            int br = ui -> i1 -> text().toInt();
            br++;
            QString qs = QString::number(br);
            ui -> i1 -> setText(qs);
            return;
        }
        else
        {
            QMessageBox::warning(this, "Upozorenje", "Greška u dodavanju!");
            return;
        }
    }

    k.dbClose();
}
