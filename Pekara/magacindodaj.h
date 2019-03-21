#ifndef MAGACINDODAJ_H
#define MAGACINDODAJ_H

#include <QDialog>

namespace Ui {
class magacinDodaj;
}

class magacinDodaj : public QDialog
{
    Q_OBJECT

public:
    explicit magacinDodaj(QWidget *parent = nullptr);
    ~magacinDodaj();

private slots:
    void on_dodajDugme_clicked();
    void on_izlazDugme_clicked();

private:
    Ui::magacinDodaj *ui;
};

#endif // MAGACINDODAJ_H
