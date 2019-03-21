#ifndef PROIZVODPREGLED_H
#define PROIZVODPREGLED_H

#include <QDialog>

namespace Ui {
class proizvodPregled;
}

class proizvodPregled : public QDialog
{
    Q_OBJECT

public:
    explicit proizvodPregled(QWidget *parent = nullptr);
    ~proizvodPregled();

private slots:
    void on_izlazDugme_clicked();
    void on_pregledDugme_clicked();

private:
    Ui::proizvodPregled *ui;
};

#endif // PROIZVODPREGLED_H
