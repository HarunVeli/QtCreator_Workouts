#include "dersler.h"
#include "ui_dersler.h"

dersler::dersler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dersler)
{
    ui->setupUi(this);

    data.setDatabaseName("C:/Users/90553/Documents/Qt/Odev_2/veriler.db");

    sql_table=new QSqlTableModel();
    sql_table->setTable("ders");
    sql_table->select();
    ui->tableView->setModel(sql_table);
}
int ders_varmi=0;
dersler::~dersler()
{
    delete ui;
}
void dersler::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_derskodu->setText(sql_table->index(index.row(),0).data().toString());
    ui->lineEdit_dersadi->setText(sql_table->index(index.row(),1).data().toString());
    int ders_kodu=sql_table->index(index.row(),0).data().toInt();

    //TIKLANILAN DERS BILGISINE KAYITLI OGRENCILERI EKRANA YAZDIRMA ISLEMI

    QSqlQuery bilgi;
    bilgi.prepare("select * from notlar where ders_kodu=?" );
    bilgi.addBindValue(ders_kodu);
    bilgi.exec();
    QSqlQueryModel *bilgi2 = new QSqlQueryModel();
    bilgi2->setQuery(bilgi);
    ui->tableView_2->setModel(bilgi2);
    ui->lineEdit_derskodu->setText(sql_table->index(index.row(),0).data().toString());
    ui->lineEdit_dersadi->setText(sql_table->index(index.row(),1).data().toString());
}

int var_mi=0;
void dersler::on_pushButton_yenikayit_clicked()
{
        if(ui->lineEdit_dersadi->text()=="" || ui->lineEdit_derskodu->text()==""){
            QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
            return;
        }
        QString ders_adi;
        int ders_kodu;
        ders_adi=ui->lineEdit_dersadi->text();
        ders_kodu=ui->lineEdit_derskodu->text().toInt();

        int row_count=sql_table->rowCount();

        for(int i=0;i<row_count;i++){
            if(ders_kodu==sql_table->index(i,0).data().toInt()){
                var_mi=1;
            }
            if(var_mi){//AYNI DERS KODUNA SAHİP DERS OLUP OLMADIGI KONTROLU
                QMessageBox::information(this,"Bilgilendirme","Aynı koda sahip ders bulunmaktadır farklı kod ile tekrar deneyiniz");
                var_mi=0;
                return;
            }
        }

        //DERS KAYIT ISLEMI

            QString bilgi = "INSERT INTO ders VALUES('"+QString::number(ders_kodu)+"','"+ders_adi+"');";
            QSqlQuery query;
           int kontrol = query.exec(bilgi);
           if(kontrol){
               QMessageBox::information(this,"Bilgilendirme","Yeni kayıt başarılı");
           }
           else{
               QMessageBox::information(this,"Bilgilendirme","Yeni kayıt başarısız");
           }
            sql_table->setTable("ders");
            sql_table->select();
            ui->tableView->setModel(sql_table);
            var_mi=0;
        }





void dersler::on_pushButton_sil_clicked()
{
    if(ui->lineEdit_dersadi->text()=="" || ui->lineEdit_derskodu->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }

    int ders_kodu=ui->lineEdit_derskodu->text().toInt();
    sql_table->setTable("notlar");
    sql_table->select();
    int row_count=sql_table->rowCount();

    for(int i=0;i<row_count;i++){
        if(ders_kodu==sql_table->index(i,1).data().toInt()){
            ders_varmi=1;
        }
    }
    if(ders_varmi){//DERSE OGRENCI KAYITLI OLUP OLMADIGI KONTROLU
        QMessageBox::information(this,"Bilgilendirme","Derse kayıtlı ogrenci bulunmaktadir ders silinemez");
        sql_table->setTable("ders");
        sql_table->select();
        ui->tableView->setModel(sql_table);
        ders_varmi=0;
        return;
    }
    else{//DERS SILME ISLEMI
        QSqlQuery bilgi;
        QString ders_adi;
        //int ders_kodu;
        ders_adi=ui->lineEdit_dersadi->text();
        ders_kodu=ui->lineEdit_derskodu->text().toInt();
        bilgi.prepare("DELETE FROM ders WHERE ders_kodu="+QString::number(ders_kodu));
        ui->lineEdit_derskodu->clear();
        bilgi.bindValue("ders_kodu",ders_kodu);
        if(bilgi.exec()){
            QMessageBox::information(this,"Bilgilendirme","Derse tanımlı ogrenci yok\nkayıt basarılıyla silindi");
            sql_table->setTable("ders");
            sql_table->select();
            ui->tableView->setModel(sql_table);
        }
        else{
            QMessageBox::information(this,"Bilgilendirme",bilgi.lastError().text());
        }
}
}

void dersler::on_pushButton_guncelle_clicked()
{
    if(ui->lineEdit_dersadi->text()=="" || ui->lineEdit_derskodu->text()==""){
        QMessageBox::information(this,"Bilgilendirme","Lütfen boş alanları doldurunuz");
        return;
    }

    //DERS GUNCELLEME ISLEMI

    QSqlQuery bilgi;
    QString ders_adi;
    int ders_kodu;
    ders_adi=ui->lineEdit_dersadi->text();
    ders_kodu=ui->lineEdit_derskodu->text().toInt();
    bilgi.prepare("UPDATE ders SET ""ders_adi='"+ders_adi+"'WHERE ders_kodu="+QString::number(ders_kodu));
    ui->lineEdit_derskodu->clear();
    bilgi.bindValue("ders_kodu",ders_kodu);
    if(bilgi.exec()){
        QMessageBox::information(this,"Bilgilendirme","Kayıt Basarıyla guncellendi");
        sql_table->setTable("ders");
        sql_table->select();
        ui->tableView->setModel(sql_table);
    }
    else{
        QMessageBox::information(this,"Bilgilendirme",bilgi.lastError().text());

    }
}

