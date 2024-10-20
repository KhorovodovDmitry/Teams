#include "result_client.h"
#include "ui_result_client.h"

Result_client::Result_client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Result_client)
{
    ui->setupUi(this);
    ui->tableWidget_Stat->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Result_client::~Result_client()
{
    delete ui;
}

void Result_client::on_pushButton_exit_result_clicked()
{
    this->close();
}

void Result_client::result_login(QString login) {
    ui->label_login->setText(login.toUtf8());
}

void Result_client::stat_update() {
    QString login = ui->label_login->text();
    QString* statics = get_stat(login);
    // заполнение
}
