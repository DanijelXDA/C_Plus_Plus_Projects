#ifndef PROIZVODAZURIRAJ_H
#define PROIZVODAZURIRAJ_H

#include <QDialog>

namespace Ui {
class proizvodAzuriraj;
}

class proizvodAzuriraj : public QDialog
{
    Q_OBJECT

public:
    explicit proizvodAzuriraj(QWidget *parent = nullptr);
    ~proizvodAzuriraj();

private slots:
    void on_comboBoxID_currentIndexChanged();
    void on_azurirajDugme_clicked();
    void on_dugmeUcitajAz_clicked();
    void on_dugmeIzlazAz_clicked();

private:
    Ui::proizvodAzuriraj *ui;
};

#endif // PROIZVODAZURIRAJ_H
