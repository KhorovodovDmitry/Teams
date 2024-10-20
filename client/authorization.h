#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
#include <QMessageBox>
#include "mainwindow.h"
#include "funcforclient.h"

namespace Ui {
class authorization;
}

class authorization : public QWidget
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();

private slots:
    void on_pushButton_authorization_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_registration_clicked();

private:
    Ui::authorization *ui;
    MainWindow *ui_main;
};

#endif // AUTHORIZATION_H
