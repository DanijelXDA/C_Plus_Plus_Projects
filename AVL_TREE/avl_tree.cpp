#include "avl_tree.h"
#include "ui_avl_tree.h"

AVL_TREE::AVL_TREE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AVL_TREE)
{
    ui->setupUi(this);
}

AVL_TREE::~AVL_TREE()
{
    delete ui;
}

// binary tree implementation
#include <stdlib.h>
#include <stdio.h>

void init_stablo(STABLO **koren) { *koren = NULL; }

STABLO *kreiraj_element(const float broj)
{
    STABLO *novi = (STABLO *) malloc(sizeof(STABLO));
    if(novi == NULL)
    {
        exit(40);
    }
    novi -> broj = broj;
    novi -> dubina = 1;
    novi -> levi = NULL;
    novi -> desni = NULL;

    return novi;
}

void dodaj_u_stablo(STABLO *novi, STABLO **koren)
{
    if(*koren == NULL) {
        (*koren) = novi;
        return;
    }
    else if(novi -> broj < (*koren) -> broj) {
        dodaj_u_stablo(novi, &((*koren) -> levi));
        return;
    }
    else {
        dodaj_u_stablo(novi, &((*koren) -> desni));
        return;
    }
}

char tmp[10];

void prikaz_podatka(STABLO *s)
{
    sprintf(tmp, "% .2f   ", s -> broj);
}

void prikaz_stabla(STABLO *koren)
{
    if(koren == NULL)
        return;
    else
    {
        prikaz_stabla(koren -> levi);
        prikaz_podatka(koren);
        prikaz_stabla(koren -> desni);
    }
}

void brisanje_stabla(STABLO **koren)
{
    if(*koren == NULL)
        return;

    brisanje_stabla(&((*koren) -> levi));
    brisanje_stabla(&((*koren) -> desni));

    free((*koren));
    (*koren) = NULL;
}

int dubina_levog_podstabla(STABLO *cvor)
{
    if(cvor == NULL)
        return 0;
    else
        return dubina_levog_podstabla(cvor -> levi) + 1;
}

int dubina_desnog_podstabla(STABLO *cvor)
{
    if(cvor == NULL)
        return 0;
    else
        return dubina_desnog_podstabla(cvor -> desni) + 1;
}

void print_tree(const unsigned l, const unsigned r, const char *situation)
{
    printf("\n\n\t\t\t\t%s balansiranja stabla", situation);
    printf("\n\tDubina levog podstabla:  % d", l);
    printf("\n\tDubina desnog podstabla: % d", r);
    printf("\n\tRazlika izmedju visine levog podstabla i desnog podstabla: % d\n", l - r);
}

// AVL PART
int veci(const int x, const int y)
{
    return (x > y) ? x : y;
}

int dubinaStabla(const STABLO *cvor)
{
    if(cvor == NULL)
        return 0;
    else
        return cvor -> dubina;
}

int balansirano(STABLO *cvor)
{
    if(cvor == NULL)
        return 0;
    else
        return dubinaStabla(cvor -> levi) - dubinaStabla(cvor -> desni);
}

STABLO *desnaRotacija(STABLO *cvor)
{
    STABLO *tmp = cvor -> levi;
    STABLO *p_tree = cvor -> levi -> desni;

    tmp -> desni = cvor;
    cvor -> levi = p_tree;

    int d_levo = dubinaStabla(cvor -> levi), d_desno = dubinaStabla(cvor -> desni);
    int tmp_d_levo = dubinaStabla(tmp -> levi), tmp_d_desno = dubinaStabla(tmp -> desni);

    cvor -> dubina = veci(d_levo, d_desno)         + 1;
    tmp  -> dubina = veci(tmp_d_levo, tmp_d_desno) + 1;

    return tmp;
}

STABLO *levaRotacija(STABLO *cvor)
{
    STABLO *tmp = cvor -> desni;
    STABLO *p_tree = cvor -> desni -> levi;

    tmp -> levi = cvor;
    cvor -> desni = p_tree;

    int d_levo = dubinaStabla(cvor -> levi), d_desno = dubinaStabla(cvor -> desni);
    int tmp_d_levo = dubinaStabla(tmp -> levi), tmp_d_desno = dubinaStabla(tmp -> desni);

    cvor -> dubina = veci(d_levo, d_desno)         + 1;
    tmp  -> dubina = veci(tmp_d_levo, tmp_d_desno) + 1;

    return tmp;
}

/***
* Reimplementation of
* binary_tree/binary_tree.c ->
* void dodaj_u_stablo(STABLO *, STABLO **)
***/
STABLO *AVL_dodaj_u_stablo(STABLO *cvor, float broj)
{
    if(cvor == NULL)
        return kreiraj_element(broj);

    if(broj < cvor -> broj)
        cvor -> levi = AVL_dodaj_u_stablo(cvor -> levi, broj);
    else if (broj > cvor -> broj)
        cvor -> desni = AVL_dodaj_u_stablo(cvor -> desni, broj);
    else
        return cvor;

    cvor -> dubina = veci(dubinaStabla(cvor -> levi), dubinaStabla(cvor -> desni)) + 1;
    int blc = balansirano(cvor);

    if(blc > 1 && broj < cvor -> levi -> broj)
        return desnaRotacija(cvor);

    if(blc < -1 && broj > cvor -> desni -> broj)
        return levaRotacija(cvor);

    if(blc > 1 && broj > cvor -> levi -> broj) {
       cvor -> levi = levaRotacija(cvor -> levi);
       return desnaRotacija(cvor);
    }

    if(blc < -1 && broj < cvor -> desni -> broj) {
       cvor -> desni = desnaRotacija(cvor -> desni);
       return levaRotacija(cvor);
    }

    return cvor;
}

/*** NIJE NAJPAMETNIJE, BUT IT'LL WORK **/
STABLO *root = NULL;

void AVL_TREE::on_dodajbtn_clicked()
{
    if(ui -> inpt -> text().isEmpty())
    {
        QMessageBox::critical(this, "Упозорење!", "Нисте унели податак за унос у стабло!");
        return;
    }
    else
    {
        float broj = ui -> inpt -> text().toFloat();
        dodaj_u_stablo(kreiraj_element(broj), &root);
        ui -> inpt -> clear();
        QMessageBox::information(this, "Обавештење", "Унели сте податак у стабло!");
        prikaz_stabla(root);
    }
}

void AVL_TREE::on_about_clicked()
{
    //
}

void AVL_TREE::on_darkT_clicked()
{
    if(ui -> darkT -> isChecked())
    {
        ui -> gb -> setStyleSheet("#gb { background-color: #1f1b24; border: 1px solid #1f1b24; border-radius: 25px; }");
        ui -> darkT -> setStyleSheet("background: #fff; color: #000; border: 2px solid #fff; border-radius: 5px; padding-left: 5px;");
        ui -> cw -> setStyleSheet("#cw{border-image: url(:/resursi/poz-dark.jpg) ;}");
    }
    else
    {
        ui -> gb -> setStyleSheet("#gb { background-color: #fff; border: 1px solid #fff; border-radius: 25px; }");
        ui -> darkT -> setStyleSheet("border: 2px solid #20B2AA; border-radius: 5px; padding-left: 5px; color: #000;");
        ui -> cw -> setStyleSheet("#cw{border-image: url(:/resursi/poz.jpg) ;}");
    }
}
