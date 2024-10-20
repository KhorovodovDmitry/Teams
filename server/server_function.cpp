#include "server_function.h"
#include <iostream>

QByteArray parse(QString request) {
    QByteArray response;
    QStringList parts = request.split('&');
    if (parts.size() == 3 && parts[0] == "auth")
    {
        // Обработка запроса авторизации (auth&login&password)
        response = authenticate(parts[1], parts[2]);
    }
    else if (parts[0] == "reg" && parts.size() == 4){
        // Обработка запроса регистрации (reg&login&password&email)
        response = registerUser(parts[1], parts[2], parts[3]);
    }
    else if (parts[0] == "stat" && parts.size() == 2)
    {
        // Обработка запроса статистики (stat&login)
        response = getUserStats(parts[1]);
    }
    else if (parts[0] == "check" && parts.size() == 5)
    {
        // Обработка запроса проверки (check&task_number&variant&answer&login)
        response = checkTask(parts[1], parts[2], parts[3], parts[4]);
    }
    return response;
}
QByteArray authenticate(const QString &login, const QString &pass)
{
    QByteArray response;
    if (!Database::getInstance()->userExist(login)) {
        response = "auth&-";
        return response;
    }

    QSqlQuery user = Database::getInstance()->getUser(login);
    QString db_login = user.value(1).toString();
    QString db_hashed_password =  user.value(2).toString();

    std::cout << "login_db: " << db_login.toStdString() << " pass_db: " << db_hashed_password.toStdString() << "1" << std::endl;
    std::cout << "login_db: " << login.toStdString() << " pass_db: " << pass.toStdString() << "1" << std::endl;

    if ((login == db_login) && (pass == db_hashed_password)) {
        response = "auth&+&" + login.toUtf8();
    }
    else {
        response = "auth&-";
    }
    return response;
}

QByteArray registerUser(const QString &login, const QString &pass, const QString &email)
{
    QByteArray response;
    if (!Database::getInstance()->userExist(login)) {
        Database::getInstance()->addUser(login, pass);
        response = "reg&+&" + login.toUtf8();
    } else {
        response = "reg&-";
    }
    return response;
}

QByteArray getUserStats(const QString &login)
{
    QByteArray response;
    // взятие из базы данных результатов пользователя
    // response = "stat&" + результаты через & ;
    return response;
}

QByteArray checkTask(const QString &task_number, const QString &variant, const QString &answer_client, const QString &login)
{
    QByteArray response;
    // ответ пользователя правильный или нет?
    bool check = true;
    if (task_number == "1") {
        std::cout << variant.toStdString() << std::endl;
        bool check_task = gg(variant.split("/")[0], answer_client, variant.split("/")[1].toInt());
        if (check_task) {
            check = true;
        }
        else {
            check = false;
        }
    }
    else if (task_number == "2") {
        double check_task = secant(variant.split("/")[0], variant.split("/")[1], variant.split("/")[2], variant.split("/")[3]);
        std::cout << check_task << std::endl;
        if (check_task == answer_client.toDouble()) {
            check = true;
        }
        else {
            check = false;
        }
    }

    if (check) {
        response = "check&+";
    }
    else {
        response = "check&-";
    }
    return response;
}

