#ifndef GRAF_H
#define GRAF_H

#include <QWidget>
#include "funcforclient.h"

namespace Ui {
class Graf;
}

class Graf : public QWidget
{
    Q_OBJECT

public:
    explicit Graf(QWidget *parent = nullptr);
    ~Graf();
    void task1_login(QString login);
    void update_task1();

private slots:
    void on_pushButton_exit_graf_clicked();

    void on_pushButton_check_graf_clicked();

private:
    Ui::Graf *ui;
};

#endif // GRAF_H
