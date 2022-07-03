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

int kansecili_mi=0;
void Dialog::on_pushButton_baslat_clicked()
{
    ui->plainTextEdit->clear();
    QFont yazim;
    QPalette renk;

    yazim.setBold(ui->checkBox_bold->isChecked());
    yazim.setItalic(ui->checkBox_italik->isChecked());
    yazim.setUnderline(ui->checkBox_altcizili->isChecked());
    yazim.setFamily(ui->fontComboBox->currentText());
    yazim.setPointSize(ui->spinBox_yaziboyut->value());

    renk.setColor(QPalette::Text,ui->comboBox_renksecim->currentText());

    ui->plainTextEdit->setFont(yazim);
    ui->plainTextEdit->setPalette(renk);


    QString ad,soyad,cinsiyet,medeni;
    int tarih,cs,s_tarih,yas,maas,a=0;

    ad=ui->ad->text();
    soyad=ui->soyad->text();
    tarih=ui->dateEdit->date().year();
    cs=ui->spinBox_cocuksayisi->value();
    s_tarih=QDate::currentDate().year();
    yas=s_tarih-tarih;
    maas=(yas*10)+(cs*100)+5000;


    if(ui->radioButton__erkek->isChecked()){
        cinsiyet="Erkek";
    }
    else if(ui->radioButton_kadin->isChecked()){
        cinsiyet="Kadın";
    }
    else{
        ui->plainTextEdit->setPlainText("Cinsiyet Tercihi Yapınız.");
        a=1;
    }

    if(ui->radioButton_evli->isChecked()){
        medeni="Evli";
    }
    else if(ui->radioButton_bekar->isChecked()){
        medeni="Bekar";
    }
    else{
        ui->plainTextEdit->setPlainText("Medeni Durum Tercihi Yapınız.");
        if(a){
        ui->plainTextEdit->setPlainText("Cinsiyet ve Medeni Durum Tercihi Yapınız.");
        }
    }

    if(kansecili_mi==0){
        ui->plainTextEdit->setPlainText("Ad->"+ad+"\nSoyad->"+soyad+"\nCinsiyet->"+cinsiyet+"\nMedeni Durum->"+medeni+"\nCocuk Sayısı->"+QString::number(cs)+"\nYas->"+QString::number(yas)+"\nMaas->"+QString::number(maas));
    }
    else{
        ui->plainTextEdit->setPlainText("Ad->"+ad+"\nSoyad->"+soyad+"\nCinsiyet->"+cinsiyet+"\nMedeni Durum->"+medeni+"\nCocuk Sayısı->"+QString::number(cs)+"\nYas->"+QString::number(yas)+"\nKan Grubu->"+ui->comboBox_kangrubu->currentText()+"\nMaas->"+QString::number(maas));
    }




}


void Dialog::on_checkBox_kangrubu_toggled(bool checked)
{
    if(ui->checkBox_kangrubu->isChecked()){
        ui->comboBox_kangrubu->setEnabled(true);
        kansecili_mi=1;
    }
    else{
        ui->comboBox_kangrubu->setEnabled(false);
        kansecili_mi=0;
    }
}

