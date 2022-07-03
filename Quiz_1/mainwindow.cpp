#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int sayi,kontrol=0;

void MainWindow::on_checkBox_tumcarpan_toggled(bool checked)
{
    if(checked){
        ui->listWidget->setEnabled(true);
    }
    else{
         ui->listWidget->setEnabled(false);
    }
}

void MainWindow::on_checkBox_asalcarpan_toggled(bool checked)
{
    if(checked){
        ui->listWidget_2->setEnabled(true);
    }
    else{
         ui->listWidget_2->setEnabled(false);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int altsayi=ui->spinBox->value();
    int ustsayi=ui->spinBox_2->value();

    if(ustsayi<altsayi){
        QMessageBox::information(this,"Uyarı","Aralıkları kontrol ediniz","ok");
    }
    else{
    sayi =rand()%(ustsayi-altsayi)+altsayi;
    ui->label->setText(QString::number(sayi));

    }



}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    kontrol=0;
    if(ui->listWidget->isEnabled()){
        for(int i=1;i<=sayi;i++){
            if(sayi%i==0){
                ui->listWidget->addItem(QString::number(i));
        }
    }

    if(ui->listWidget_2->isEnabled()){
        for(int i=1;i<=sayi;i++){
            if(sayi%i==0){
                   for(int k=2;k<i;k++){
                        if(i%k==0){
                            kontrol=1;
                        }

                   }
                   if(kontrol==0){
                       if(i!=1){
                           ui->listWidget_2->addItem(QString::number(i));
                           kontrol=0;
                       }
                   }
                }
kontrol=0;
            }
        }

    }
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
}

