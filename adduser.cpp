#include "adduser.h"
#include "ui_adduser.h"

adduser::adduser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
}

adduser::~adduser()
{
    delete ui;
}

void adduser::closeEvent(QCloseEvent * event) {
    ui->userid->clear();
    ui->pass->clear();
    ui->confirmpass->clear();
    ui->masterkey->clear();
    event->accept();
}

void adduser::on_showpass_pressed()
{
    ui->pass->setEchoMode(QLineEdit::Normal);
}

void adduser::on_showpass_released()
{
    ui->pass->setEchoMode(QLineEdit::Password);
}

void adduser::on_showconfpass_pressed()
{
    ui->confirmpass->setEchoMode(QLineEdit::Normal);
}

void adduser::on_showconfpass_released()
{
    ui->confirmpass->setEchoMode(QLineEdit::Password);
}

void adduser::on_showmasterkey_pressed()
{
    ui->masterkey->setEchoMode(QLineEdit::Normal);
}

void adduser::on_showmasterkey_released()
{
    ui->masterkey->setEchoMode(QLineEdit::Password);
}

void adduser::on_confirmpass_textChanged(const QString &arg1)
{
    if(ui->pass->text() != ui->confirmpass->text())
        ui->warning->setText("KONFIRMASI HARUS SAMA DENGAN PASSWORD !");
    else
        ui->warning->setText("");
}

void adduser::on_tambah_clicked()
{
    ui->information->setText("");
    if(ui->userid->text() == NULL){
        ui->userid->setFocus();
        ui->warning->setText("USER ID HARUS DIISI !");
    }else if(ui->pass->text() == NULL){
        ui->pass->setFocus();
        ui->warning->setText("PASSWORD HARUS DIISI !");
    }else if(ui->confirmpass->text() == NULL){
        ui->confirmpass->setFocus();
        ui->warning->setText("KONFIRMASI HARUS DIISI !");
    }else if(ui->confirmpass->text() != ui->pass->text()){
        ui->confirmpass->setFocus();
        ui->warning->setText("KONFIRMASI HARUS SAMA DENGAN PASSWORD !");
    }else if(ui->masterkey->text() == NULL){
        ui->masterkey->setFocus();
        ui->warning->setText("MASTER KEY HARUS DIISI !");
    }else{
        ui->warning->setText("");
        string userid = ui->userid->text().toStdString();
        string pass = ui->pass->text().toStdString();
        string passconf = ui->confirmpass->text().toStdString();
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
                    if(query.size() == 0){
                        query.prepare("INSERT INTO user (username,password) VALUES (?,?)");
                        query.addBindValue(QString::fromStdString(userid));
                        query.addBindValue(passhex);
                        if(query.exec()){
                            ui->warning->setText("");
                            ui->information->setText("USER BERHASIL DITAMBAHKAN");
                            ui->userid->clear();
                            ui->pass->clear();
                            ui->confirmpass->clear();
                            ui->masterkey->clear();
                            ui->userid->setFocus();
                        }else{
                            ui->warning->setText("GAGAL MENAMBAHKAN USER");
                        }
                    }else{
                        ui->warning->setText("USER ID SUDAH TERDAFTAR");
                        ui->userid->clear();
                        ui->pass->clear();
                        ui->confirmpass->clear();
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



void adduser::on_userid_returnPressed()
{
    this->on_tambah_clicked();
}

void adduser::on_pass_returnPressed()
{
    this->on_tambah_clicked();
}

void adduser::on_confirmpass_returnPressed()
{
    this->on_tambah_clicked();
}

void adduser::on_masterkey_returnPressed()
{
    this->on_tambah_clicked();
}

void adduser::on_userid_textChanged(const QString &arg1)
{
    if(ui->userid->text().length() < 5)
        ui->warning->setText("USER ID MINIMAL 5 KARAKTER");
    else
        ui->warning->clear();
}

void adduser::on_pass_textChanged(const QString &arg1)
{
    if(ui->pass->text().length() < 8)
        ui->warning->setText("PASSWORD MINIMAL 8 KARAKTER");
    else
        ui->warning->clear();
}
