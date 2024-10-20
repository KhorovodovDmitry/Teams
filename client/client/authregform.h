#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include <QMessageBox>
#include "functionsforclient.h"
#include "mainwindow.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    //FunctionsForClient* get_func();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButtonAuth_clicked();

    void on_pushButtonChange_clicked();

    void on_pushButtonReg_clicked();

private:
    Ui::AuthRegForm *ui;
    MainWindow *ui_main;
};

#endif // AUTHREGFORM_H
