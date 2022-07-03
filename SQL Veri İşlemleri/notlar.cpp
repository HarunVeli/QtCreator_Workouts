#include "notlar.h"
#include "ui_notlar.h"

notlar::notlar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notlar)
{
    ui->setupUi(this);

    data.setDatabaseName("C:/Users/90553/Documents/Qt/Odev_2/veriler.db");


    sql_tableo=new QSqlTableModel();
    sql_tableo->setTable("öğrenci");
    sql_tableo->select();
    ui->tableView_tumogrenciler->setModel(sql_tableo);

    sql_tabled=new QSqlTableModel();
    sql_tabled->setTable("ders");
    sql_tabled->select();
    ui->tableView_tumdersler->setModel(sql_tabled);

    sql_tablen=new QSqlTableModel();
    sql_tablen->setTable("notlar");
    sql_tablen->select();
    ui->tableView_tumkayitlar->setModel(sql_tablen);


}
int ders_kontrol=0,row=0;
notlar::~notlar()
{
    delete ui;
}

void notlar::on_tableView_tumogrenciler_clicked(const QModelIndex &index)
{
    ui->lineEdit_ogr_no->setText(sql_tableo->index(index.row(),0).data().toString());
}


void notlar::on_tableView_tumdersler_clicked(const QModelIndex &index)
{
    ui->lineEdit_ders_kodu->setText(sql_tabled->index(index.row(),0).data().toString());
}


void notlar::on_pushButton_derskayit_clicked()
{
    if(ui->lineEdit_ders_kodu->text()=="" || ui->lineEdit_final_notu->text()=="" || ui->lineEdit_ogr_no->text()=="" || ui->lineEdit_vize_notu->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }
    int ders_kodu,ogr_no,vize_not,final_not,gecme_notu;
    ders_kodu=ui->lineEdit_ders_kodu->text().toInt();
    ogr_no=ui->lineEdit_ogr_no->text().toInt();
    vize_not=ui->lineEdit_vize_notu->text().toInt();
    final_not=ui->lineEdit_final_notu->text().toInt();
    gecme_notu=vize_not*0.4+final_not*0.6;


    sql_tablen->setTable("notlar");
    sql_tablen->select();
    int row_countn=sql_tablen->rowCount();

    //AYNI DERSE AYNI OGRENCI KAYITLI OLUP OLMADIGI KONTROLU

    for(int i=0;i<row_countn;i++){
        if(ders_kodu==sql_tablen->index(i,1).data().toInt()){
            row=i;
                if(ogr_no==sql_tablen->index(row,0).data().toInt()){
                    ders_kontrol=1;
            }
        }
    }
    if(ders_kontrol){//OGRENCININ DERSI ALIP ALMADIGI KONTROL
        QMessageBox::information(this,"Bilgilendirme","Bu ogrenci bu dersi almaktadır tekrar deneyiniz");
        ders_kontrol=0;
        return;
    }
    else{//DERS KAYIT ISLEMI
        QMessageBox::information(this,"Bilgilendirme","Ders kaydı basarıyla yapıldı");
        QString bilgi = "INSERT INTO notlar VALUES('" +QString::number(ogr_no)+ "' ,'" + QString::number(ders_kodu) + "','"+QString::number(vize_not)+"','"+QString::number(final_not)+"','"+QString::number(gecme_notu)+"');";
        QSqlQuery query;
        query.exec(bilgi);
        sql_tablen->setTable("notlar");
        sql_tablen->select();
        ui->tableView_tumkayitlar->setModel(sql_tablen);

}
}
