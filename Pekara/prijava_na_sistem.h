#ifndef PRIJAVA_NA_SISTEM_H
#define PRIJAVA_NA_SISTEM_H

#include <QMainWindow>
#include "pocetna.h"

namespace Ui {
class Prijava_Na_Sistem;
}

class Prijava_Na_Sistem : public QMainWindow
{
    Q_OBJECT

public:
    explicit Prijava_Na_Sistem(QWidget *parent = nullptr);
    ~Prijava_Na_Sistem();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::Prijava_Na_Sistem *ui;
};

#endif // PRIJAVA_NA_SISTEM_H
