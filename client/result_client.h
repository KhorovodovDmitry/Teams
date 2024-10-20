#ifndef RESULT_CLIENT_H
#define RESULT_CLIENT_H

#include <QWidget>
#include "funcforclient.h"

namespace Ui {
class Result_client;
}

class Result_client : public QWidget
{
    Q_OBJECT

public:
    explicit Result_client(QWidget *parent = nullptr);
    ~Result_client();
    void result_login(QString login);
    void stat_update();

private slots:
    void on_pushButton_exit_result_clicked();

private:
    Ui::Result_client *ui;

};

#endif // RESULT_CLIENT_H
