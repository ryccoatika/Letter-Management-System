#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_smasuk_clicked()
{
    sm.resize(1366,768);
    this->close();
    if(QApplication::desktop()->height() > 768 || QApplication::desktop()->width() > 1366)
        sm.show();
    else
        sm.showMaximized();
}

void menu::on_skeluar_clicked()
{
    sk.resize(1366,768);
    this->close();
    if(QApplication::desktop()->height() > 768 || QApplication::desktop()->width() > 1366)
        sk.show();
    else
        sk.showMaximized();
}
