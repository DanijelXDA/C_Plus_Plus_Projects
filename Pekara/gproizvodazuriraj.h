#ifndef GPROIZVODAZURIRAJ_H
#define GPROIZVODAZURIRAJ_H

#include <QDialog>

namespace Ui {
class gProizvodAzuriraj;
}

class gProizvodAzuriraj : public QDialog
{
    Q_OBJECT

public:
    explicit gProizvodAzuriraj(QWidget *parent = nullptr);
    ~gProizvodAzuriraj();

private slots:
    void on_comboBoxID_currentIndexChanged();
    void on_azurirajDugme_clicked();
    void on_dugmeUcitajAz_clicked();
    void on_dugmeIzlazAz_clicked();

private:
    Ui::gProizvodAzuriraj *ui;
};

#endif // GPROIZVODAZURIRAJ_H
