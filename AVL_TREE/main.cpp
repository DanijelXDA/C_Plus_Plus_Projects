#include "avl_tree.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AVL_TREE w;
    w.show();
    return a.exec();
}
