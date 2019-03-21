#ifndef GPROIZVODUKLONI_H
#define GPROIZVODUKLONI_H

#include <QDialog>

namespace Ui {
class gProizvodUkloni;
}

class gProizvodUkloni : public QDialog
{
    Q_OBJECT

public:
    explicit gProizvodUkloni(QWidget *parent = nullptr);
    ~gProizvodUkloni();

private slots:
    void on_dugmeIzlazAz_clicked();
    void on_ukloniDugme_clicked();
    void on_comboBoxID_currentIndexChanged();
    void on_dugmeUcitajAz_clicked();

private:
    Ui::gProizvodUkloni *ui;
};

#endif // GPROIZVODUKLONI_H
