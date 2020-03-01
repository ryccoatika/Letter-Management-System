#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.setFixedSize(650,361);
    l.show();
    return a.exec();
}
