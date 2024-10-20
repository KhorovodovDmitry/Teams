#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H
#include <QObject>
#include <QRandomGenerator>
#include <QDebug>
const QStringList function_str1 = QStringList("12345+x");
bool is_auth(QString, QString);
bool is_reg(QString, QString, QString);
bool check_task(QString, QString, QString, QString);
QString get_task2();
QString get_task1();
QString getStat(QString login);

#endif // FUNCTIONSFORCLIENT_H
