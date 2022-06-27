#include "suratkeluar.h"
#include "ui_suratkeluar.h"

suratkeluar::suratkeluar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::suratkeluar)
{
    ui->setupUi(this);
    this->on_btndashboard_clicked();
    this->on_skrefresh_clicked();
}

suratkeluar::~suratkeluar()
{
    delete ui;
}

QString suratkeluar::changeDate(QString datein)
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

QString suratkeluar::dateChange(QString datein)
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

void suratkeluar::on_btndashboard_clicked()
{
    ui->skeditwidget->close();
    this->on_skrefresh_clicked();
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

void suratkeluar::on_btntambah_clicked()
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
    ui->alamattujuan->clear();
    ui->tglkirim->clear();
    ui->tglsurat->clear();
    ui->nosurat->clear();
    ui->perihal->clear();
    ui->keterangan->clear();
    ui->klasifikasi->clear();
}

void suratkeluar::on_btnsetting_clicked()
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

void suratkeluar::on_icondashboard_clicked()
{
    this->on_btndashboard_clicked();
}

void suratkeluar::on_iconsetting_clicked()
{
    this->on_btnsetting_clicked();
}

void suratkeluar::on_icontambah_clicked()
{
    this->on_btntambah_clicked();
}

void suratkeluar::on_skkategori_currentIndexChanged(int index)
{
    if(index == 2 || index == 3){
        ui->skkwtextedit->setPlaceholderText("format : 01 Jan 2001");
    }else{
        ui->skkwtextedit->setPlaceholderText("masukkan kata kunci");
    }
}

void suratkeluar::on_skcari_clicked()
{
    QString keyword = ui->skkwtextedit->toPlainText();
    QList<QStandardItem *> findlist;
    int row = ui->skkategori->currentIndex();
    findlist = model->findItems(keyword,Qt::MatchContains,row);
    if(findlist.count() == 0){
        ui->sksearchresult->setText("\""+keyword+"\" tidak ditemukan di kolom \""+ui->skkategori->currentText()+"\"");
        ui->sksearchresult->setStyleSheet("QLabel#searchresult{color: #ff0000;font: 10pt 'Comic Sans MS';}");
    }else{
        ui->sksearchresult->setText("\""+keyword+"\" ditemukan di kolom \""+ui->skkategori->currentText()+"\"\n("+QVariant(findlist.count()).toString()+")");
        ui->sksearchresult->setStyleSheet("QLabel#searchresult{color: #00ff00;font: 10pt 'Comic Sans MS';}");
    }

    connection conn = connection(); // add connection
    if(conn.ok){ // if db connection is valid

        QStringList header;
        header << "NO" << "ALAMAT TUJUAN"
               << "TGL KIRIM" << "TGL SURAT"
               << "NO SURAT" << "PERIHAL"
               << "KETERANGAN" << "KLASIFIKASI SURAT";

        QSqlQuery query = QSqlQuery(conn.db);
        query.exec("SELECT * FROM skeluar");

        model = new QStandardItemModel(query.size(),8,this);

        model->setHorizontalHeaderLabels(header);

        int r = 0;  //set row for looping
        while(query.next()){
            for(int i = 0; i < 8; i++){
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
                }else if(i == 2 || i == 3){
                    QString dt = query.value(i).toString(); //save date from sql to Qstring
                    dt = this->changeDate(dt);  //convert sql date format to human readable format
                    model->setItem(r,i,new QStandardItem(dt)); //set item
                }else
                    model->setItem(r,i,new QStandardItem(query.value(i).toString())); //set item

                model->item(r,i)->setTextAlignment(Qt::AlignCenter); //set item Hcenter
            }
            r++;    //increment row for looping
            ui->sktabelsmasuk->resizeRowToContents(r);
        }
        for(int i = 0; i < findlist.count(); i++){
            model->item(findlist.at(i)->index().row(),findlist.at(i)->index().column())->setBackground(QBrush(QColor(141, 255, 128,220)));
        }
        if(findlist.count() == 0){
            ui->information->setText("pencarian tidak ditemukan");
            ui->information->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #ff0000;font-weight: bold;}");
        }else {
            ui->information->clear();
            ui->information->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #00ff00;font-weight: bold;}");
        }

        ui->sktabelsmasuk->setModel(model);

        ui->sktabelsmasuk->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->sktabelsmasuk->setColumnWidth(0,35);
        ui->sktabelsmasuk->setColumnWidth(1,205);
        ui->sktabelsmasuk->setColumnWidth(2,80);
        ui->sktabelsmasuk->setColumnWidth(3,80);
        ui->sktabelsmasuk->setColumnWidth(4,180);
        ui->sktabelsmasuk->setColumnWidth(5,215);
        ui->sktabelsmasuk->setColumnWidth(6,100);
        ui->sktabelsmasuk->setColumnWidth(7,110);
    }
    conn.db.close();
}

