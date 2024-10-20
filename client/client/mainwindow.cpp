#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , task1(new Task1)
    , task2(new Task2)
    , stat(new Stat)
{
    ui->setupUi(this);
    //ui_reg = new AuthRegForm;
    //ui_reg->show();
    //connect(ui_reg->get_func(),&FunctionsForClient::on_auth_ok,this,&MainWindow::slot_on_auth_ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStat_clicked() {
    stat->show();
    stat->login(ui->label_login->text());
}
void MainWindow::on_pushButtonTask1_clicked() {
    task1->show();
    task1->login(ui->label_login->text());
    task1->update_task1();
}
void MainWindow::on_pushButtonTask2_clicked() {
    task2->show();
    task2->login(ui->label_login->text());
    task2->update_task2();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::login(QString login) {
    ui->label_login->setText(login);
}
/*
void MainWindow::slot_on_auth_ok()
{
    delete ui_reg;
    this -> show();
}
*/
