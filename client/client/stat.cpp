#include "stat.h"
#include "ui_stat.h"

Stat::Stat(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Stat)
{
    ui->setupUi(this);
};


Stat::~Stat()
{
    delete ui;
}

void Stat::on_pushButton_exit_stat_clicked() {
    this->close();
}


void Stat::login(QString login) {
    ui->label_login->setText(login);
}
void Stat::update_stat() {

}
