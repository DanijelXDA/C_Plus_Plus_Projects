#ifndef PRODAJAMALOPRODAJA_H
#define PRODAJAMALOPRODAJA_H

#include <QDialog>

namespace Ui {
class prodajaMaloprodaja;
}

class prodajaMaloprodaja : public QDialog
{
    Q_OBJECT

public:
    explicit prodajaMaloprodaja(QWidget *parent = nullptr);
    ~prodajaMaloprodaja();

private:
    Ui::prodajaMaloprodaja *ui;
};

#endif // PRODAJAMALOPRODAJA_H
