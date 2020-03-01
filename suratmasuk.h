#ifndef SURATMASUK_H
#define SURATMASUK_H

#include <QMainWindow>
#include "connection.h"
#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
class suratmasuk;
}

class suratmasuk : public QMainWindow
{
    Q_OBJECT

public:
    explicit suratmasuk(QWidget *parent = 0);
    ~suratmasuk();
    QString btngrey = "border: 1px solid #9f9f9f; padding-left: 20px; font: 18pt 'Comic Sans MS'; \
                       font-weight: bold; color:  #9f9f9f; text-align: left;";
    QString btngreen = "border: 1px solid #9f9f9f; padding-left: 20px; font: 18pt 'Comic Sans MS'; \
                        font-weight: bold; color: rgba(141, 255, 128,220); text-align: left;";
    QString bggrey = "border: 1px solid #9f9f9f;";
    QString bggreen = "border: 1px solid #9f9f9f; background-color: rgba(141, 255, 128,220);";
    QString changeDate(QString datein);
    QString dateChange(QString datein);
    QStandardItemModel * model;

private slots:
    void on_btndashboard_clicked();

    void on_btntambah_clicked();

    void on_btnsetting_clicked();

    void on_icondashboard_clicked();

    void on_iconsetting_clicked();

    void on_icontambah_clicked();

    void on_kategori_currentIndexChanged(int index);

    void on_urutkan_currentIndexChanged(int index);

    void on_az_clicked();

    void on_za_clicked();

    void on_refresh_clicked();

    void on_hapus_clicked();

    void on_btnreset_clicked();

    void on_btntambah_2_clicked();

    void on_no_returnPressed();

    void on_alamatpengirim_returnPressed();

    void on_nosurat_returnPressed();

    void on_perihal_returnPressed();

    void on_acckepada_returnPressed();

    void on_keterangan_returnPressed();

    void on_klasifikasi_returnPressed();

    void on_cari_clicked();

    void on_edit_clicked();

    void on_editkembali_clicked();

    void on_editbtnubah_clicked();

private:
    Ui::suratmasuk *ui;
};

#endif // SURATMASUK_H
