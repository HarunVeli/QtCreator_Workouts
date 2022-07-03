#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    veritabani.setDatabaseName("C:/Users/90553/Documents/Qt/Lab10/Lab10.db");
    if(!veritabani.open()){
        ui->statusbar->showMessage("Veri Tabanına Bağlanılamadı");
    }
    else{
        ui->statusbar->showMessage("Veri Tabanına Bağlanıldı");
    }

    model_table =new QSqlTableModel();
    model_table->setTable("departman");
    model_table->select();
    ui->tableView_departman->setModel(model_table);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    personel *per=new personel(veritabani,this);
    per->show();
}


void MainWindow::on_tableView_departman_clicked(const QModelIndex &index)
{
    QString indis=model_table->index(index.row(),0).data().toString();
    int indis_2=indis.toInt();//int çevirmedende string ile degerleri alabilirsin

    QSqlQuery sorgu;
    sorgu.prepare("select * from personel where departman_id=?");
    sorgu.addBindValue(indis_2);
    sorgu.exec();

    model_query=new QSqlQueryModel();
    model_query->setQuery(sorgu);
    ui->tableView_personel->setModel(model_query);

}

