#ifndef PROIZVODUKLONI_H
#define PROIZVODUKLONI_H

#include <QDialog>

namespace Ui {
class proizvodukloni;
}

class proizvodukloni : public QDialog
{
    Q_OBJECT

public:
    explicit proizvodukloni(QWidget *parent = nullptr);
    ~proizvodukloni();

private slots:
    void on_dugmeIzlazAz_clicked();
    void on_ukloniDugme_clicked();
    void on_comboBoxID_currentIndexChanged();
    void on_dugmeUcitajAz_clicked();

private:
    Ui::proizvodukloni *ui;
};

#endif // PROIZVODUKLONI_H
