#include "suratmasuk.h"
#include "ui_suratmasuk.h"

suratmasuk::suratmasuk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::suratmasuk)
{
    ui->setupUi(this);

    this->on_btndashboard_clicked();

    this->on_refresh_clicked();
}

suratmasuk::~suratmasuk()
{
    delete ui;
}

// method for change sql date format to human readable date format
QString suratmasuk::changeDate(QString datein)
{
    QString y,m,d;
    y = datein.mid(0,4);
    m = datein.mid(5,2);
    d = datein.mid(8,2);

    switch (m.toInt()) {
    case 1:
        m = "Jan";
        break;
    case 2:
        m = "Feb";
        break;
    case 3:
        m = "Mar";
        break;
    case 4:
        m = "Apr";
        break;
    case 5:
        m = "Mei";
        break;
    case 6:
        m = "Jun";
        break;
    case 7:
        m = "Jul";
        break;
    case 8:
        m = "Ags";
        break;
    case 9:
        m = "Sep";
        break;
    case 10:
        m = "Okt";
        break;
    case 11:
        m = "Nov";
        break;
    case 12:
        m = "Des";
        break;
    default:
        break;
    }
    return d+" "+m+" "+y;
}

QString suratmasuk::dateChange(QString datein)
{
    //12 jan 2017
    QString y,m,d;
    d = datein.mid(0,2);
    m = datein.mid(3,3);
    y = datein.mid(7,4);

    if(m == "Jan")
        m = "01";
    else if(m == "Feb")
        m = "02";
    else if(m == "Mar")
        m = "03";
    else if(m == "Apr")
        m = "04";
    else if(m == "Mei")
        m = "05";
    else if(m == "Jun")
        m = "06";
    else if(m == "Jul")
        m = "07";
    else if(m == "Ags")
        m = "08";
    else if(m == "Sep")
        m = "09";
    else if(m == "Okt")
        m = "10";
    else if(m == "Nov")
        m = "11";
    else if(m == "Des")
        m = "12";

    return d+"/"+m+"/"+y;
}

void suratmasuk::on_btndashboard_clicked()
{
    ui->editwidget->close();
    this->on_refresh_clicked();
    ui->dashboard->show();
    ui->tambah->close();
    ui->setting->close();
    //dashboard
    ui->bgdashboard->setStyleSheet("QPushButton#bgdashboard{"+this->bggreen+"}"); //bgdashboard green
    ui->btndashboard->setStyleSheet("QPushButton#btndashboard{"+this->btngreen+"}"); //btndashboard green
    //tambah
    ui->bgtambah->setStyleSheet("QPushButton#bgtambah{"+this->bggrey+"}"); //bgtambah grey
    ui->btntambah->setStyleSheet("QPushButton#btntambah{"+this->btngrey+"}"); //btntambah grey
    //setting
    ui->bgsetting->setStyleSheet("QPushButton#bgsetting{"+this->bggrey+"}"); //bgsetting grey
    ui->btnsetting->setStyleSheet("QPushButton#btnsetting{"+this->btngrey+"}"); //btnsetting grey


}

void suratmasuk::on_btntambah_clicked()
{
    ui->tambah->show();
    ui->dashboard->close();
    ui->setting->close();
    //dashboard
    ui->bgdashboard->setStyleSheet("QPushButton#bgdashboard{"+this->bggrey+"}"); //bgdashboard grey
    ui->btndashboard->setStyleSheet("QPushButton#btndashboard{"+this->btngrey+"}"); //btndashboard grey
    //tambah
    ui->bgtambah->setStyleSheet("QPushButton#bgtambah{"+this->bggreen+"}"); //bgtambah green
    ui->btntambah->setStyleSheet("QPushButton#btntambah{"+this->btngreen+"}"); //btntambah green
    //setting
    ui->bgsetting->setStyleSheet("QPushButton#bgsetting{"+this->bggrey+"}"); //bgsetting grey
    ui->btnsetting->setStyleSheet("QPushButton#btnsetting{"+this->btngrey+"}"); //btnsetting grey

    ui->no->clear();
    ui->alamatpengirim->clear();
    ui->tglterima->clear();
    ui->tglsurat->clear();
    ui->nosurat->clear();
    ui->perihal->clear();
    ui->acckepada->clear();
    ui->tglacc->clear();
    ui->keterangan->clear();
    ui->klasifikasi->clear();
}

