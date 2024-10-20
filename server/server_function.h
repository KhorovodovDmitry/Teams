#ifndef SERVER_FUNCTION_H
#define SERVER_FUNCTION_H

#include <QObject>
#include <QTcpSocket>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include "databaseservice.h"
#include "task1.h"
#include "task2.h"


QByteArray parse(QString request);
QByteArray authenticate(const QString &login, const QString &pass);
QByteArray registerUser(const QString &login, const QString &pass, const QString &email);
QByteArray getUserStats(const QString &login);

QByteArray checkTask(const QString &task_number, const QString &variant, const QString &answer_client, const QString &login);


#endif // SERVER_FUNCTION_H
