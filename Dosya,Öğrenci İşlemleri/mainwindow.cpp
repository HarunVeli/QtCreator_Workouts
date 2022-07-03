#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ogrenci.cpp"

QList<ogrenci*> ogrler;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //gecenler.txt dosyasındaki bilgileri ekrana yazdırıyoruz
    QFile file(":/gecenler/dosya/gecenler.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox ::critical(this,"HATA",file.errorString(),"ok");
        return;
    }
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();


    //kalanlar.txt dosyasındaki bilgileri ekrana yazdırıyoruz
    QFile file_2(":/kalanlar/dosya/kalanlar.txt");
    if(!file_2.open(QIODevice::ReadOnly)){
        QMessageBox ::critical(this,"HATA",file_2.errorString(),"ok");
        return;
    }
    QTextStream stream_2(&file_2);
    ui->plainTextEdit_2->setPlainText(stream_2.readAll());
    file_2.close();

}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString ad,soyad;
    int vize,final;
    double gnot=0;

    ad=ui->lineEdit->text();
    soyad=ui->lineEdit_2->text();
    vize=ui->lineEdit_3->text().toInt();
    final=ui->lineEdit_4->text().toInt();

    ogrenci *ogr =new ogrenci(ad,soyad,vize,final);

    ogrler.append(ogr);

    if(ogr->gecmenotuhesapla(vize,final)>=60){
        ui->plainTextEdit->appendPlainText(ad+" "+soyad+" Geçme Notu->"+QString::number(ogr->gnot));
        QFile file(":/gecenler/dosya/gecenler.txt");
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox ::critical(this,"HATA",file.errorString(),"ok");
            return;
        }
        QTextStream stream(&file);

        //foreach(ogrenci *ogr_,ogrler){
            stream << "\n"+ogr->ad+" "+ogr->soyad+" Gecme Notu->"+QString::number(ogr->gnot)+"\n";
        //}
        file.close();


    }
    else{
        ui->plainTextEdit_2->appendPlainText(ad+" "+soyad+" Geçme Notu->"+QString::number(ogr->gnot));
       /* QFile file_2(":/kalanlar/dosya/kalanlar.txt");
        if(!file_2.open(QIODevice::ReadOnly)){
            QMessageBox ::critical(this,"HATA",file_2.errorString(),"ok");
            return;
        }
        QTextStream stream_2(&file_2);
        file_2.close();*/
    }



}