void suratmasuk::on_btnsetting_clicked()
{
    ui->setting->show();
    ui->dashboard->close();
    ui->tambah->close();
    //dashboard
    ui->bgdashboard->setStyleSheet("QPushButton#bgdashboard{"+this->bggrey+"}"); //bgdashboard grey
    ui->btndashboard->setStyleSheet("QPushButton#btndashboard{"+this->btngrey+"}"); //btndashboard grey
    //tambah
    ui->bgtambah->setStyleSheet("QPushButton#bgtambah{"+this->bggrey+"}"); //bgtambah grey
    ui->btntambah->setStyleSheet("QPushButton#btntambah{"+this->btngrey+"}"); //btntambah grey
    //setting
    ui->bgsetting->setStyleSheet("QPushButton#bgsetting{"+this->bggreen+"}"); //bgsetting green
    ui->btnsetting->setStyleSheet("QPushButton#btnsetting{"+this->btngreen+"}"); //btnsetting green
}

void suratmasuk::on_icondashboard_clicked()
{
    this->on_btndashboard_clicked();
}

void suratmasuk::on_iconsetting_clicked()
{
    this->on_btnsetting_clicked();
}

void suratmasuk::on_icontambah_clicked()
{
    this->on_btntambah_clicked();
}

void suratmasuk::on_kategori_currentIndexChanged(int index)
{
    if(index == 2 || index == 3 || index == 7){
        ui->kwtextedit->setPlaceholderText("format : 01 Jan 2001");
    }else{
        ui->kwtextedit->setPlaceholderText("masukkan kata kunci");
    }
}

void suratmasuk::on_urutkan_currentIndexChanged(int index)
{
    if(ui->az->isChecked())
        ui->tabelsmasuk->sortByColumn(index,Qt::AscendingOrder);
    if(ui->za->isChecked())
        ui->tabelsmasuk->sortByColumn(index,Qt::DescendingOrder);
}

void suratmasuk::on_az_clicked()
{
    this->on_urutkan_currentIndexChanged(ui->urutkan->currentIndex());
    ui->tabelsmasuk->resizeRowsToContents();
}

void suratmasuk::on_za_clicked()
{
    this->on_urutkan_currentIndexChanged(ui->urutkan->currentIndex());
    ui->tabelsmasuk->resizeRowsToContents();
}

void suratmasuk::on_refresh_clicked()
{
    ui->searchresult->clear();
    ui->warning->clear();
    ui->information_2->clear();
    ui->az->setChecked(true);
    ui->urutkan->setCurrentIndex(0);
    ui->kwtextedit->clear();
    ui->kategori->setCurrentIndex(0);



    connection conn = connection(); // add connection
    if(conn.ok){ // if db connection is valid

        QStringList header;
        header << "NO" << "ALAMAT PENGIRIM"
               << "TGL TERIMA" << "TGL SURAT"
               << "NO SURAT" << "PERIHAL"
               << "ACC KEPADA" << "TGL ACC"
               << "KETERANGAN" << "KLASIFIKASI SURAT";

        QSqlQuery query = QSqlQuery(conn.db);
        query.exec("SELECT * FROM smasuk");

        model = new QStandardItemModel(query.size(),10,this);

        model->setHorizontalHeaderLabels(header);

        int r = 0;  //set row for looping
        while(query.next()){
            for(int i = 0; i < 10; i++){
                if(i == 0){
                    QString str = query.value(0).toString();
                    if(str.length() == 3)
                        model->setItem(r,0,new QStandardItem("0"+str));
                    else if(str.length() == 2)
                        model->setItem(r,0,new QStandardItem("00"+str));
                    else if(str.length() == 1)
                        model->setItem(r,0,new QStandardItem("000"+str));
                    else
                        model->setItem(r,0,new QStandardItem(str));
                }else if(i == 2 || i == 3 || i == 7){
                    QString dt = query.value(i).toString(); //save date from sql to Qstring
                    dt = this->changeDate(dt);  //convert sql date format to human readable format
                    model->setItem(r,i,new QStandardItem(dt)); //set item
                }else
                    model->setItem(r,i,new QStandardItem(query.value(i).toString())); //set item

                model->item(r,i)->setTextAlignment(Qt::AlignCenter); //set item Hcenter
            }

            r++;    //increment row for looping
        }
        ui->tabelsmasuk->resizeRowsToContents();
        ui->tabelsmasuk->setModel(model);
        ui->tabelsmasuk->resizeRowsToContents();
        ui->tabelsmasuk->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tabelsmasuk->setColumnWidth(0,35);
        ui->tabelsmasuk->setColumnWidth(1,167);
        ui->tabelsmasuk->setColumnWidth(2,75);
        ui->tabelsmasuk->setColumnWidth(3,75);
        ui->tabelsmasuk->setColumnWidth(4,145);
        ui->tabelsmasuk->setColumnWidth(5,167);
        ui->tabelsmasuk->setColumnWidth(6,75);
        ui->tabelsmasuk->setColumnWidth(7,75);
        ui->tabelsmasuk->setColumnWidth(8,90);
        ui->tabelsmasuk->setColumnWidth(9,110);
    }
    conn.db.close();
}

