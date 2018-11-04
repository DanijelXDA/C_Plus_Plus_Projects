#include "prijava_na_sistem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Prijava_Na_Sistem w;
    w.show();

    return a.exec();
}
