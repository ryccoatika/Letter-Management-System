#ifndef LOGIN_H
#define LOGIN_H

#include "menu.h"
#include "connection.h"
#include "forgetpass.h"
#include "adduser.h"
#include "deluser.h"

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_showhide_pressed();

    void on_showhide_released();

    void on_loginbutton_clicked();

    void on_username_returnPressed();

    void on_password_returnPressed();

    void on_lupasandi_clicked();

    void on_tambahuser_clicked();

    void on_hapususer_clicked();

private:
    Ui::login *ui;
    menu m;
    forgetpass f;
    adduser a;
    deluser d;
};

#endif // LOGIN_H
