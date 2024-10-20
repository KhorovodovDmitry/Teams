#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Task1)
{
    ui->setupUi(this);
};


Task1::~Task1()
{
    delete ui;
}

void Task1::on_pushButton_exit_task1_clicked() {
    this->close();
}

void Task1::on_pushButton_check_task1_clicked() {
    QString variant = get_task1();
    QString result_client = ui->lineEdit_result->text();
    QString login = ui->label_login->text();
    bool check = check_task("1", variant, result_client, login);
    if (check) {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Задание выполнено успешно!");
    } else {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Задание выполнено неверно!");
    }
}


void Task1::login(QString login) {
    ui->label_login->setText(login);
}

void Task1::update_task1() {
    QString variant = get_task1();
    QStringList variant_rash = variant.split("&");
    ui->lineEdit_a->setText(variant_rash[0]);
    ui->lineEdit_b->setText(variant_rash[1]);
    ui->lineEdit_e->setText(variant_rash[2]);
    ui->lineEdit_f->setText(variant_rash[3]);
}
