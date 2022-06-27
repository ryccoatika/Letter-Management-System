#include "deluser.h"
#include "ui_deluser.h"

deluser::deluser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deluser)
{
    ui->setupUi(this);
}

deluser::~deluser()
{
    delete ui;
}

void deluser::closeEvent(QCloseEvent *event) {
    ui->masterkey->clear();
    ui->usertabel->clear();
    event->accept();
}

void deluser::on_refresh_clicked()
{
    if(ui->masterkey->text().isNull()){
        ui->warning->setText("MASTER KEY HARUS DIISI !");
        ui->masterkey->setFocus();
    }else {
        string master = ui->masterkey->text().toStdString();
        connection conn = connection();
        QByteArray masterhex = QByteArray::fromStdString(master);
        conn.hash = new QCryptographicHash(QCryptographicHash::Sha256);
        conn.hash->addData(masterhex);
        masterhex = conn.hash->result().toHex();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);
            query.prepare("SELECT * FROM user WHERE id = 1 ORDER BY username ASC");
            query.exec();
            if(query.next()){
                if(query.value(2) == masterhex){
                    ui->warning->clear();
                    query.prepare("SELECT * FROM user");
                    if(query.exec()){
                        int rows = query.size()-1;
                        ui->usertabel->setEditTriggers(QAbstractItemView::NoEditTriggers);
                        ui->usertabel->setFixedSize(221,141);
                        ui->usertabel->verticalHeader()->setVisible(false);
                        ui->usertabel->setColumnCount(1);
                        ui->usertabel->setRowCount(rows);
                        ui->usertabel->setColumnWidth(0,221);
                        QStringList tableheader;
                        tableheader << "USER ID" << "AKSI";
                        ui->usertabel->setHorizontalHeaderLabels(tableheader);
                        rows = 0;
                        query.next();
                        while(query.next()){
                            ui->usertabel->setItem(rows,0,new QTableWidgetItem(query.value(1).toString()));
                            rows++;
                        }
                    }
                }else{
                    ui->warning->setText("MASTER KEY SALAH");
                    ui->usertabel->clear();
                    ui->masterkey->clear();
                    ui->masterkey->setFocus();
                }
            }
            conn.db.close();
        }else{
            ui->warning->setText("DB Error !");
        }
    }

}

void deluser::on_showpass_pressed()
{
    ui->masterkey->setEchoMode(QLineEdit::Normal);
}

void deluser::on_showpass_released()
{
    ui->masterkey->setEchoMode(QLineEdit::Password);
}

void deluser::on_masterkey_returnPressed()
{
    this->on_refresh_clicked();
}

void deluser::on_hapus_clicked()
{
    if(ui->masterkey->text().isNull()){
        ui->warning->setText("MASTER KEY HARUS DIISI !");
        ui->masterkey->setFocus();
    }else if(ui->userid->text().isNull()){
        ui->warning->setText("USER ID HARUS DIISI !");
        ui->userid->setFocus();
    }else {
        string master = ui->masterkey->text().toStdString();
        string userid = ui->userid->text().toStdString();
        connection conn = connection();
        QByteArray masterhex = QByteArray::fromStdString(master);
        conn.hash = new QCryptographicHash(QCryptographicHash::Sha256);
        conn.hash->addData(masterhex);
        masterhex = conn.hash->result().toHex();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);
            query.prepare("SELECT * FROM user WHERE id = 1");
            query.exec();
            if(query.next()){
                if(query.value(2) == masterhex){
                    ui->warning->clear();
                    query.prepare("SELECT * FROM user WHERE username = ?");
                    query.addBindValue(QString::fromStdString(userid));
                    query.exec();
                    if(query.size() != 0){
                        query.prepare("DELETE FROM user WHERE username = ?");
                        query.addBindValue(QString::fromStdString(userid));
                        query.exec();
                        if(query.numRowsAffected() != 0){
                            ui->information->setText("USER "+QString::fromStdString(userid)+" BERHASIL DIHAPUS");
                            this->on_refresh_clicked();
                            ui->userid->clear();
                            ui->masterkey->clear();
                            ui->userid->setFocus();
                        }else {
                            ui->warning->setText("USER "+QString::fromStdString(userid)+" GAGAL DIHAPUS");
                            this->on_refresh_clicked();
                            ui->userid->clear();
                            ui->masterkey->clear();
                            ui->userid->setFocus();
                        }
                    }else{
                        ui->warning->setText("USER ID TIDAK TERDAFTAR");
                        ui->userid->clear();
                        ui->userid->setFocus();
                    }
                }else{
                    ui->warning->setText("MASTER KEY SALAH");
                    ui->usertabel->clear();
                    ui->masterkey->clear();
                    ui->masterkey->setFocus();
                }
            }
            conn.db.close();
        }else{
            ui->warning->setText("DB Error !");
        }
    }
}

void deluser::on_userid_returnPressed()
{
    this->on_hapus_clicked();
}
