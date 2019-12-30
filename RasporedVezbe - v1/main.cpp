#include "pocetna.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pocetna w;
    w.show();
    return a.exec();
}
