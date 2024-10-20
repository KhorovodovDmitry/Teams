#include "singleton_client.h"
#include "QMessageBox"
#include <QCoreApplication>

Singleton_client::Singleton_client()
{
    this->initTCP();
}

Singleton_client::~Singleton_client()
{
    this->tcpInstance->close();
}

void Singleton_client::initTCP() {
    this->tcpInstance = new QTcpSocket(this);
    this->tcpInstance->connectToHost("127.0.0.1", 33333);
    if (this->tcpInstance->waitForConnected(1000)) {
        qDebug() << "Connected!";
        tcpInstance->waitForReadyRead(1000);
        this->tcpInstance->readAll();
    }
    else {
        qDebug() << "no Connected!";
    }
}


QString Singleton_client::doRequest(QByteArray request) {
    this->tcpInstance->write(request);
    this->tcpInstance->waitForBytesWritten(1000);
    this->tcpInstance->waitForReadyRead(2000);
    QByteArray response = this->tcpInstance->readAll();
    return QString::fromUtf8(response);
}

Singleton_client *Singleton_client::pInstance = nullptr;
QTcpSocket *Singleton_client::tcpInstance;
Singleton_clientDestroyer Singleton_client::destroyer;

