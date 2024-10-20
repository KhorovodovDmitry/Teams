#ifndef TASK2_H
#define TASK2_H

#include <QObject>
double secant_method(std::function<double(double)> f, double a, double b, int max_iterations);
double f1(double x);
double f2(double x);
double f3(double x);
double secant(QString a, QString b, QString n, QString number_f);

#endif // TASK2_H
