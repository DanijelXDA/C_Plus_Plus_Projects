#include "resenja.h"
#include "ui_resenja.h"

#include <QDir>
#include <QProcess>

Resenja::Resenja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resenja)
{
    ui->setupUi(this);
}

Resenja::~Resenja()
{
    delete ui;
}

void Resenja::on_magicBtn_clicked()
{
//

}
