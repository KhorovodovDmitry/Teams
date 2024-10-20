#include "databaseservice.h"
#include <iostream>

Database::Database(QObject *parent) : QObject(parent) // вызывается в getInstance, если еще нет подключения
{
    this->connect(); //подключение к бд
}

Database * Database::p_instance = nullptr;
DatabaseDestroyer Database::destroyer;

DatabaseDestroyer::~DatabaseDestroyer()
{
    delete p_instance;
}

Database::~Database()
{
    if (db.isOpen())
        disconnect();
    if (p_instance)
        delete p_instance;
}

Database* Database::getInstance()
{
    if (!p_instance)
    {
        p_instance = new Database();
        p_instance->query("CREATE TABLE IF NOT EXISTS User(id INTEGER PRIMARY KEY AUTOINCREMENT, login VARCHAR(20) NOT NULL, password VARCHAR(128) NOT NULL);");
        destroyer.initialize(p_instance);
    }
    return p_instance;
}


void Database::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Test.db"); // Test.db в каталоге сборки (путь к нему можно настроить во вкладке проекты)

    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
}

QSqlQuery Database::query(QString queryStr) //отправка sql запросов
{
    QSqlQuery myquery;

    if(myquery.prepare(queryStr))
    {
        myquery.exec();
    }

    return myquery;
}

bool Database::userExist(const QString& login) {
    QSqlQuery query = this->query(QString("SELECT * FROM User WHERE user.login = \"%1\" LIMIT 1").arg(login));
    if (query.next()){
        return true;
    }
    return false;
}

QSqlQuery Database::getUser(const QString& login) {
    QSqlQuery query = this->query(QString("SELECT * FROM User WHERE user.login = \"%1\" LIMIT 1").arg(login));
    query.next();
    return query;
}

bool Database::addUser(const QString& login, const QString& hashed_password) {
    this->query(QString("INSERT INTO user (login, password) VALUES (\"%1\",\"%2\") ").arg(login).arg(hashed_password));
    return true;
}

void Database::disconnect()
{
    db.close();
}


