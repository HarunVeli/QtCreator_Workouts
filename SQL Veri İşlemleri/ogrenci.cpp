#include "ogrenci.h"
#include "ui_ogrenci.h"

ogrenci::ogrenci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogrenci)
{
    ui->setupUi(this);

    data.setDatabaseName("C:/Users/90553/Documents/Qt/Odev_2/veriler.db");


    sql_table=new QSqlTableModel();
    sql_table->setTable("öğrenci");
    sql_table->select();
    ui->tableView->setModel(sql_table);

}

ogrenci::~ogrenci()
{
    delete ui;
}
int guncellenecek_ogrenci,dersvar_mi=0;
void ogrenci::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_no->setText(sql_table->index(index.row(),0).data().toString());
    ui->lineEdit_ad->setText(sql_table->index(index.row(),1).data().toString());
    ui->lineEdit_soyad->setText(sql_table->index(index.row(),2).data().toString());
    guncellenecek_ogrenci=sql_table->index(index.row(),0).data().toInt();
    //guncellenecek_ogrenci=ui->lineEdit_no->text().toInt();
}


void ogrenci::on_pushButton_yenikayit_clicked()
{
    if(ui->lineEdit_ad->text()=="" || ui->lineEdit_soyad->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }

    //OGRENCI KAYIT ISLEMI

    QString ad,soyad;
    ad=ui->lineEdit_ad->text();
    soyad=ui->lineEdit_soyad->text();

         QString bilgi = "INSERT INTO öğrenci VALUES(NULL ,'" + ad + "','"+soyad+"');";
         QSqlQuery query;
         int kontrol = query.exec(bilgi);
         sql_table->setTable("öğrenci");
         sql_table->select();
         ui->tableView->setModel(sql_table);
}


void ogrenci::on_pushButton_guncelle_clicked()
{
    if(ui->lineEdit_ad->text()=="" || ui->lineEdit_soyad->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }

        //OGRENCI GUNCELLEME ISLEMI

        QSqlQuery bilgi;
        QString ogr_ad=ui->lineEdit_ad->text();
        QString ogr_soyad=ui->lineEdit_soyad->text();
        bilgi.prepare("UPDATE öğrenci SET ogr_ad='"+ogr_ad+"',""ogr_soyad='"+ogr_soyad+"'WHERE ogr_no="+QString::number(guncellenecek_ogrenci));
        ui->lineEdit_no->clear();
        bilgi.bindValue("ogr_no",guncellenecek_ogrenci);
        if(bilgi.exec()){
            QMessageBox::information(this,"Bilgilendirme","Kayıt Basarıyla guncellendi");
            sql_table->setTable("öğrenci");
            sql_table->select();
            ui->tableView->setModel(sql_table);
        }
        else{
            QMessageBox::information(this,"Bilgilendirme",bilgi.lastError().text());

        }


}


void ogrenci::on_pushButton_sil_clicked()
{
    if(ui->lineEdit_ad->text()=="" || ui->lineEdit_soyad->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }

    sql_table->setTable("notlar");
    sql_table->select();
    int row_count=sql_table->rowCount();

    for(int i=0;i<row_count;i++){
        if(guncellenecek_ogrenci==sql_table->index(i,0).data().toInt()){
            dersvar_mi=1;
        }
    }
    if(dersvar_mi){//OGRENCIYE KAYITLI DERS OLUP OLMADIGI KONTROL
        QMessageBox::information(this,"Bilgilendirme","Ogrenciye tanımlı ders bulunmaktadır ogrenci silinemez");
        sql_table->setTable("öğrenci");
        sql_table->select();
        ui->tableView->setModel(sql_table);
        dersvar_mi=0;
        return;
    }
    else{//OGRENCI KAYIT SILME ISLEMI
        QMessageBox::information(this,"Bilgilendirme","Ogrenciye tanımlı ders yok");
        QSqlQuery bilgi;
        bilgi.prepare("DELETE FROM öğrenci WHERE ogr_no="+QString::number(guncellenecek_ogrenci));
        ui->lineEdit_no->clear();
        bilgi.bindValue("ogr_no",guncellenecek_ogrenci);
        if(bilgi.exec()){
            QMessageBox::information(this,"Bilgilendirme","Kayıt basarılıyla silindi");
            sql_table->setTable("öğrenci");
            sql_table->select();
            ui->tableView->setModel(sql_table);
        }
        else{
            QMessageBox::information(this,"Bilgilendirme",bilgi.lastError().text());
        }
    }
}

