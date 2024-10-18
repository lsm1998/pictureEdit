#include "pictureedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PictureEdit w;
    w.show();

    return QApplication::exec();
}
