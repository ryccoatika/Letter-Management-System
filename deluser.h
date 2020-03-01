#ifndef DELUSER_H
#define DELUSER_H

#include <QWidget>
#include <QCloseEvent>
#include "connection.h"

namespace Ui {
class deluser;
}

class deluser : public QWidget
{
    Q_OBJECT

public:
    explicit deluser(QWidget *parent = 0);
    ~deluser();
    void closeEvent(QCloseEvent * event);

private slots:
    void on_refresh_clicked();

    void on_showpass_pressed();

    void on_showpass_released();

    void on_masterkey_returnPressed();

    void on_userid_returnPressed();

    void on_hapus_clicked();

private:
    Ui::deluser *ui;
};

#endif // DELUSER_H
