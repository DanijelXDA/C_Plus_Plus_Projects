#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <QMainWindow>
#include <QMessageBox>

typedef struct stablo_st
{
    float broj;
    int dubina;
    struct stablo_st *levi;
    struct stablo_st *desni;
} STABLO;

QT_BEGIN_NAMESPACE
namespace Ui { class AVL_TREE; }
QT_END_NAMESPACE

class AVL_TREE : public QMainWindow
{
    Q_OBJECT

public:
    AVL_TREE(QWidget *parent = nullptr);
    ~AVL_TREE();
    friend void prikaz_podatka(STABLO *s);

private slots:
    void on_dodajbtn_clicked();
    void on_about_clicked();
    void on_darkT_clicked();

private:
    Ui::AVL_TREE *ui;

public:
    Ui::AVL_TREE *uiCpy = ui;
};
#endif // AVL_TREE_H
