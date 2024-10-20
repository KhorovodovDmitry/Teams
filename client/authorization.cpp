#include "authorization.h"
#include "ui_authorization.h"


authorization::authorization(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::authorization)
{
    ui->setupUi(this);
    ui->pushButton_registration->setVisible(false);
    ui->label_email->setVisible(false);
    ui->lineEdit_email->setVisible(false);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_authorization_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    bool check = is_auth(login, password);
    if (check) {
        QMessageBox::information(this, "Авторизация", "Авторизация прошла успешно.");
        this->close();
        ui_main = new MainWindow;
        ui_main->show();
        ui_main->main_login(login);
    }
    else {
        QMessageBox::information(this, "Авторизация", "Введен неправильный логин или пароль.");
    }
}


void authorization::on_pushButton_change_clicked()
{
    bool flag = ui->pushButton_registration->isVisible();
    ui->pushButton_authorization->setVisible(flag);
    ui->label_email->setVisible(!flag);
    ui->lineEdit_email->setVisible(!flag);
    ui->pushButton_registration->setVisible(!flag);
}


void authorization::on_pushButton_registration_clicked()
{
    QString email = ui->lineEdit_email->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    bool check = is_reg(email, login, password);
    if (check) {
        QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно.");
        this->close();
        ui_main = new MainWindow;
        ui_main->show();
        ui_main->main_login(login);
    }
    else {
        QMessageBox::information(this, "Регистрация", "Регистрация не удалась.");
    }

}

