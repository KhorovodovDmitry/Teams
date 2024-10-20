#include "net.h"

// Инициализация статических членов класса
Net* Net::pInstance = nullptr;
QTcpSocket* Net::tcpInstance = nullptr;
NetDestroyer Net::destroyer;

Net::Net() {
    initTCP();
}

Net::~Net() {
    if (tcpInstance) {
        tcpInstance->close();
        delete tcpInstance;
        tcpInstance = nullptr;
    }
}

void Net::initTCP() {
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

QString Net::doRequest(const QByteArray& request) {
    this->tcpInstance->write(request);
    this->tcpInstance->waitForBytesWritten(1000);
    this->tcpInstance->waitForReadyRead(2000);
    QByteArray response = this->tcpInstance->readAll();
    return QString::fromUtf8(response);
}
