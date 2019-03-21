#include "izborprodavca.h"
#include "ui_izborprodavca.h"

izborProdavca::izborProdavca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izborProdavca)
{
    ui->setupUi(this);
}

izborProdavca::~izborProdavca()
{
    delete ui;
}
