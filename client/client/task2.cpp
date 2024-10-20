#include "task2.h"
#include "ui_task2.h"

Task2::Task2(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Task2)
{
    ui->setupUi(this);
    ui->tableWidget_graf->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->label_graf_var->setVisible(false);
};


Task2::~Task2()
{
    delete ui;
}

void Task2::on_pushButton_exit_task2_clicked() {
    this->close();
}

void Task2::on_pushButton_check_task2_clicked() {
    QString result_client = ui->lineEdit_result_graf_min->text();
    QString login = ui->label_login->text();
    bool check = check_task("2", ui->label_graf_var->text(), result_client, login);
    if (check) {
        ui->label_error_graf_min->setVisible(true);
        ui->label_error_graf_min->setText("Задание выполнено успешно!");
        ui->pushButton_check_task2->setEnabled(false);
    } else {
        ui->label_error_graf_min->setVisible(true);
        ui->label_error_graf_min->setText("Задание выполнено неверно!");
    }
}
void Task2::update_task2() {
    QString var = get_task2();
    ui->label_error_graf_min->setText("");
    ui->pushButton_check_task2->setEnabled(true);
    ui->label_error_graf_min->setVisible(false);
    ui->lineEdit_result_graf_min->setText("");
    ui->label_graf_var->setText(var);
    QStringList variant_rash = var.split("&");
    QStringList graf = variant_rash[0].split(";");
    ui->tableWidget_graf->setColumnCount(variant_rash[3].toInt());
    ui->tableWidget_graf->setRowCount(variant_rash[3].toInt());
    ui->lineEdit_from->setText(variant_rash[1]);
    ui->lineEdit_to->setText(variant_rash[2]);
    int** graff = new int*[variant_rash[3].toInt()];
    for (int i = 0; i < variant_rash[3].toInt(); i++) {
        graff[i] = new int[variant_rash[3].toInt()];
        for (int j = 0; j < variant_rash[3].toInt(); j++) {
            graff[i][j] = 0;
        }
    }
    for (int i = 0; i < graf.size() - 1; i++) {
        QStringList element = graf[i].split(":");
        graff[element[0].toInt() - 1][element[1].toInt() - 1] = element[2].toInt();
    }
    for (int i = 0; i < variant_rash[3].toInt(); i++) {
        for (int j = 0; j < variant_rash[3].toInt(); j++) {
            char el[256];
            sprintf(el, "%d", graff[i][j]);
            QTableWidgetItem *newItem = new QTableWidgetItem(tr(el));
            ui->tableWidget_graf->setItem(i, j, newItem);
        }
    }
}


void Task2::login(QString login) {
    ui->label_login->setText(login);
}
