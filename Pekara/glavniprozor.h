#ifndef GLAVNIPROZOR_H
#define GLAVNIPROZOR_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class GlavniProzor;
}

class GlavniProzor : public QMainWindow
{
    Q_OBJECT

public:
    explicit GlavniProzor(QWidget *parent = nullptr);
    ~GlavniProzor();

private slots:
    // magacin sirovina
    void on_actionDodaj_u_magacin_triggered();
    void on_azuriranjeMagacin_triggered();
    void on_pregledMagacina_triggered();
    void on_trebovanjeMagacin_triggered();

    // magacin proizvoda
    void on_actionProizvodDodaj_triggered();
    void on_actionProizvodUkloni_triggered();
    void on_actionAzurirajProizvod_triggered();
    void on_actionPregledProizvod_triggered();

    // istorija izmena
    void on_istorijaIzmenaMagacin_triggered();


    // magacin gotovih proizvoda
    void on_DodajGProizvod_triggered();
    void on_azurirajGProizvod_triggered();
    void on_ukloniGProizvod_triggered();
    void on_gProizvodPregled_triggered();

    // Maloprodaja
    void on_trebovanjeGProizvoda_triggered();
    void on_otpisProizvoda_triggered();
    void on_actionProdaja_triggered();
    void on_izborProdavca_triggered();

    // Pomoc
    void on_actionIzlaz_triggered();
    void on_actionOaplikaciji_triggered();

    // ciscenje
    void on_isprazniMagacin_triggered();
    void on_isprazniProizvode_triggered();
    void on_isprazniGotoveProizvode_triggered();


private:
    Ui::GlavniProzor *ui;
};

#endif // GLAVNIPROZOR_H
