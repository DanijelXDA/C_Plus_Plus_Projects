#include "kafa.h"
#include "ui_kafa.h"

kafa::kafa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kafa)
{
    ui->setupUi(this);
    ui -> dodajUListu -> setEnabled(false);
}

kafa::~kafa()
{
    delete ui;
}

void kafa::on_comboBox_activated(int index)
{
    if(index == 0)
    {
        osnovnaCena = 0;
        ui -> dodajUListu -> setEnabled(false);
    }
    else
    {
        switch (index)
        {
            case 1: osnovnaCena = 50; break;
            case 2: osnovnaCena = 80; break;
            case 3: osnovnaCena = 100; break;

            default: break;
        }

        if(ui -> checkBoxSlagKrem -> isChecked())
            osnovnaCena += 30;

        if(ui -> checkBoxPrelivCokolada -> isChecked())
            osnovnaCena += 20;

        if(ui -> checkBoxKuglaSladoleda -> isChecked())
            osnovnaCena += 50;

        ui -> dodajUListu -> setEnabled(true);
    }

    ui -> cenaNapitka -> setText(QString::number(osnovnaCena));
}

void kafa::on_checkBoxSlagKrem_clicked()
{
    if(osnovnaCena != 0)
    {
        if(ui -> checkBoxSlagKrem -> isChecked())
            osnovnaCena += 30;
        else
            osnovnaCena -= 30;

        ui -> cenaNapitka -> setText(QString::number(osnovnaCena));
    }
}

void kafa::on_checkBoxPrelivCokolada_clicked()
{
    if(osnovnaCena != 0)
    {
        if(ui -> checkBoxPrelivCokolada -> isChecked())
            osnovnaCena += 20;
        else
            osnovnaCena -= 20;

        ui -> cenaNapitka -> setText(QString::number(osnovnaCena));
    }
}

void kafa::on_checkBoxKuglaSladoleda_clicked()
{
    if(osnovnaCena != 0)
    {
        if(ui -> checkBoxKuglaSladoleda -> isChecked())
            osnovnaCena += 50;
        else
            osnovnaCena -= 50;

        ui -> cenaNapitka -> setText(QString::number(osnovnaCena));
    }
}

void kafa::on_dodajUListu_clicked()
{
    if(zakljuceno)
        ui -> textEdit -> clear();

    zakljuceno = false;

    QString stavka, razmak = "";

    switch (ui -> comboBox -> currentIndex())
    {
        case 1: stavka = "Crna kafa"; break;
        case 2: stavka = "Nes kafa"; break;
        case 3: stavka = "Kapućino"; break;
        default: break;
    }

    if(ui -> checkBoxSlagKrem -> isChecked())
        stavka += ", šlag";

    if(ui -> checkBoxPrelivCokolada -> isChecked())
        stavka += ", preliv";

    if(ui -> checkBoxKuglaSladoleda -> isChecked())
        stavka += ", sladoled";

    if(stavka.size() < 15)
        razmak = "\t\t\t";
    else if(stavka.size() < 30)
        razmak = "\t\t";
    else
        razmak = "\t";

    int cena = ui -> spinBoxKolicina -> value() * ui -> cenaNapitka -> text().toInt();
    ukupno += cena;

    stavka += razmak + ui -> spinBoxKolicina -> text() + " kom.\t" + QString::number(cena);

    ui -> textEdit -> append(stavka);

    ui -> comboBox -> setCurrentIndex(0);
    ui -> checkBoxSlagKrem -> setChecked(false);
    ui -> checkBoxPrelivCokolada -> setChecked(false);
    ui -> checkBoxKuglaSladoleda -> setChecked(false);
    ui -> dodajUListu -> setEnabled(false);
    ui -> spinBoxKolicina -> setValue(1);
    ui -> cenaNapitka -> setText(QString::number(0));
    osnovnaCena = 0;
}

void kafa::on_zakljuciPorudzbinu_clicked()
{
    if(!zakljuceno)
    {
        QString konacno;
        konacno = "\t\tUkupan iznos:\t" + QString::number(ukupno);
        ui -> textEdit -> append("____________________________________________");
        ui -> textEdit -> append(konacno);
        zakljuceno = true;
        ukupno = 0;
        osnovnaCena = 0;
    }
}
