#ifndef TREBOVANJEGPROIZVOD_H
#define TREBOVANJEGPROIZVOD_H

#include <QDialog>

namespace Ui {
class trebovanjeGProizvod;
}

class trebovanjeGProizvod : public QDialog
{
    Q_OBJECT

public:
    explicit trebovanjeGProizvod(QWidget *parent = nullptr);
    ~trebovanjeGProizvod();

private slots:
    void on_dugmeUcitajAz_clicked();
    void on_nazivSirovineComboBox_currentIndexChanged();
    void on_trebuj_2_clicked();
    void on_trebuj_clicked();

private:
    Ui::trebovanjeGProizvod *ui;
};

#endif // TREBOVANJEGPROIZVOD_H
