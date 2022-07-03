#include "personel.h"
#include "ui_personel.h"

personel::personel(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personel)
{
    ui->setupUi(this);

    sorgu=new QSqlQuery(db);
    listele();
}

personel::~personel()
{
    delete ui;
}

void personel::listele()
{
    sorgu->prepare("select * from personel");
    sorgu->exec();

    model_query=new QSqlQueryModel;
    model_query->setQuery(*sorgu);
    ui->tableView->setModel(model_query);
}

void personel::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_pid->setText(model_query->index(index.row(),0).data().toString());
    ui->lineEdit_pad->setText(model_query->index(index.row(),1).data().toString());
    ui->lineEdit_psoyad->setText(model_query->index(index.row(),2).data().toString());
    ui->lineEdit_did->setText(model_query->index(index.row(),3).data().toString());


}


void personel::on_pushButton_kaydet_clicked()
{
    QString ad,soyad;
        int dep_id;

        ad=ui->lineEdit_pad->text();
        soyad=ui->lineEdit_psoyad->text();
        dep_id=ui->lineEdit_did->text().toInt();

        QString bilgi = "INSERT INTO personel VALUES(NULL,'"+ad+"','"+soyad+"','"+QString::number(dep_id)+"');";
        QSqlQuery query;
        query.exec(bilgi);
        listele();



}


void personel::on_pushButton_degistir_clicked()
{
    QString ad,soyad;
    int per_id,dep_id;

    ad=ui->lineEdit_pad->text();
    soyad=ui->lineEdit_psoyad->text();
    per_id=ui->lineEdit_pid->text().toInt();
    dep_id=ui->lineEdit_did->text().toInt();

    sorgu->prepare("update personel set personel_ad=?,personel_soyad=?,departman_id=? where personel_id=?");
    sorgu->addBindValue(ad);
    sorgu->addBindValue(soyad);
    sorgu->addBindValue(dep_id);
    sorgu->addBindValue(per_id);
    if(!sorgu->exec()){
        QMessageBox::information(this,"asd",sorgu->lastError().text());
    }

    listele();
}


void personel::on_pushButton_sil_clicked()
{
    int per_id;
    per_id=ui->lineEdit_pid->text().toInt();

    sorgu->prepare("delete from personel where personel_id=?");
    sorgu->addBindValue(per_id);
    sorgu->exec();
    listele();

}

