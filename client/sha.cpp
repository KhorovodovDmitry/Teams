#include "sha.h"
#include "ui_sha.h"


SHA512::SHA512(QWidget* parent)
    : QWidget(parent), ui(new Ui::sha)
{
    ui->setupUi(this);
    ui->label_error_sha->setVisible(false);
}

SHA512::~SHA512() {
    delete ui;
}

// void SHA512::on_pushButton_exit_sha512() {
//     this->close();
// }

// void SHA512::on_pushButton_result_sha512_clicked() {
//     QString variant = generate_variant("4");
//     QString result_client = ui->lineEdit_result_sha->text();
//     QString login = ui->label_login->text();
//     bool check = check_Task("4", variant, result_client, login);
//     if (check) {
//         ui->label_error_sha->setVisible(true);
//         ui->label_error_sha->setText("Задание выполнено успешно!");
//     } else {
//         ui->label_error_sha->setVisible(true);
//         ui->label_error_sha->setText("Задание выполнено неверно!");
//     }
// }

void SHA512::task4_login(QString login) {
    ui->label_login->setText(login.toUtf8());
}

