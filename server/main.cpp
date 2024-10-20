#include <QCoreApplication>
#include "mytcpserver.h"
#include "databaseservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Database * database = Database::getInstance(); //получение объекта класса database
    MyTcpServer server;
    return a.exec();
}
