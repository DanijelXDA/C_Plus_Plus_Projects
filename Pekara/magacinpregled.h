#ifndef MAGACINPREGLED_H
#define MAGACINPREGLED_H

#include <QDialog>

namespace Ui {
class magacinPregled;
}

class magacinPregled : public QDialog
{
    Q_OBJECT

public:
    explicit magacinPregled(QWidget *parent = nullptr);
    ~magacinPregled();

private slots:
    void on_izlazDugme_clicked();

    void on_pregledDugme_clicked();

private:
    Ui::magacinPregled *ui;
};

#endif // MAGACINPREGLED_H
