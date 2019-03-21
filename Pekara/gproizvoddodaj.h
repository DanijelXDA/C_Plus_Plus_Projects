#ifndef GPROIZVODDODAJ_H
#define GPROIZVODDODAJ_H

#include <QDialog>

namespace Ui {
class gProizvodDodaj;
}

class gProizvodDodaj : public QDialog
{
    Q_OBJECT

public:
    explicit gProizvodDodaj(QWidget *parent = nullptr);
    ~gProizvodDodaj();

private slots:
    void on_dodajDugme_clicked();
    void on_izlazDugme_clicked();

private:
    Ui::gProizvodDodaj *ui;
};

#endif // GPROIZVODDODAJ_H
