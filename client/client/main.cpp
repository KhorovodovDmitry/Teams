#include "authregform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    AuthRegForm w;
    w.show();
    return a.exec();
}
