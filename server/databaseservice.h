#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

class Database;

class DatabaseDestroyer
{
private:
    Database * p_instance;
public:
    ~DatabaseDestroyer();
    void initialize(Database * p){p_instance = p;}
};

class Database : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    static Database * p_instance;
    static DatabaseDestroyer destroyer;

    void connect();
    void disconnect();

protected:
    explicit Database(QObject *parent = nullptr);
    Database(const Database& ) = delete;
    Database& operator = (Database &) = delete;
    ~Database();
    friend class DatabaseDestroyer;
    QSqlQuery query(QString queryStr);

public:
    static Database* getInstance();
    bool userExist(const QString& login);
    QSqlQuery getUser(const QString& login);
    bool addUser(const QString& login, const QString& hashed_password);

};


#endif // DATABASESERVICE_H
