#ifndef KAFA_H
#define KAFA_H

#include <QMainWindow>

namespace Ui {
class kafa;
}

class kafa : public QMainWindow
{
    Q_OBJECT

public:
    explicit kafa(QWidget *parent = nullptr);
    ~kafa();

private slots:
    void on_comboBox_activated(int index);
    void on_checkBoxSlagKrem_clicked();
    void on_checkBoxPrelivCokolada_clicked();
    void on_checkBoxKuglaSladoleda_clicked();
    void on_dodajUListu_clicked();
    void on_zakljuciPorudzbinu_clicked();

private:
    Ui::kafa *ui;
    int ukupno = 0, osnovnaCena = 0;
    bool zakljuceno = false;
};

#endif // KAFA_H
