#ifndef STAT_H
#define STAT_H

#include <QWidget>
#include "functionsforclient.h"

namespace Ui {
class Stat;
}

class Stat : public QWidget {
    Q_OBJECT
public:
    explicit Stat(QWidget *parent = nullptr);
    ~Stat();
    void login(QString login);
    void update_stat();

private slots:
    void on_pushButton_exit_stat_clicked();
private:
    Ui::Stat *ui;
};

#endif // STAT_H