void suratkeluar::on_skurutkan_currentIndexChanged(int index)
{
    if(ui->skaz->isChecked())
        ui->sktabelsmasuk->sortByColumn(index,Qt::AscendingOrder);
    if(ui->skza->isChecked())
        ui->sktabelsmasuk->sortByColumn(index,Qt::DescendingOrder);
}

void suratkeluar::on_skaz_clicked()
{
    this->on_skurutkan_currentIndexChanged(ui->skurutkan->currentIndex());
    ui->sktabelsmasuk->resizeRowsToContents();
}

void suratkeluar::on_skza_clicked()
{
    this->on_skurutkan_currentIndexChanged(ui->skurutkan->currentIndex());
    ui->sktabelsmasuk->resizeRowsToContents();
}

void suratkeluar::on_skrefresh_clicked()
{
    ui->sksearchresult->clear();
    ui->warning->clear();
    ui->information->clear();
    ui->skaz->setChecked(true);
    ui->skurutkan->setCurrentIndex(0);
    ui->skkwtextedit->clear();
    ui->skkategori->setCurrentIndex(0);



    connection conn = connection(); // add connection
    if(conn.ok){ // if db connection is valid

        QStringList header;
        header << "NO" << "ALAMAT TUJUAN"
               << "TGL KIRIM" << "TGL SURAT"
               << "NO SURAT" << "PERIHAL"
               << "KETERANGAN" << "KLASIFIKASI SURAT";

        QSqlQuery query = QSqlQuery(conn.db);
        query.exec("SELECT * FROM skeluar");

        model = new QStandardItemModel(query.size(),8,this);

        model->setHorizontalHeaderLabels(header);

        int r = 0;  //set row for looping
        while(query.next()){
            for(int i = 0; i < 8; i++){
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
                }else if(i == 2 || i == 3){
                    QString dt = query.value(i).toString(); //save date from sql to Qstring
                    dt = this->changeDate(dt);  //convert sql date format to human readable format
                    model->setItem(r,i,new QStandardItem(dt)); //set item
                }else
                    model->setItem(r,i,new QStandardItem(query.value(i).toString())); //set item

                model->item(r,i)->setTextAlignment(Qt::AlignCenter); //set item Hcenter
            }

            r++;    //increment row for looping
        }
        ui->sktabelsmasuk->resizeRowsToContents();
        ui->sktabelsmasuk->setModel(model);
        ui->sktabelsmasuk->resizeRowsToContents();
        ui->sktabelsmasuk->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->sktabelsmasuk->setColumnWidth(0,35);
        ui->sktabelsmasuk->setColumnWidth(1,205);
        ui->sktabelsmasuk->setColumnWidth(2,80);
        ui->sktabelsmasuk->setColumnWidth(3,80);
        ui->sktabelsmasuk->setColumnWidth(4,180);
        ui->sktabelsmasuk->setColumnWidth(5,215);
        ui->sktabelsmasuk->setColumnWidth(6,100);
        ui->sktabelsmasuk->setColumnWidth(7,110);
    }
    conn.db.close();
}