void suratmasuk::on_hapus_clicked()
{
    QModelIndexList selectedr = ui->tabelsmasuk->selectionModel()->selectedRows();
    if(selectedr.count() != 0){
        int r[selectedr.count()];
        int no[selectedr.count()];
        QMessageBox::StandardButton reply;
        QString nomer;
        for(int i = 0; i < selectedr.count(); i++){
            r[i] = selectedr.at(i).row();
            no[i] = this->model->item(r[i])->text().toInt();
        }
        connection conn = connection();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);
            reply = QMessageBox::warning(this,"HAPUS SURAT","Apakah Anda yakin ingin menghapus surat",QMessageBox::No|QMessageBox::Yes);
            if(selectedr.count() > 1){
                if(reply == QMessageBox::Yes){
                    for(int i = 1; i <= selectedr.count(); i++){
                        query.exec("DELETE FROM smasuk WHERE no in ("+QVariant(no[i-1]).toString()+")");
                    }
                }
                this->on_refresh_clicked();
            }else{
                if(reply == QMessageBox::Yes){
                        query.exec("DELETE FROM smasuk WHERE no = "+QVariant(no[0]).toString());
                        query.clear();
                        query.exec("SELECT alamat_pengirim FROM smasuk WHERE no = "+QVariant(no[0]).toString());
                    if(query.size() == 0){
                        ui->information_2->setText("berhasil dihapus");
                        ui->information_2->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #00ff00;font-weight: bold;}");
                        this->on_refresh_clicked();
                    }else{
                        ui->warning->setText("gagal dihapus");
                        ui->warning->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #ff0000;font-weight: bold;}");
                    }
                }
            }
        }
    }else{
        QMessageBox::information(this,"HAPUS","Anda harus memilih surat yang akan dihapus",QMessageBox::Close);
    }



}

void suratmasuk::on_btnreset_clicked()
{
    ui->no->clear();
    ui->alamatpengirim->clear();
    ui->tglterima->clear();
    ui->tglsurat->clear();
    ui->nosurat->clear();
    ui->perihal->clear();
    ui->acckepada->clear();
    ui->tglacc->clear();
    ui->keterangan->clear();
    ui->klasifikasi->clear();
}

