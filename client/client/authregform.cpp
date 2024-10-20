#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelPass_Conf-> setVisible(false);
    ui->lineEditPass_Conf-> setVisible(false);
    ui->pushButtonReg-> setVisible(false);

}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButton_4_clicked()
{
    this->close();
}


void AuthRegForm::on_pushButtonAuth_clicked()
{
    bool auth = is_auth(ui->lineEditLogin->text(), ui->lineEditPass->text());
    if (auth) {
        QMessageBox::information(this, "Авторизация", "Авторизация прошла успешно.");
        this->close();
        ui_main = new MainWindow;
        ui_main->show();
        ui_main->login(ui->lineEditLogin->text());
    }
    else {
        QMessageBox::information(this, "Авторизация", "Введен неправильный логин или пароль.");
    }
}


void AuthRegForm::on_pushButtonChange_clicked()
{
    bool flag = ui->labelPass_Conf->isVisible();
    ui->labelPass_Conf-> setVisible(!flag);
    ui->lineEditPass_Conf-> setVisible(!flag);
    ui->pushButtonReg-> setVisible(!flag);
    ui->pushButtonAuth->setVisible(flag);
}


void AuthRegForm::on_pushButtonReg_clicked()
{
    if (ui->lineEditPass->text() != ui->lineEditPass_Conf->text()) {
        QMessageBox::information(this, "Регистрация", "Регистрация не удалась. Пароли не совпадают.");
    }
    bool reg = is_reg(ui->lineEditLogin->text(),ui->lineEditPass->text(), ui->lineEditPass_Conf->text());
    if (reg) {
        QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно.");
        this->close();
        ui_main = new MainWindow;
        ui_main->show();
        ui_main->login(ui->lineEditLogin->text());
    }
    else {
        QMessageBox::information(this, "Регистрация", "Регистрация не удалась.");
    }
}

