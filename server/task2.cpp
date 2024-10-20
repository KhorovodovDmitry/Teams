#include "task2.h"
#include <iostream>
#include <cmath>


#include <iostream>
#include <cmath>
#include <functional>

double secant_method(std::function<double(double)> f, double a, double b, int max_iterations) {
    double f_a = f(a);
    double f_b = f(b);
    double c;

    for (int i = 0; i < max_iterations; ++i) {
        if (f_b == f_a) {
        }
        double c = b - f_b * (b - a) / (f_b - f_a);
        double f_c = f(c);
        a = b;
        b = c;
        f_a = f_b;
        f_b = f_c;
    }
    return c;
}

// Примеры функций
double f1(double x) {
    return x * x - 2; // Пример: корень из 2
}

double f2(double x) {
    return std::sin(x); // Пример: корень синуса
}

double f3(double x) {
    return x * x * x - x - 2; // Пример: кубический корень
}

double secant(QString a, QString b, QString n, QString number_f) {
    double (*functions[])(double) = {f1, f2, f3};
    if (number_f == "x^2 - 2") {
        number_f = "1";
    }
    if (number_f == "sin(x)") {
        number_f = "2";
    }
    if (number_f == "x^3 - x - 2") {
        number_f = "3";
    }
    double root = secant_method(functions[number_f.toInt()], a.toInt(), b.toInt(), n.toInt());
    return root;
}

