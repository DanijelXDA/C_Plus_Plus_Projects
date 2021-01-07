#ifndef PRESEK_STANJA_H
#define PRESEK_STANJA_H

#include <QDialog>
#include "db/conn.h"

namespace Ui {
class presek_stanja;
}

class presek_stanja : public QDialog
{
    Q_OBJECT

public:
    explicit presek_stanja(QWidget *parent = nullptr);
    ~presek_stanja();
    //void refresh();
    void prikaz();

private:
    Ui::presek_stanja *ui;
};

#endif // PRESEK_STANJA_H
