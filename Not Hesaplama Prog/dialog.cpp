#include "dialog.h"
#include "ui_dialog.h"

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





void Dialog::on_hesapla_clicked()
{
    QString ad,dersad,vizenot,finalnot,gn;
    ad=ui->ogrencisim->text();
    dersad=ui->dersad->text();
    vizenot=ui->vizenot->text();
    finalnot=ui->finalnot->text();

    if(ad=="" || dersad=="" || vizenot=="" || finalnot==""){
        ui->textBrowser->setText("Eksik bilgi girdiniz tekrar deneyiniz.");
    }
    else{
        int gecme_notu,vize_notu,final_notu;
        vize_notu=vizenot.toInt();
        final_notu=finalnot.toInt();

        gecme_notu=vize_notu*0.4+final_notu*0.6;

        if(gecme_notu>=60)
        {
            ui->textBrowser->setText(ad+" İsimli öğrenci "+dersad+" dersinden geçmiştir. ("+QString::number(gecme_notu)+")");
        }
        else{
            ui->textBrowser->setText(ad+" İsimli öğrenci "+dersad+" dersinden kalmıştır. ");
        }
    }
}

void Dialog::on_temizle_clicked()
{
    ui->textBrowser->clear();
}

