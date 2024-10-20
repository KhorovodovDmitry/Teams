#ifndef SINGLETON_CLIENT_H
#define SINGLETON_CLIENT_H


#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Singleton_client;


class Singleton_clientDestroyer
{
private:
    Singleton_client* pInstance;
public:
    ~Singleton_clientDestroyer() {
        delete this->pInstance;
    }
    void initialize(Singleton_client * p) {
        this->pInstance = p;
    }
};

class Singleton_client: public QObject {
private:
    static Singleton_client* pInstance;
    void initTCP();
    static QTcpSocket* tcpInstance;
    static Singleton_clientDestroyer destroyer;
protected:
    Singleton_client();
    Singleton_client(const Singleton_client&) = delete;
    Singleton_client& operator = (Singleton_client &) = delete;
    ~Singleton_client();
    friend class Singleton_clientDestroyer;
public:
    static Singleton_client* getInstance() {
        if (!pInstance) {
            pInstance = new Singleton_client();
            destroyer.initialize(pInstance);
        }
        return pInstance;
    }
    QString doRequest(QByteArray request);

};

#endif // Singleton_client_H
