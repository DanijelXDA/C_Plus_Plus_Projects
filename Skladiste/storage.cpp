#include "storage.h"
#include "ui_storage.h"
#include <QMessageBox>

Storage::Storage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
}

Storage::~Storage()
{
    delete ui;
}

void Storage::on_dodaj_clicked()
{
    if(ui -> ime -> text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Popunite polje za Ime!");
        msgBox.exec();

        return;
    }

    if(ui -> prezime -> text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Popunite polje za prezime!");
        msgBox.exec();

        return;
    }

    if(ui -> email -> text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Popunite polje za email!");
        msgBox.exec();

        return;
    }

    QString i, p, e;

    i = ui -> ime -> text();
    p = ui -> prezime -> text();
    e = ui -> email -> text();

    // popuni tabelu podacima
    ui -> podaci -> append("\n" + i + "\t" + p + "\t" + e);
}
