#ifndef POCETNA_H
#define POCETNA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Pocetna; }
QT_END_NAMESPACE

class Pocetna : public QMainWindow
{
    Q_OBJECT

public:
    Pocetna(QWidget *parent = nullptr);
    ~Pocetna();

private slots:
    void on_pushButton_clicked();
    void on_upisUBazu_clicked();
    void on_prikaziRaspored_clicked();
    void on_generisanjeBtn_clicked();
    void on_deleteSpisakBtn_clicked();
    void on_deleteRasporedBtn_clicked();

private:
    Ui::Pocetna *ui;
};
#endif // POCETNA_H
