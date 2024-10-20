#include "secant_method.h"
#include "ui_secant_method.h"

Secant_method::Secant_method(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Secant_method)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

Secant_method::~Secant_method()
{
    delete ui;
}

void Secant_method::on_pushButton_exit_task1_clicked()
{
    this->close();
}

void Secant_method::task2_login(QString login) {
    ui->label_login->setText(login.toUtf8());
}
void Secant_method::update_task2() {
    QString variant = generate_variant("2");
    ui->label_error->setVisible(false);
    QStringList variant_rash = variant.split("&");
    ui->lineEdit_a->setText(variant_rash[0]);
    ui->lineEdit_b->setText(variant_rash[1]);
    ui->lineEdit_n->setText(variant_rash[2]);
    ui->lineEdit_f->setText(variant_rash[3]);
}

void Secant_method::on_pushButton_check_task1_clicked()
{
    QString variant = ui->lineEdit_a->text() + "/" + ui->lineEdit_b->text() + "/" + ui->lineEdit_n->text() + "/" + ui->lineEdit_f->text();
    QString result_client = ui->lineEdit_result->text();
    QString login = ui->label_login->text();
    bool check = check_Task("2", variant, result_client, login);
    if (check) {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Задание выполнено успешно!");
    } else {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Задание выполнено неверно!");
    }
}

