#include "funcforclient.h"

bool is_auth(QString log, QString pass) {
    QByteArray request;
    request = "auth&" + log.toUtf8() + "&" + pass.toUtf8();
    QStringList parts = Singleton_client::getInstance()->doRequest(request).split('&');
    if (parts[1] == "+") {
        return true;
    }
    else {
        return false;
    }
}
bool is_reg(QString email, QString log, QString pass) {
    QByteArray request;
    request = "reg&" + log.toUtf8() + "&" + pass.toUtf8() + "&" + email.toUtf8();
    QStringList parts = Singleton_client::getInstance()->doRequest(request).split('&');
    if (parts[1] == "+") {
        return true;
    }
    else {
        return false;
    }
}
bool check_Task(QString task_number, QString variant, QString result_client, QString login) {
    QByteArray request;
    request = "check&" + task_number.toUtf8() + "&" + variant.toUtf8() + "&" + result_client.toUtf8() + "&" + login.toUtf8();
    QStringList parts = Singleton_client::getInstance()->doRequest(request).split('&');
    if (parts[1] == "+") {
        return true;
    }
    else {
        return false;
    }
}
QString* get_stat(QString login) {
    QByteArray request;
    request = "stat&" + login.toUtf8();
    QStringList parts = Singleton_client::getInstance()->doRequest(request).split('&');
    QString *statistic = new QString[5];
    statistic[0] = parts[1];
    statistic[1] = parts[2];
    statistic[2] = parts[3];
    statistic[3] = parts[4];
    statistic[4] = parts[5];
    return statistic;
}

QString generate_variant(QString number_task) {
    QString variant_task;
    if (number_task == "1") {
        variant_task = generate_task1();
    }
    else if (number_task == "2") {
        variant_task = generate_task2();
    }
    return variant_task;
}
