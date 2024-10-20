#ifndef FUNCFORCLIENT_H
#define FUNCFORCLIENT_H
#include "singleton_client.h"
#include "generate_for_variant.h"

#include <QObject>
bool is_auth(QString log, QString pass);
bool is_reg(QString email, QString log, QString pass);
bool check_Task(QString task_number, QString variant, QString result_client, QString login);
QString* get_stat(QString login);
QString generate_variant(QString number_task);



#endif // FUNCFORCLIENT_H
