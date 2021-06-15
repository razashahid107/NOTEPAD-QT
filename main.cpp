#include "initialscr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Initialscr w;
    w.show();
    return a.exec();
}
