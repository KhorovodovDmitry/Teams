#include "QMessageBox"
#include "QDebug"
#include "QChar"

#include "functionsforclient.h"
#include "net.h"
bool is_auth(QString log, QString pass)
{
    QByteArray request;
    request = "auth&" + log.toUtf8() + "&" + pass.toUtf8() + "\r\n";
    qDebug().noquote() << "Making request: " << request;
    QString response = Net::getInstance()->doRequest(request);
    QStringList parts = response.split('&');

    if (QChar(parts[1][0]) == QChar('+')) {
        return true;
    }
    else {
        return false;
    }
}

bool is_reg(QString log, QString pass, QString pass_conf)
{
    QByteArray request;
    request = "reg&" + log.toUtf8() + "&" + pass.toUtf8() + "\r\n";
    QString response = Net::getInstance()->doRequest(request);
    QStringList parts = response.split('&');
    if (QChar(parts[1][0]) == QChar('+')) {
        return true;
    }
    else {
        return false;
    }
}

bool check_task(QString number_task, QString variant, QString result, QString login) {
    QByteArray request;
    request = "check&" + number_task.toUtf8() + "&" + variant.toUtf8() + "&" + result.toUtf8() + "&" + login.toUtf8();
    qDebug()<<request;
    QStringList parts = Net::getInstance()->doRequest(request).split('&');
    qDebug()<<parts;
    if (QChar(parts[1][0]) == QChar('+')) {

        return true;
    }
    else {
        return false;
    }
}
QString get_task2() {
    int n = QRandomGenerator::global()->bounded(6, 8);
    QString result;

    for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            int value = QRandomGenerator::global()->bounded(1, 100);
            result += QString::number(i) + ":" + QString::number(j) + ":" + QString::number(value) + ";";
            result += QString::number(j) + ":" + QString::number(i) + ":" + QString::number(value) + ";";
        }
    }
    int a = QRandomGenerator::global()->bounded(1, n - 2);
    int b = QRandomGenerator::global()->bounded(a + 1, n);
    result = result + "&" + QString::number(a) + "&" + QString::number(b) + "&" + QString::number(n);
    qDebug()<<result;
    return result;

}
QString get_task1() {
    double a = 0;
    double b = 1;
    int n=1;
    int variant_of_function = 0;
    QString variant = QString::number(a) + "&" + QString::number(b) + "&" + QString::number(n) + "&" + function_str1[variant_of_function];
    return variant;
}
QString getStat(QString login) {

}
