#ifndef TREBOVANJEMAGACIN_H
#define TREBOVANJEMAGACIN_H

#include <QDialog>
#include "konekcija.h"

namespace Ui {
class trebovanjeMagacin;
}

class trebovanjeMagacin : public QDialog
{
    Q_OBJECT

public:
    explicit trebovanjeMagacin(QWidget *parent = nullptr);
    ~trebovanjeMagacin();

private slots:
    void on_dugmeUcitajAz_clicked();
    void on_nazivSirovineComboBox_currentIndexChanged();
    void on_trebuj_2_clicked();
    void on_trebuj_clicked();

private:
    Ui::trebovanjeMagacin *ui;
};

#endif // TREBOVANJEMAGACIN_H
