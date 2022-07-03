#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "butonlar.h"

int sure=0,kontrol=0,sayac=1,patlak_balon=1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    timer->start(50);
    connect(timer,&QTimer::timeout,this,&MainWindow::BalonOlustur);

    ui->label_arkaplan->setGeometry(0,0,2000,1100);
    ui->label_gosterge->setGeometry(0,0,2000,80);
    ui->label_gosterge->setPixmap(QPixmap(":/images/images/beyaz_ekran.png"));
    ui->label_sure->setGeometry(25,20,60,20);
    ui->label_sure2->setGeometry(80,20,60,20);
    ui->label_balonsayisi->setGeometry(900,10,400,20);
    ui->label_balonsayisi2->setGeometry(1100,10,400,20);
    ui->label_kacanbalonsayisi->setGeometry(900,40,400,20);
    ui->label_kacanbalonsayisi2->setGeometry(1100,40,400,20);
    ui->pushButton_bitir->setGeometry(1400,20,120,40);

    QTimer *timer2=new QTimer(this);
    timer2->start(1000);
    connect(timer2,&QTimer::timeout,this,&MainWindow::zamanlayıcı);
}
int balon_resmi=0,sil=0,vurulan_balonkntrl=0,kacan_balon=1,kacan_balonkntrl=0;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BalonOlustur()
{
    if(kontrol%10==0){
        butonlar *button=new butonlar(this);

        for(int j=0;j<silinecek.size();j++){
            buttons[silinecek[j]]->setVisible(false);
        }
        if(vurulan_balonkntrl){
            ui->label_balonsayisi2->setText(QString::number(patlak_balon));
            patlak_balon+=1;
            vurulan_balonkntrl=0;
        }
        if(kacan_balonkntrl){
            ui->label_kacanbalonsayisi2->setText(QString::number(kacan_balon));
            kacan_balon+=1;
            kacan_balonkntrl=0;
        }

        button->setGeometry(rand()%1500,85,50,50);
        button->setIconSize(QSize(50,50));

        if(balon_resmi==0){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/0.jpg"));
        }
        else if(balon_resmi==1){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/1.jpg"));
        }
        else if(balon_resmi==2){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/2.jpg"));
        }
        else if(balon_resmi==3){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/3.jpg"));
        }
        else if(balon_resmi==4){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/4.jpg"));
        }
        else if(balon_resmi==5){
            balon_resmi+=1;
            button->setIcon(QIcon(":/images/images/5.jpg"));
        }
        else if(balon_resmi==6){
            balon_resmi=0;
            button->setIcon(QIcon(":/images/images/6.jpg"));
        }

        buttons.push_back(button);
        button->show();
    }
        int listeuzunluk=buttons.size();
        for (int i=0; i<listeuzunluk; ++i){
               if (buttons[i]->tikladinmi && buttons[i]->isVisible()){
                   vurulan_balonkntrl=1;
                buttons[i]->setIcon(QIcon(":/images/images/patlama.jpg"));
                silinecek.append(i);
               }else{
                   buttons[i]->setGeometry(buttons[i]->x(),buttons[i]->y()+6,buttons[i]->width(),buttons[i]->height());
               }
           }
        for (int i=0; i<listeuzunluk; ++i){
            if(buttons[i]->y()>=750 && buttons[i]->kactimi){
                kacan_balonkntrl=1;
                buttons[i]->kactimi=false;
            }
        }
        kontrol+=1;
}

void MainWindow::zamanlayıcı()
{
    ui->label_sure2->setText(QString::number(sayac));
    sayac+=1;
}

void MainWindow::vurulan_balon()
{
    ui->label_balonsayisi2->setText(QString::number(patlak_balon));
    patlak_balon+=1;
}

void MainWindow::on_pushButton_bitir_clicked()
{
    if(patlak_balon!=1 || kacan_balon!=1){
    if(patlak_balon>=kacan_balon){
        QMessageBox::information(this,"Bigilendirme","TEBRİKLER! Kazandınız.");
    }
    else{
        QMessageBox::information(this,"Bigilendirme","ÜZGÜNÜM! Kaybettiniz.");
    }
    }
}

