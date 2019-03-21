#ifndef ISTORIJAIZMENAMAGACIN_H
#define ISTORIJAIZMENAMAGACIN_H

#include <QDialog>

namespace Ui {
class istorijaIzmenaMagacin;
}

class istorijaIzmenaMagacin : public QDialog
{
    Q_OBJECT

public:
    explicit istorijaIzmenaMagacin(QWidget *parent = nullptr);
    ~istorijaIzmenaMagacin();

private slots:
    void on_izlazDugme_clicked();
    void on_pregledDugme_clicked();

private:
    Ui::istorijaIzmenaMagacin *ui;
};

#endif // ISTORIJAIZMENAMAGACIN_H
