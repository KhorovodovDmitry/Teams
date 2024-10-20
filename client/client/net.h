#ifndef NET_H
#define NET_H

#include <QObject>
#include <QTcpSocket>
#include <QMap>
#include <QString>

class Net;

class NetDestroyer {
private:
    Net* pInstance = nullptr;

public:
    ~NetDestroyer() {
        delete pInstance;
    }

    void initialize(Net* p) {
        pInstance = p;
    }
};

/*!
 * \brief Синглтон-класс для работы с сетью
 */
class Net : public QObject {
    Q_OBJECT

private:
    static Net* pInstance;
    static QTcpSocket* tcpInstance;
    static NetDestroyer destroyer;

    Net();
    ~Net();

    void initTCP();

    // Запрещаем копирование и присваивание
    Net(const Net&) = delete;
    Net& operator=(const Net&) = delete;

    friend class NetDestroyer;

public:
    /*!
     * \brief Получение единственного экземпляра класса
     * \return Указатель на экземпляр класса Net
     */
    static Net* getInstance() {
        if (!pInstance) {
            pInstance = new Net();
            destroyer.initialize(pInstance);
        }
        return pInstance;
    }

    /*!
     * \brief Выполнение запроса
     * \param[in] request Передаваемые данные в виде QMap<QString, QString>
     * \return Ответ сервера в виде QMap<QString, QString>
     */
    QString doRequest(const QByteArray& request);
};

#endif // NET_H
