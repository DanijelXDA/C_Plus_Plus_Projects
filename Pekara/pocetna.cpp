#include "pocetna.h"
#include "ui_pocetna.h"

Pocetna::Pocetna(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pocetna)
{
    ui->setupUi(this);
}

Pocetna::~Pocetna()
{
    delete ui;
}

void Pocetna::on_actionZatvori_prozor_triggered()
{
    close(); // Zatvori prozor
}

void Pocetna::on_actionVerzija_triggered()
{
    // DO NOTHING
}

void Pocetna::on_actionVerzija_2_triggered()
{
    // DO NOTHING
}
