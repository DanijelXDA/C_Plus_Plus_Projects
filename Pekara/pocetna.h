#ifndef POCETNA_H
#define POCETNA_H

#include <QMainWindow>

namespace Ui {
class Pocetna;
}

class Pocetna : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pocetna(QWidget *parent = nullptr);
    ~Pocetna();

private slots:
    void on_actionVerzija_triggered();

    void on_actionZatvori_prozor_triggered();

    void on_actionVerzija_2_triggered();

private:
    Ui::Pocetna *ui;
    Pocetna *pocetna; // forward declaration required otherwise this is an error
};

#endif // POCETNA_H