void suratmasuk::on_btntambah_2_clicked()
{
    ui->warning->clear();
    ui->information->clear();
    if(ui->no->text().isEmpty()){
        ui->warning->setText("NO HARUS DIISI !");
        ui->no->setFocus();
    }else if(ui->alamatpengirim->text().isEmpty()){
        ui->warning->setText("ALAMAT PENGIRIM HARUS DIISI !");
        ui->alamatpengirim->setFocus();
    }else if(ui->tglterima->text().isEmpty()){
        ui->warning->setText("TANGGAL TERIMA HARUS DIISI !");
        ui->tglterima->setFocus();
    }else if(ui->tglsurat->text().isEmpty()){
        ui->warning->setText("TANGGAL SURAT HARUS DIISI !");
        ui->tglsurat->setFocus();
    }else if(ui->nosurat->text().isEmpty()){
        ui->warning->setText("NO SURAT HARUS DIISI !");
        ui->nosurat->setFocus();
    }else if(ui->perihal->text().isEmpty()){
        ui->warning->setText("PERIHAL HARUS DIISI !");
        ui->perihal->setFocus();
    }else if(ui->acckepada->text().isEmpty()){
        ui->warning->setText("ACC KEPADA HARUS DIISI !");
        ui->acckepada->setFocus();
    }else if(ui->tglacc->text().isEmpty()){
        ui->warning->setText("TANGGAL ACC HARUS DIISI !");
        ui->tglacc->setFocus();
    }else if(ui->keterangan->text().isEmpty()){
        ui->warning->setText("KETERANGAN HARUS DIISI !");
        ui->keterangan->setFocus();
    }else if(ui->klasifikasi->text().isEmpty()){
        ui->warning->setText("KLASIFIKASI HARUS DIISI !");
        ui->klasifikasi->setFocus();
    }else{
        QString no = ui->no->text();
        QString alamatpengirim = ui->alamatpengirim->text();
        QString tglterima = ui->tglterima->text();
        QString tglsurat = ui->tglsurat->text();
        QString nosurat = ui->nosurat->text();
        QString perihal = ui->perihal->text();
        QString acckepada = ui->acckepada->text();
        QString tglacc = ui->tglacc->text();
        QString keterangan = ui->keterangan->text();
        QString klasifikasi = ui->klasifikasi->text();

        connection conn = connection();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);

            query.exec("SELECT alamat_pengirim FROM smasuk WHERE no = "+no);
            if(query.size() == 0){
                query.prepare("INSERT INTO smasuk (no, alamat_pengirim, tgl_terima, tgl_surat, nomor_surat, perihal, acc_kepada, tanggal_acc, keterangan, klasifikasi_surat) \
                               VALUES (?,?,?,?,?,?,?,?,?,?)");
                query.addBindValue(no);
                query.addBindValue(alamatpengirim);
                query.addBindValue(tglterima);
                query.addBindValue(tglsurat);
                query.addBindValue(nosurat);
                query.addBindValue(perihal);
                query.addBindValue(acckepada);
                query.addBindValue(tglacc);
                query.addBindValue(keterangan);
                query.addBindValue(klasifikasi);
                query.exec();
                query.exec("SELECT alamat_pengirim FROM smasuk WHERE no = "+no);
                if(query.size() == 1){
                    ui->information->setText("BERHASIL DITAMBAHKAN");
                    ui->warning->clear();
                    this->on_btnreset_clicked();
                }else{
                    ui->warning->setText("GAGAL MENAMBAHKAN DATA");
                    ui->information->clear();
                }
            }else{
                ui->warning->setText("DATA DENGAN NO "+no+" SUDAH ADA");
                ui->no->setFocus();
                ui->information->clear();
            }
        }
        conn.db.close();
    }
}

