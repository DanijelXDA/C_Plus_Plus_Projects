#include "pppr.h"
#include "ui_pppr.h"

#include "dodaj_proizvod.h"
#include "kasa.h"
#include "presek_stanja.h"

#include "db/conn.h"

PPPR::PPPR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPR)
{
    ui->setupUi(this);
}

PPPR::~PPPR()
{
    delete ui;
}

void PPPR::on_d2_clicked()
{
    dodaj_proizvod *p = new dodaj_proizvod(this);
    p -> setModal(true);
    p -> show();
}

void PPPR::on_d2_2_clicked()
{
    kasa *p = new kasa(this);
    p -> setModal(true);
    p -> show();
}

void PPPR::on_d2_3_clicked()
{
    presek_stanja *p = new presek_stanja(this);
    p -> setModal(true);
    p -> show();
}
