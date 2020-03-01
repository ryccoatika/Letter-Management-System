#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_showhide_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
}

void login::on_showhide_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
}

void login::on_loginbutton_clicked()
{
    if(ui->username->text() == NULL){
        ui->warning->setText("Username harus diisi !!");
        ui->username->setFocus();
    }else if(ui->password->text() == NULL){
        ui->warning->setText("Password harus diisi !!");
        ui->password->setFocus();
    }else{
        string username = ui->username->text().toUtf8().constData();
        string password = ui->password->text().toUtf8().constData();
        connection conn = connection();
        QByteArray pass = QByteArray::fromStdString(password);
        conn.hash = new QCryptographicHash(QCryptographicHash::Sha1);
        conn.hash->addData(pass);
        pass = conn.hash->result().toHex();
        delete conn.hash;
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);
            query.prepare("SELECT * FROM user WHERE username = :user");
            query.bindValue(":user",QString::fromStdString(username));
            query.exec();
            if(query.next()){
                if(query.value(2) == pass){
                    ui->warning->setText("Login Success");
                    m.resize(1366,768);
                    this->close();
                    if(QApplication::desktop()->height() > 768 || QApplication::desktop()->width() > 1366)
                        m.show();
                    else
                        m.showMaximized();
                        //if login ok
                }else{
                    ui->warning->setText("Username atau Password salah !");
                    ui->username->clear();
                    ui->password->clear();
                    ui->username->setFocus();
                }
            }else{
                ui->warning->setText("Username atau Password salah !");
                ui->username->clear();
                ui->password->clear();
                ui->username->setFocus();
            }
        }else
            ui->warning->setText("DB Error");

        conn.db.close();
        }

}

void login::on_username_returnPressed()
{
    this->on_loginbutton_clicked();
}

void login::on_password_returnPressed()
{
    this->on_loginbutton_clicked();
}

void login::on_lupasandi_clicked()
{
    f.setFixedSize(631,363);
    f.show();
}

void login::on_tambahuser_clicked()
{
    a.setFixedSize(631,363);
    a.show();
}

void login::on_hapususer_clicked()
{
    d.setFixedSize(631,363);
    d.show();
}
