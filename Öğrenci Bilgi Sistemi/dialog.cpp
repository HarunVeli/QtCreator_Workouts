#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_rd_lisans_clicked()
{
    ui->grp_sinif->setEnabled(true);
    ui->grp_zorunlu->setEnabled(true);
    ui->grp_durum->setEnabled(false);
    ui->grp_zorunlu2->setEnabled(false);


}


void Dialog::on_rd_lisansustu_clicked()
{
    ui->grp_durum->setEnabled(true);
    ui->grp_zorunlu2->setEnabled(true);
    ui->grp_sinif->setEnabled(false);
    ui->grp_zorunlu->setEnabled(false);
}


void Dialog::on_bilgiyazdirbut_clicked()
{
    QString ad,soyad,bolum,egitim="Okumuyor";

    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();

    if(ui->rd_lisans->isChecked()){
        egitim="Lisans";
    }
    if(ui->rd_lisansustu->isChecked()){
        egitim="Lisans Üstü";
    }


    QMessageBox::information(this,"Bilgiler",ad+" "+soyad+"\n"+bolum+"\n"+egitim,"Ok","Cancel");

}

void Dialog::mezuniyet_sorgula()
{
    if(ui->rd_lisans->isChecked() && ui->rd4->isChecked() && ui->che_ai->isChecked() && ui->che_isg->isChecked() && ui->che_turk->isChecked()){
        QMessageBox::information(this,"Bilgi","Lisans öğrencisi mezun durumunda","Ok","Cancel");
    }
    else if(ui->rd_lisansustu->isChecked() && ui->radioButton_5->isChecked() && ui->che_seminer->isChecked() && ui->che_semeli->isChecked() && ui->che_tez->isChecked()){
        QMessageBox::information(this,"Bilgi","Lisans üstü öğrencisi mezun durumunda","Ok","Cancel");
    }else{
        QMessageBox::information(this,"Bilgi","Öğrenci mezun durumunda değil","Ok","Cancel");
    }
    }


void Dialog::on_mezuniyetbut_clicked()
{
    mezuniyet_sorgula();



}

