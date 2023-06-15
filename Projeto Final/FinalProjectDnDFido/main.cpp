#include "dnd_encounter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DnD_encounter w;
    w.show();
    return a.exec();
}
