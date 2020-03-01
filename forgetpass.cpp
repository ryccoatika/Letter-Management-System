#include "forgetpass.h"
#include "ui_forgetpass.h"

forgetpass::forgetpass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forgetpass)
{
    ui->setupUi(this);
}

forgetpass::~forgetpass()
{
    delete ui;
}

void forgetpass::closeEvent(QCloseEvent * event) {
    ui->userid->clear();
    ui->password->clear();
    ui->confirmpassword->clear();
    ui->masterkey->clear();
    event->accept();
}

void forgetpass::on_showpass_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
}

void forgetpass::on_showpass_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
}

void forgetpass::on_showconfpass_pressed()
{
    ui->confirmpassword->setEchoMode(QLineEdit::Normal);
}

void forgetpass::on_showconfpass_released()
{
    ui->confirmpassword->setEchoMode(QLineEdit::Password);
}

void forgetpass::on_showmasterkey_pressed()
{
    ui->masterkey->setEchoMode(QLineEdit::Normal);
}

void forgetpass::on_showmasterkey_released()
{
    ui->masterkey->setEchoMode(QLineEdit::Password);
}

void forgetpass::on_reset_clicked()
{
    ui->information->setText("");
    if(ui->userid->text() == NULL){
        ui->userid->setFocus();
        ui->warning->setText("USER ID HARUS DIISI !");
    }else if(ui->password->text() == NULL){
        ui->password->setFocus();
        ui->warning->setText("PASSWORD HARUS DIISI !");
    }else if(ui->confirmpassword->text() == NULL){
        ui->confirmpassword->setFocus();
        ui->warning->setText("KONFIRMASI HARUS DIISI !");
    }else if(ui->confirmpassword->text() != ui->password->text()){
        ui->confirmpassword->setFocus();
        ui->warning->setText("KONFIRMASI HARUS SAMA DENGAN PASSWORD !");
    }else if(ui->masterkey->text() == NULL){
        ui->masterkey->setFocus();
        ui->warning->setText("MASTER KEY HARUS DIISI !");
    }else{
        ui->warning->setText("");
        string userid = ui->userid->text().toStdString();
        string pass = ui->password->text().toStdString();
        string passconf = ui->confirmpassword->text().toStdString();
        string master = ui->masterkey->text().toStdString();

        connection conn = connection();
        QByteArray masterhex = QByteArray::fromStdString(master);
        QByteArray passhex = QByteArray::fromStdString(pass);
        conn.hash = new QCryptographicHash(QCryptographicHash::Sha256);
        conn.hash->addData(masterhex);
        masterhex = conn.hash->result().toHex();
        conn.hash->reset();
        conn.hash = new QCryptographicHash(QCryptographicHash::Sha1);
        conn.hash->addData(passhex);
        passhex = conn.hash->result().toHex();
        delete conn.hash;

        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);
            query.exec("SELECT * FROM user WHERE id = 1");
            if(query.next()){
                if(query.value(2) == masterhex){
                    query.prepare("SELECT * FROM user WHERE username = :user");
                    query.bindValue(":user",QString::fromStdString(userid));
                    query.exec();
                    if(query.next()){
                        query.prepare("UPDATE user SET password = :pass WHERE username = :user");
                        query.bindValue(":user",QString::fromStdString(userid));
                        query.bindValue(":pass",passhex);
                        if(query.exec()){
                            ui->warning->setText("");
                            ui->information->setText("KATA SANDI BERHASIL DIGANTI");
                            ui->userid->clear();
                            ui->password->clear();
                            ui->confirmpassword->clear();
                            ui->masterkey->clear();
                            ui->userid->setFocus();
                        }else
                            ui->warning->setText("KATA SANDI GAGAL DIGANTI");
                            ui->userid->clear();
                            ui->password->clear();
                            ui->confirmpassword->clear();
                            ui->masterkey->clear();
                            ui->userid->setFocus();
                    }else{
                        ui->warning->setText("USER ID TIDAK TERDAFTAR");
                        ui->userid->clear();
                        ui->password->clear();
                        ui->confirmpassword->clear();
                        ui->masterkey->clear();
                        ui->userid->setFocus();
                    }
                }else{
                    ui->warning->setText("MASTER KEY SALAH !");
                    ui->masterkey->clear();
                    ui->masterkey->setFocus();
                }
            }
        }else{
            ui->warning->setText("DB Error !");
        }

        conn.db.close();
    }
}

void forgetpass::on_confirmpassword_textChanged(const QString &arg1)
{
    if(ui->confirmpassword->text() != ui->password->text()){
        ui->warning->setText("KONFIRMASI HARUS SAMA DENGAN PASSWORD !");
    }else{
        ui->warning->setText("");
    }
}

void forgetpass::on_userid_returnPressed()
{
    this->on_reset_clicked();
}

void forgetpass::on_password_returnPressed()
{
    this->on_reset_clicked();
}

void forgetpass::on_confirmpassword_returnPressed()
{
    this->on_reset_clicked();
}

void forgetpass::on_masterkey_returnPressed()
{
    this->on_reset_clicked();
}
