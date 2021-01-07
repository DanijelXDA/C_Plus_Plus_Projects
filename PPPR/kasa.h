#ifndef KASA_H
#define KASA_H

#include <QDialog>

namespace Ui {
class kasa;
}

class kasa : public QDialog
{
    Q_OBJECT

public:
    explicit kasa(QWidget *parent = nullptr);
    ~kasa();
    void refresh();
private slots:
    void on_addp_clicked();

    void on_delp_clicked();

    void on_novaM_clicked();

private:
    Ui::kasa *ui;
};

#endif // KASA_H
