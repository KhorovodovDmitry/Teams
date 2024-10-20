#ifndef SHA_H
#define SHA_H

#include <QWidget>
#include "funcforclient.h"

namespace Ui {
class sha;
}

class SHA512 : public QWidget
{
    Q_OBJECT

public:

    explicit SHA512(QWidget* parent = nullptr);
    void task4_login(QString login);
    ~SHA512();

private slots:

    // void on_pushButton_exit_sha512();

    // void on_pushButton_result_sha512_clicked();

private:
    Ui::sha *ui;
};;

#endif // SHA_H
