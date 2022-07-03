#ifndef DERSLER_H
#define DERSLER_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class dersler;
}

class dersler : public QDialog
{
    Q_OBJECT

public:
    explicit dersler(QWidget *parent = nullptr);
    ~dersler();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_yenikayit_clicked();

    void on_pushButton_sil_clicked();

    void on_pushButton_guncelle_clicked();

private:
    Ui::dersler *ui;

    QSqlTableModel *sql_table,*sql_tablen;
    QSqlDatabase data=QSqlDatabase::addDatabase("QSQLITE");
};

#endif // DERSLER_H
