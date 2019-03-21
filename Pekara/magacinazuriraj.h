#ifndef MAGACINAZURIRAJ_H
#define MAGACINAZURIRAJ_H

#include <QDialog>

namespace Ui {
class magacinAzuriraj;
}

class magacinAzuriraj : public QDialog
{
    Q_OBJECT

public:
    explicit magacinAzuriraj(QWidget *parent = nullptr);
    ~magacinAzuriraj();

private slots:
    void on_comboBoxID_currentIndexChanged();
    void on_azurirajDugme_clicked();
    void on_dugmeUcitajAz_clicked();
    void on_dugmeIzlazAz_clicked();

private:
    Ui::magacinAzuriraj *ui;
};

#endif // MAGACINAZURIRAJ_H
