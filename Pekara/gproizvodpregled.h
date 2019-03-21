#ifndef GPROIZVODPREGLED_H
#define GPROIZVODPREGLED_H

#include <QDialog>

namespace Ui {
class gProizvodPregled;
}

class gProizvodPregled : public QDialog
{
    Q_OBJECT

public:
    explicit gProizvodPregled(QWidget *parent = nullptr);
    ~gProizvodPregled();

private slots:
    void on_izlazDugme_clicked();
    void on_pregledDugme_clicked();

private:
    Ui::gProizvodPregled *ui;
};

#endif // GPROIZVODPREGLED_H
