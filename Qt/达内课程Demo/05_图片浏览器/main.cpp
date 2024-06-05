#include "ShowImageDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowImageDialog w;
    w.show();
    return a.exec();
}
