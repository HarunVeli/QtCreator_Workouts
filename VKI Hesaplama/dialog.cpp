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


void Dialog::on_pushButton_clicked()
{
    int tarih,kilo,yas;
    QString vki="";
    double boy,deger;

    tarih=ui->dateEdit->date().year();
    yas=QDate::currentDate().year()-tarih;

    boy=ui->doubleSpinBox->value();
    kilo=ui->spinBox->value();

    deger= kilo/(boy*boy);

    if(deger<=18.5){
        vki="Zayıf";
    }
    else if(deger<=24.9){
        vki="Normal Kilolu";
    }
    else if(deger<=29.9){
        vki="Fazla Kilolu";
    }
    else if(deger<=39.9){
        vki="Obez";
    }
    else if(deger>=40){
        vki="İleri derecede obez";
    }

    QMessageBox::information(this,"Bilgi","VKI Sınıfı->"+vki+"\nVKI Değeri->"+QString::number(deger)+"\nYas->"+QString::number(yas));
    //"<font color=red>VKI Sınıfı-></font>"
    //br ile alt satıra geçilebilir html olarak düşün
}

