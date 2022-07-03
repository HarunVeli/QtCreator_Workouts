#ifndef OGRENCI_H
#define OGRENCI_H

#include <QDialog>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class ogrenci;
}

class ogrenci : public QDialog
{
    Q_OBJECT

public:
    explicit ogrenci(QWidget *parent = nullptr);
    ~ogrenci();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_yenikayit_clicked();

    void on_pushButton_guncelle_clicked();

    void on_pushButton_sil_clicked();

private:
    Ui::ogrenci *ui;
     QSqlTableModel *sql_table;
     QSqlDatabase data=QSqlDatabase::addDatabase("QSQLITE");
     /*QSqlQueryModel *sql_query=new QSqlQueryModel();
     QSqlQuery *oku=new QSqlQuery();*/

};

#endif // OGRENCI_H
