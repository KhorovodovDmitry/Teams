#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_task1 = new Graf;
    ui_task2 = new Secant_method;
    ui_result = new Result_client;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_task1_clicked()
{
    ui_task1->show();
    ui_task1->task1_login(ui->label_login->text());
    ui_task1->update_task1();
}


void MainWindow::on_pushButton_task2_clicked()
{
    ui_task2->show();
    ui_task2->update_task2();
    ui_task2->task2_login(ui->label_login->text());
}

void MainWindow::on_pushButton_result_clicked()
{
    ui_result->show();
    ui_result->result_login(ui->label_login->text());
}

void MainWindow::main_login(QString login) {
    ui->label_login->setText(login.toUtf8());
}
