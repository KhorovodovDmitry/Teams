#include "generate_for_variant.h"
#include "singleton_client.h"
#include <iostream>

QString generate_task1() {
    int n = QRandomGenerator::global()->bounded(6, 8);
    QString result;

    for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            int value = QRandomGenerator::global()->bounded(0, 2);
            if (value == 1){
            result += QString::number(i) + ":" + QString::number(j) + ":" + QString::number(value) + ";";
            result += QString::number(j) + ":" + QString::number(i) + ":" + QString::number(value) + ";";
            }
        }
    }
    result = result + "/" + QString::number(n);
    qDebug()<<result;
    return result;
}
QString generate_task2() {
        int a = QRandomGenerator::global()->bounded(0, 2);
        int b = QRandomGenerator::global()->bounded(3, 5);
        int variant_of_function = QRandomGenerator::global()->bounded(0, 2);
        int n = QRandomGenerator::global()->bounded(1, 3);
        const QStringList function_str1 = {"x^2 - 2", "sin(x)", "x^3 - x - 2"};
        QString variant = QString::number(a) + "&" + QString::number(b) + "&" + QString::number(n) + "&" + function_str1[variant_of_function];
        return variant;
    }


