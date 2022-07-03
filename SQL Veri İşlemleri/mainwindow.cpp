#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ogrenci.h"
#include "notlar.h"
#include "dersler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data.setDatabaseName("C:/Users/90553/Documents/Qt/Odev_2/veriler.db");
    if(!data.open())
    {
        ui->statusbar->showMessage("Veri tabanına bağlanılamadı!");
    }
    else
    {
        ui->statusbar->showMessage("Veri tabanına başarıyla bağlanıldı!");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ogris_clicked()
{
    ogrenci *ogr=new ogrenci();
    ogr->show();
}


void MainWindow::on_pushButton_dersis_clicked()
{
    dersler *ders= new dersler();
    ders->show();
}


void MainWindow::on_pushButton_notis_clicked()
{
    notlar *not_=new notlar();
    not_->show();
}

