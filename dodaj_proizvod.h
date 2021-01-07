#ifndef DODAJ_PROIZVOD_H
#define DODAJ_PROIZVOD_H

#include <QDialog>

namespace Ui {
class dodaj_proizvod;
}

class dodaj_proizvod : public QDialog
{
    Q_OBJECT

public:
    explicit dodaj_proizvod(QWidget *parent = nullptr);
    ~dodaj_proizvod();

private slots:
    void on_close_clicked();
    void on_addp_clicked();

private:
    Ui::dodaj_proizvod *ui;
};

#endif // DODAJ_PROIZVOD_H
