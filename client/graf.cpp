#include "graf.h"
#include "ui_graf.h"

Graf::Graf(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Graf)
{
    ui->setupUi(this);
    ui->label_error_graf->setVisible(false);
    ui->label_graf_var->setVisible(false);
}

Graf::~Graf()
{
    delete ui;
}

void Graf::on_pushButton_exit_graf_clicked()
{
    this->close();
}

void Graf::task1_login(QString login) {
    ui->label_login->setText(login.toUtf8());
}
void Graf::update_task1() {
    QString var = generate_variant("1");
    ui->label_error_graf->setText("");
    ui->label_error_graf->setVisible(false);
    ui->lineEdit_result_graf->setText("");
    QStringList variant_rash = var.split("/");
    ui->label_graf_var->setText(var);
    QStringList graf = variant_rash[0].split(";");
    ui->tableWidget_graf->setColumnCount(variant_rash[1].toInt());
    ui->tableWidget_graf->setRowCount(variant_rash[1].toInt());
    int** graff = new int*[variant_rash[1].toInt()];
    for (int i = 0; i < variant_rash[1].toInt(); i++) {
        graff[i] = new int[variant_rash[1].toInt()];
        for (int j = 0; j < variant_rash[1].toInt(); j++) {
            graff[i][j] = 0;
        }
    }
    for (int i = 0; i < graf.size() - 1; i++) {
        QStringList element = graf[i].split(":");
        graff[element[0].toInt() - 1][element[1].toInt() - 1] = element[2].toInt();
    }
    for (int i = 0; i < variant_rash[1].toInt(); i++) {
        for (int j = 0; j < variant_rash[1].toInt(); j++) {
            char el[256];
            sprintf(el, "%d", graff[i][j]);
            QTableWidgetItem *newItem = new QTableWidgetItem(tr(el));
            ui->tableWidget_graf->setItem(i, j, newItem);
        }
    }
}

void Graf::on_pushButton_check_graf_clicked()
{
    QString result_client = ui->lineEdit_result_graf->text();
    QString login = ui->label_login->text();
    bool check = check_Task("1", ui->label_graf_var->text(), result_client, login);
    if (check) {
        ui->label_error_graf->setVisible(true);
        ui->label_error_graf->setText("Задание выполнено успешно!");
    } else {
        ui->label_error_graf->setVisible(true);
        ui->label_error_graf->setText("Задание выполнено неверно!");
    }
}