void suratkeluar::on_skhapus_clicked()
{
    QModelIndexList selectedr = ui->sktabelsmasuk->selectionModel()->selectedRows();
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
                        query.exec("DELETE FROM skeluar WHERE no in ("+QVariant(no[i-1]).toString()+")");
                    }
                }
                this->on_skrefresh_clicked();
            }else{
                if(reply == QMessageBox::Yes){
                        query.exec("DELETE FROM skeluar WHERE no = "+QVariant(no[0]).toString());
                        query.clear();
                        query.exec("SELECT alamat_tujuan FROM skeluar WHERE no = "+QVariant(no[0]).toString());
                    if(query.size() == 0){
                        ui->information->setText("berhasil dihapus");
                        ui->information->setStyleSheet("QLabel#information_2{font: 16pt 'Comic Sans MS';color: #00ff00;font-weight: bold;}");
                        this->on_skrefresh_clicked();
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

void suratkeluar::on_btnreset_clicked()
{
    ui->no->clear();
    ui->alamattujuan->clear();
    ui->tglkirim->clear();
    ui->tglsurat->clear();
    ui->nosurat->clear();
    ui->perihal->clear();
    ui->keterangan->clear();
    ui->klasifikasi->clear();
}

void suratkeluar::on_btntambah_2_clicked()
{
    ui->warning->clear();
    ui->information->clear();
    if(ui->no->text().isNull()){
        ui->warning->setText("NO HARUS DIISI !");
        ui->no->setFocus();
    }else if(ui->alamattujuan->text().isNull()){
        ui->warning->setText("ALAMAT PENGIRIM HARUS DIISI !");
        ui->alamattujuan->setFocus();
    }else if(ui->tglkirim->text().isNull()){
        ui->warning->setText("TANGGAL TERIMA HARUS DIISI !");
        ui->tglkirim->setFocus();
    }else if(ui->tglsurat->text().isNull()){
        ui->warning->setText("TANGGAL SURAT HARUS DIISI !");
        ui->tglsurat->setFocus();
    }else if(ui->nosurat->text().isNull()){
        ui->warning->setText("NO SURAT HARUS DIISI !");
        ui->nosurat->setFocus();
    }else if(ui->perihal->text().isNull()){
        ui->warning->setText("PERIHAL HARUS DIISI !");
        ui->perihal->setFocus();
    }else if(ui->keterangan->text().isNull()){
        ui->warning->setText("KETERANGAN HARUS DIISI !");
        ui->keterangan->setFocus();
    }else if(ui->klasifikasi->text().isNull()){
        ui->warning->setText("KLASIFIKASI HARUS DIISI !");
        ui->klasifikasi->setFocus();
    }else{
        QString no = ui->no->text();
        QString alamattujuan = ui->alamattujuan->text();
        QString tglkirim = ui->tglkirim->text();
        QString tglsurat = ui->tglsurat->text();
        QString nosurat = ui->nosurat->text();
        QString perihal = ui->perihal->text();
        QString keterangan = ui->keterangan->text();
        QString klasifikasi = ui->klasifikasi->text();

        connection conn = connection();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);

            query.exec("SELECT alamat_tujuan FROM skeluar WHERE no = "+no);
            if(query.size() == 0){
                query.prepare("INSERT INTO skeluar (no, alamat_tujuan, tgl_kirim, tgl_surat, nomor_surat, perihal, keterangan, klasifikasi_surat) \
                               VALUES (?,?,?,?,?,?,?,?)");
                query.addBindValue(no);
                query.addBindValue(alamattujuan);
                query.addBindValue(tglkirim);
                query.addBindValue(tglsurat);
                query.addBindValue(nosurat);
                query.addBindValue(perihal);
                query.addBindValue(keterangan);
                query.addBindValue(klasifikasi);
                query.exec();
                query.exec("SELECT alamat_tujuan FROM skeluar WHERE no = "+no);
                if(query.size() == 1){
                    ui->information_8->setText("BERHASIL DITAMBAHKAN");
                    ui->warning->clear();
                    this->on_btnreset_clicked();
                }else{
                    ui->warning->setText("GAGAL MENAMBAHKAN DATA");
                    ui->information_8->clear();
                }
            }else{
                ui->warning->setText("DATA DENGAN NO "+no+" SUDAH ADA");
                ui->no->setFocus();
                ui->information_8->clear();
            }
        }
        conn.db.close();
    }
}


void suratkeluar::on_no_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_alamattujuan_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_nosurat_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_perihal_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_keterangan_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_klasifikasi_returnPressed()
{
    this->on_btntambah_2_clicked();
}

void suratkeluar::on_skeditkembali_clicked()
{
    ui->skeditwidget->close();
    ui->skeditwarning->clear();
    ui->skeditno->clear();
    ui->skeditalamattujuan->clear();
    ui->skedittglkirim->clear();
    ui->skedittglsurat->clear();
    ui->skeditnosurat->clear();
    ui->skeditperihal->clear();
    ui->skeditketerangan->clear();
    ui->skeditklasifikasi->clear();
}

void suratkeluar::on_skeditbtnubah_clicked()
{
    if(ui->skeditno->text().isNull()){
        ui->skeditwarning->setText("NO HARUS DIISI !");
        ui->skeditno->setFocus();
    }else if(ui->skeditalamattujuan->text().isNull()){
        ui->skeditwarning->setText("ALAMAT PENGIRIM HARUS DIISI !");
        ui->skeditalamattujuan->setFocus();
    }else if(ui->skedittglkirim->text().isNull()){
        ui->skeditwarning->setText("TANGGAL TERIMA HARUS DIISI !");
        ui->skedittglkirim->setFocus();
    }else if(ui->skedittglsurat->text().isNull()){
        ui->skeditwarning->setText("TANGGAL SURAT HARUS DIISI !");
        ui->skedittglsurat->setFocus();
    }else if(ui->skeditnosurat->text().isNull()){
        ui->skeditwarning->setText("NO SURAT HARUS DIISI !");
        ui->skeditnosurat->setFocus();
    }else if(ui->skeditperihal->text().isNull()){
        ui->skeditwarning->setText("PERIHAL HARUS DIISI !");
        ui->skeditperihal->setFocus();
    }else if(ui->skeditketerangan->text().isNull()){
        ui->skeditwarning->setText("KETERANGAN HARUS DIISI !");
        ui->skeditketerangan->setFocus();
    }else if(ui->skeditklasifikasi->text().isNull()){
        ui->skeditwarning->setText("KLASIFIKASI HARUS DIISI !");
        ui->skeditklasifikasi->setFocus();
    }else{
        QString no = QVariant(ui->skeditno->text().toInt()).toString();
        QString alamattujuan = ui->skeditalamattujuan->text();
        QString tglkirim = ui->skedittglkirim->text();
        QString tglsurat = ui->skedittglsurat->text();
        QString nosurat = ui->skeditnosurat->text();
        QString perihal = ui->skeditperihal->text();
        QString keterangan = ui->skeditketerangan->text();
        QString klasifikasi = ui->skeditklasifikasi->text();
        connection conn = connection();
        if(conn.ok){
            QSqlQuery query = QSqlQuery(conn.db);

            query.prepare("UPDATE skeluar SET no=?, alamat_tujuan=?,tgl_kirim=?,tgl_surat=?,nomor_surat=?,perihal=?,keterangan=?,klasifikasi_surat=? WHERE no = "+no);
            query.addBindValue(no);
            query.addBindValue(alamattujuan);
            query.addBindValue(tglkirim);
            query.addBindValue(tglsurat);
            query.addBindValue(nosurat);
            query.addBindValue(perihal);
            query.addBindValue(keterangan);
            query.addBindValue(klasifikasi);
            query.exec();
            if(query.numRowsAffected() != 0){
                QMessageBox::information(this,"INFORMASI","DATA BERHASIL DI EDIT",QMessageBox::Ok);
                this->on_skrefresh_clicked();
                this->on_skeditkembali_clicked();
            }else{
                ui->skeditwarning->setText("GAGAL EDIT DATA");
            }

        }
        conn.db.close();
    }
}

void suratkeluar::on_skedit_clicked()
{
    QModelIndexList selectedr = ui->sktabelsmasuk->selectionModel()->selectedRows();
    if(selectedr.count() != 0){
        if(selectedr.count() == 1){
            int row = selectedr.at(0).row();
            ui->skeditno->setText(this->model->item(row,0)->text());
            ui->skeditalamattujuan->setText(this->model->item(row,1)->text());
            ui->skedittglkirim->setDate(QDate::fromString(dateChange(this->model->item(row,2)->text()),"dd/MM/yyyy"));
            ui->skedittglsurat->setDate(QDate::fromString(dateChange(this->model->item(row,3)->text()),"dd/MM/yyyy"));
            ui->skeditnosurat->setText(this->model->item(row,4)->text());
            ui->skeditperihal->setText(this->model->item(row,5)->text());
            ui->skeditketerangan->setText(this->model->item(row,6)->text());
            ui->skeditklasifikasi->setText(this->model->item(row,7)->text());
            ui->skeditwidget->show();
        }else{
            QMessageBox::information(this,"EDIT","PILIH SATU YANG AKAN DIEDIT",QMessageBox::Ok);
        }
    }
}