void suratmasuk::on_no_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_alamatpengirim_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_nosurat_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_perihal_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_acckepada_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_keterangan_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_klasifikasi_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratmasuk::on_cari_clicked()
{
    QString keyword = ui->kwtextedit->toPlainText();
    QList<QStandardItem *> findlist;
    int row = ui->kategori->currentIndex();
    findlist = model->findItems(keyword,Qt::MatchContains,row);
    if(findlist.count() == 0){
        ui->searchresult->setText("\""+keyword+"\" tidak ditemukan di kolom \""+ui->kategori->currentText()+"\"");
        ui->searchresult->setStyleSheet("QLabel#searchresult{color: #ff0000;font: 10pt 'Comic Sans MS';}");
    }else{
        ui->searchresult->setText("\""+keyword+"\" ditemukan di kolom \""+ui->kategori->currentText()+"\"\n("+QVariant(findlist.count()).toString()+")");
        ui->searchresult->setStyleSheet("QLabel#searchresult{color: #00ff00;font: 10pt 'Comic Sans MS';}");
    }

    connection conn = connection(); // add connection
    if(conn.ok){ // if db connection is valid

        QStringList header;
        header << "NO" << "ALAMAT PENGIRIM"
               << "TGL TERIMA" << "TGL SURAT"
               << "NO SURAT" << "PERIHAL"
               << "ACC KEPADA" << "TGL ACC"
               << "KETERANGAN" << "KLASIFIKASI SURAT";

        QSqlQuery query = QSqlQuery(conn.db);
        query.exec("SELECT * FROM smasuk");

        model = new QStandardItemModel(query.size(),10,this);

        model->setHorizontalHeaderLabels(header);

        int r = 0;  //set row for looping
        while(query.next()){
            for(int i = 0; i < 10; i++){
                if(i == 0){
                    QString str = query.value(0).toString();
                    if(str.length() == 3)
                        model->setItem(r,0,new QStandardItem("0"+str));
                    else if(str.length() == 2)
                        model->setItem(r,0,new QStandardItem("00"+str));
                    else if(str.length() == 1)
                        model->setItem(r,0,new QStandardItem("000"+str));
                    else
                        model->setItem(r,0,new QStandardItem(str));
                }else if(i == 2 || i == 3 || i == 7){
                    QString dt = query.value(i).toString(); //save date from sql to Qstring
                    dt = this->changeDate(dt);  //convert sql date format to human readable format
                    model->setItem(r,i,new QStandardItem(dt)); //set item
                }else
                    model->setItem(r,i,new QStandardItem(query.value(i).toString())); //set item

                model->item(r,i)->setTextAlignment(Qt::AlignCenter); //set item Hcenter
            }
            r++;    //increment row for looping
            ui->tabelsmasuk->resizeRowToContents(r);
        }
        for(int i = 0; i < findlist.count(); i++){
            model->item(findlist.at(i)->index().row(),findlist.at(i)->index().column())->setBackground(QBrush(QColor(141, 255, 128,220)));
        }
        if(findlist.count() == 0){
            ui->information_2->setText("pencarian tidak ditemukan");
            ui->information_2->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #ff0000;font-weight: bold;}");
        }else {
            ui->information_2->clear();
            ui->information_2->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #00ff00;font-weight: bold;}");
        }

        ui->tabelsmasuk->setModel(model);

        ui->tabelsmasuk->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tabelsmasuk->setColumnWidth(0,35);
        ui->tabelsmasuk->setColumnWidth(1,167);
        ui->tabelsmasuk->setColumnWidth(2,75);
        ui->tabelsmasuk->setColumnWidth(3,75);
        ui->tabelsmasuk->setColumnWidth(4,145);
        ui->tabelsmasuk->setColumnWidth(5,167);
        ui->tabelsmasuk->setColumnWidth(6,75);
        ui->tabelsmasuk->setColumnWidth(7,75);
        ui->tabelsmasuk->setColumnWidth(8,90);
        ui->tabelsmasuk->setColumnWidth(9,110);
    }
    conn.db.close();
}

void suratmasuk::on_edit_clicked()
{
    QModelIndexList selectedr = ui->tabelsmasuk->selectionModel()->selectedRows();
    if(selectedr.count() != 0){
        if(selectedr.count() == 1){
            int row = selectedr.at(0).row();
            ui->editno->setText(this->model->item(row,0)->text());
            ui->editalamatpengirim->setText(this->model->item(row,1)->text());
            ui->edittglterima->setDate(QDate::fromString(dateChange(this->model->item(row,2)->text()),"dd/MM/yyyy"));
            ui->edittglsurat->setDate(QDate::fromString(dateChange(this->model->item(row,3)->text()),"dd/MM/yyyy"));
            ui->editnosurat->setText(this->model->item(row,4)->text());
            ui->editperihal->setText(this->model->item(row,5)->text());
            ui->editacckepada->setText(this->model->item(row,6)->text());
            ui->edittglacc->setDate(QDate::fromString(dateChange(this->model->item(row,7)->text()),"dd/MM/yyyy"));
            ui->editketerangan->setText(this->model->item(row,8)->text());
            ui->editklasifikasi->setText(this->model->item(row,9)->text());
            ui->editwidget->show();
        }else{
            QMessageBox::information(this,"EDIT","PILIH SATU YANG AKAN DIEDIT",QMessageBox::Ok);
        }
    }
}


