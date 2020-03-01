#ifndef SURATKELUAR_H
#define SURATKELUAR_H

#include <QMainWindow>
#include "connection.h"
#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
class suratkeluar;
}

class suratkeluar : public QMainWindow
{
    Q_OBJECT

public:
    explicit suratkeluar(QWidget *parent = 0);
    ~suratkeluar();
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

    void on_skkategori_currentIndexChanged(int index);

    void on_skcari_clicked();

    void on_skurutkan_currentIndexChanged(int index);

    void on_skaz_clicked();

    void on_skza_clicked();

    void on_skrefresh_clicked();

    void on_skhapus_clicked();

    void on_btntambah_2_clicked();

    void on_btnreset_clicked();

    void on_no_returnPressed();

    void on_alamattujuan_returnPressed();

    void on_nosurat_returnPressed();

    void on_perihal_returnPressed();

    void on_keterangan_returnPressed();

    void on_klasifikasi_returnPressed();

    void on_skeditkembali_clicked();

    void on_skeditbtnubah_clicked();

    void on_skedit_clicked();

private:
    Ui::suratkeluar *ui;
};

#endif // SURATKELUAR_H
