#ifndef FORGETPASS_H
#define FORGETPASS_H

#include <QWidget>
#include <QCloseEvent>
#include "connection.h"

namespace Ui {
class forgetpass;
}

class forgetpass : public QWidget
{
    Q_OBJECT

public:
    explicit forgetpass(QWidget *parent = 0);
    ~forgetpass();
    void closeEvent(QCloseEvent * event);

private slots:
    void on_showpass_pressed();

    void on_showpass_released();

    void on_showconfpass_pressed();

    void on_showconfpass_released();

    void on_showmasterkey_pressed();

    void on_showmasterkey_released();

    void on_reset_clicked();

    void on_confirmpassword_textChanged(const QString &arg1);

    void on_userid_returnPressed();

    void on_password_returnPressed();

    void on_confirmpassword_returnPressed();

    void on_masterkey_returnPressed();

private:
    Ui::forgetpass *ui;
};

#endif // FORGETPASS_H
