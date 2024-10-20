#ifndef TASK2_H
#define TASK2_H

#include <QWidget>
#include "functionsforclient.h"

namespace Ui {
class Task2;
}

class Task2 : public QWidget {
    Q_OBJECT
public:
    explicit Task2(QWidget *parent = nullptr);
    ~Task2();
    void login(QString login);
    void update_task2();

private slots:
    void on_pushButton_exit_task2_clicked();
    void on_pushButton_check_task2_clicked();
private:
    Ui::Task2 *ui;
};

#endif // TASK1_H
