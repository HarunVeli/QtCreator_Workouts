#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ogrenci.h>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_ogris_clicked();

    void on_pushButton_dersis_clicked();

    void on_pushButton_notis_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase data=QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *sql_table;
};
#endif // MAINWINDOW_H
