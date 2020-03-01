#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QCloseEvent>
#include "connection.h"

namespace Ui {
class adduser;
}

class adduser : public QWidget
{
    Q_OBJECT

public:
    explicit adduser(QWidget *parent = 0);
    ~adduser();
    void closeEvent(QCloseEvent * event);

private slots:
    void on_showpass_pressed();

    void on_showpass_released();

    void on_showconfpass_pressed();

    void on_showconfpass_released();

    void on_showmasterkey_pressed();

    void on_showmasterkey_released();

    void on_confirmpass_textChanged(const QString &arg1);

    void on_tambah_clicked();

    void on_userid_returnPressed();

    void on_pass_returnPressed();

    void on_confirmpass_returnPressed();

    void on_masterkey_returnPressed();

    void on_userid_textChanged(const QString &arg1);

    void on_pass_textChanged(const QString &arg1);

private:
    Ui::adduser *ui;
};

#endif // ADDUSER_H