void suratmasuk::on_editkembali_clicked()
{
    ui->editwidget->close();
    ui->editwarning->clear();
    ui->editno->clear();
    ui->editalamatpengirim->clear();
    ui->edittglterima->clear();
    ui->edittglsurat->clear();
    ui->editnosurat->clear();
    ui->editperihal->clear();
    ui->editacckepada->clear();
    ui->edittglacc->clear();
    ui->editketerangan->clear();
    ui->editklasifikasi->clear();
}

void suratmasuk::on_editbtnubah_clicked()
{

    if(ui->editno->text().isEmpty()){
        ui->editwarning->setText("NO HARUS DIISI !");
        ui->editno->setFocus();
    }else if(ui->editalamatpengirim->text().isEmpty()){
        ui->editwarning->setText("ALAMAT PENGIRIM HARUS DIISI !");
        ui->editalamatpengirim->setFocus();
    }else if(ui->edittglterima->text().isEmpty()){
        ui->editwarning->setText("TANGGAL TERIMA HARUS DIISI !");
        ui->edittglterima->setFocus();
    }else if(ui->edittglsurat->text().isEmpty()){
        ui->editwarning->setText("TANGGAL SURAT HARUS DIISI !");
        ui->edittglsurat->setFocus();
    }else if(ui->editnosurat->text().isEmpty()){
        ui->editwarning->setText("NO SURAT HARUS DIISI !");
        ui->editnosurat->setFocus();
    }else if(ui->editperihal->text().isEmpty()){
        ui->editwarning->setText("PERIHAL HARUS DIISI !");
        ui->editperihal->setFocus();
    }else if(ui->editacckepada->text().isEmpty()){
        ui->editwarning->setText("ACC KEPADA HARUS DIISI !");
        ui->editacckepada->setFocus();
    }else if(ui->edittglacc->text().isEmpty()){
        ui->editwarning->setText("TANGGAL ACC HARUS DIISI !");
        ui->edittglacc->setFocus();
    }else if(ui->editketerangan->text().isEmpty()){
        ui->editwarning->setText("KETERANGAN HARUS DIISI !");
        ui->editketerangan->setFocus();
    }else if(ui->editklasifikasi->text().isEmpty()){
        ui->editwarning->setText("KLASIFIKASI HARUS DIISI !");
        ui->editklasifikasi->setFocus();
    }else{
        QString no = QVariant(ui->editno->text().toInt()).toString();
        QString alamatpengirim = ui->editalamatpengirim->text();
        QString tglterima = ui->edittglterima->text();
        QString tglsurat = ui->edittglsurat->text();
        QString nosurat = ui->editnosurat->text();
        QString perihal = ui->editperihal->text();
        QString acckepada = ui->editacckepada->text();
        QString tglacc = ui->edittglacc->text();
        QString keterangan = ui->editketerangan->text();
        QString klasifikasi = ui->editklasifikasi->text();
        connection conn = connection();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);

            query.prepare("UPDATE smasuk SET no=?, alamat_pengirim=?,tgl_terima=?,tgl_surat=?,nomor_surat=?,perihal=?,acc_kepada=?,tanggal_acc=?,keterangan=?,klasifikasi_surat=? WHERE no = "+no);
            query.addBindValue(no);
            query.addBindValue(alamatpengirim);
            query.addBindValue(tglterima);
            query.addBindValue(tglsurat);
            query.addBindValue(nosurat);
            query.addBindValue(perihal);
            query.addBindValue(acckepada);
            query.addBindValue(tglacc);
            query.addBindValue(keterangan);
            query.addBindValue(klasifikasi);
            query.exec();
            if(query.numRowsAffected() != 0){
                QMessageBox::information(this,"INFORMASI","DATA BERHASIL DI EDIT",QMessageBox::Ok);
                this->on_refresh_clicked();
                this->on_editkembali_clicked();
            }else{
                ui->editwarning->setText("GAGAL EDIT DATA");
            }

        }
        conn.db.close();
    }
}
