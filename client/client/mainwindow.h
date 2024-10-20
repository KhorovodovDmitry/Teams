#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "task1.h"
#include "task2.h"
#include "stat.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void login(QString login);

private slots:
    void on_pushButtonStat_clicked();
    void on_pushButtonTask1_clicked();
    void on_pushButtonTask2_clicked();
    void on_pushButton_4_clicked();
    //void slot_on_auth_ok();

private:
    Ui::MainWindow *ui;
    Task1* task1;
    Task2* task2;
    Stat* stat;

    //AuthRegForm *ui_reg;
};
#endif // MAINWINDOW_H
