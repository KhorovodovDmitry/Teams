#ifndef SECANT_METHOD_H
#define SECANT_METHOD_H

#include <QWidget>
#include "funcforclient.h"

namespace Ui {
class Secant_method;
}

class Secant_method : public QWidget
{
    Q_OBJECT

public:
    explicit Secant_method(QWidget *parent = nullptr);
    ~Secant_method();
    void task2_login(QString login);
    void update_task2();

private slots:
    void on_pushButton_exit_task1_clicked();

    void on_pushButton_check_task1_clicked();

private:
    Ui::Secant_method *ui;
};

#endif // SECANT_METHOD_H
