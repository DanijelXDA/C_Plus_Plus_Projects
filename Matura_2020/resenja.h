#ifndef RESENJA_H
#define RESENJA_H

#include <QDialog>

namespace Ui {
class Resenja;
}

class Resenja : public QDialog
{
    Q_OBJECT

public:
    explicit Resenja(QWidget *parent = nullptr);
    ~Resenja();

private slots:
    void on_magicBtn_clicked();

private:
    Ui::Resenja *ui;
};

#endif // RESENJA_H
