#ifndef IZBORPRODAVCA_H
#define IZBORPRODAVCA_H

#include <QDialog>

namespace Ui {
class izborProdavca;
}

class izborProdavca : public QDialog
{
    Q_OBJECT

public:
    explicit izborProdavca(QWidget *parent = nullptr);
    ~izborProdavca();

private:
    Ui::izborProdavca *ui;
};

#endif // IZBORPRODAVCA_H
