#ifndef NOTLAR_H
#define NOTLAR_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class notlar;
}

class notlar : public QDialog
{
    Q_OBJECT

public:
    explicit notlar(QWidget *parent = nullptr);
    ~notlar();

private slots:
    void on_tableView_tumogrenciler_clicked(const QModelIndex &index);

    void on_tableView_tumdersler_clicked(const QModelIndex &index);

    void on_pushButton_derskayit_clicked();

private:
    Ui::notlar *ui;

    QSqlTableModel *sql_tableo,*sql_tabled,*sql_tablen;
    QSqlDatabase data=QSqlDatabase::addDatabase("QSQLITE");
};

#endif // NOTLAR_H
