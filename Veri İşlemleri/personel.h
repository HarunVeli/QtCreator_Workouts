#ifndef PERSONEL_H
#define PERSONEL_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>//farklı bir model
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class personel;
}

class personel : public QDialog
{
    Q_OBJECT

public:
    explicit personel(QSqlDatabase,QWidget *parent = nullptr);
    ~personel();
    void listele();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_kaydet_clicked();

    void on_pushButton_degistir_clicked();

    void on_pushButton_sil_clicked();

private:
    Ui::personel *ui;

    QSqlQueryModel *model_query;
    QSqlQuery *sorgu;
};

#endif // PERSONEL_H
