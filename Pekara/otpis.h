#ifndef OTPIS_H
#define OTPIS_H

#include <QDialog>

namespace Ui {
class otpis;
}

class otpis : public QDialog
{
    Q_OBJECT

public:
    explicit otpis(QWidget *parent = nullptr);
    ~otpis();

private slots:
    void on_dugmeUcitajAz_clicked();
    void on_nazivSirovineComboBox_currentIndexChanged();
    void on_trebuj_2_clicked();
    void on_otpisi_clicked();

private:
    Ui::otpis *ui;
};

#endif // OTPIS_H
