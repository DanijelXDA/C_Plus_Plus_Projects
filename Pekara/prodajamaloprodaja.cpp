#include "prodajamaloprodaja.h"
#include "ui_prodajamaloprodaja.h"

prodajaMaloprodaja::prodajaMaloprodaja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prodajaMaloprodaja)
{
    ui->setupUi(this);
}

prodajaMaloprodaja::~prodajaMaloprodaja()
{
    delete ui;
}
