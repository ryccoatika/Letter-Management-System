#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QDesktopWidget>
#include "suratmasuk.h"
#include "suratkeluar.h"

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_smasuk_clicked();

    void on_skeluar_clicked();

private:
    Ui::menu *ui;
    suratmasuk sm;
    suratkeluar sk;
};

#endif // MENU_H
