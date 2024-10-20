#include "mytcpserver.h"


MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "Server is not started";
    }
    else
    {
        server_status = 1;
        qDebug() << "Server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    if (server_status == 1)
    {
        QTcpSocket *curr_mTcpSocket = mTcpServer->nextPendingConnection();
        if (curr_mTcpSocket)
        {
            qDebug() << "New connection established:" << curr_mTcpSocket->socketDescriptor();
            curr_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
            connect(curr_mTcpSocket, &QTcpSocket::readyRead,
                    this, &MyTcpServer::slotServerRead);
            connect(curr_mTcpSocket, &QTcpSocket::disconnected,
                    this, &MyTcpServer::slotClientDisconnected);
            mTcpSocket[curr_mTcpSocket->socketDescriptor()] = curr_mTcpSocket;
        }
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    if (curr_mTcpSocket)
    {
        QString request = "";
        while (curr_mTcpSocket->bytesAvailable() > 0)
        {
            request.append(curr_mTcpSocket->readAll());
        }

        QByteArray response = parse(request);
        curr_mTcpSocket->write(response);
    }

}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *disconnectedSocket = qobject_cast<QTcpSocket*>(sender());
    if (disconnectedSocket)
    {
        int socketDescriptor = disconnectedSocket->socketDescriptor();
        qDebug() << "Client disconnected:" << socketDescriptor;
        mTcpSocket.remove(socketDescriptor);
        disconnectedSocket->deleteLater();
    }
}
