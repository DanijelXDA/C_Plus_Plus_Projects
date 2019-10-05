#include "storage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Storage w;
    w.show();

    return a.exec();
}
