#ifndef PROIZVODDODAJ_H
#define PROIZVODDODAJ_H

#include <QDialog>

namespace Ui {
class proizvodDodaj;
}

class proizvodDodaj : public QDialog
{
    Q_OBJECT

public:
    explicit proizvodDodaj(QWidget *parent = nullptr);
    ~proizvodDodaj();

private slots:
    void on_dodajDugme_clicked();
    void on_izlazDugme_clicked();

private:
    Ui::proizvodDodaj *ui;
};

#endif // PROIZVODDODAJ_H
