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
int randsayi,randsayi1,sayi1i,sayi2i,deneme,g=0;

void Dialog::on_tahminsayi_clicked()
{
    //-------------------------------------->
    //Butona basılı tutulduğunda tekrar etmesi için
    //Kendi fonk içine yazıldığı zaman ilk tıklamada çalışmadığı için önceden ayarlıyorum
    //-------------------------------------->
    ui->tahminet->setAutoRepeat(true);
    ui->hizlitahmin->setAutoRepeat(true);
    //-------------------------------------->
    QString sayi1,sayi2;
    sayi1=ui->line1aralik->text();
    sayi2=ui->line2aralik->text();

   if(sayi1=="" || sayi2==""){
      ui->textBrowser->setText("Lütfen aralık değeri girip tekrar deneyiniz.");
   }
   else{
       sayi1i=sayi1.toInt();
       sayi2i=sayi2.toInt();

       randsayi=rand()%(sayi2i-sayi1i)+sayi1i;
       ui->textBrowser->setText("Tahmin edilecek sayı üretildi.");
       deneme=15;
       if(g==1){
           ui->tahminet->setVisible(true);
           ui->hizlitahmin->setVisible(true);
       }
   }
}

void Dialog::on_tahminet_pressed()
{
    deneme-=1;
    if(deneme==0 || deneme<0){
        ui->textBrowser->setText("Deneme hakkınız bitti doğru sayı->"+QString::number(randsayi));
        ui->tahminet->setVisible(false);
        g=1;
    }
    else{
        randsayi1=rand()%(sayi2i-sayi1i)+sayi1i;
        if(randsayi==randsayi1){
            ui->textBrowser->setText("Tebrikler doğru sayıyı buldunuz.\nkalan deneme hakkı->"+QString::number(deneme)+"\nSayı->"+QString::number(randsayi));
            ui->tahminet->setVisible(false);
            g=1;
        }
        else{
            ui->textBrowser->setText("Sayı bulunamadı.\nkalan hak->"+QString::number(deneme)+"\nDenenen sayı->"+QString::number(randsayi1));
        }
    }
}


void Dialog::on_hizlitahmin_clicked()
{
    //üretilen sayıyı hızlı bulmak için geliştirilmiş basit bir algoritma
    deneme-=1;
    if(deneme==0 || deneme<0){
        ui->textBrowser->setText("Deneme hakkınız bitti doğru sayı->"+QString::number(randsayi));
        ui->hizlitahmin->setVisible(false);
        g=1;
    }
    else{
        randsayi1=rand()%(sayi2i-sayi1i)+sayi1i;
        if(randsayi==randsayi1){
            ui->textBrowser->setText("Tebrikler doğru sayıyı buldunuz.\nkalan deneme hakkı->"+QString::number(deneme)+"\nSayı->"+QString::number(randsayi));
            ui->hizlitahmin->setVisible(false);
            g=1;
        }
        else{
            ui->textBrowser->setText("Sayı bulunamadı.\nkalan hak->"+QString::number(deneme)+"\nDenenen sayı->"+QString::number(randsayi1));
        }
    }
    if(sayi1i+sayi2i%2!=0){
        sayi2i+=1;
    }
    if(randsayi<=((sayi1i+sayi2i)/2)){
        sayi2i=(sayi1i+sayi2i)/2;
    }
    else{
        sayi1i=(sayi1i+sayi2i)/2;
    }




}

