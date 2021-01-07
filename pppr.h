#ifndef PPPR_H
#define PPPR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PPPR; }
QT_END_NAMESPACE

class PPPR : public QMainWindow
{
    Q_OBJECT

public:
    PPPR(QWidget *parent = nullptr);
    ~PPPR();

private slots:
    void on_d2_clicked();
    void on_d2_2_clicked();
    void on_d2_3_clicked();

private:
    Ui::PPPR *ui;
};
#endif // PPPR_H
