#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>//farklı bir model
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <personel.h>

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
    void on_pushButton_clicked();


    void on_tableView_departman_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase veritabani = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model_query;
    QSqlTableModel *model_table;
};
#endif // MAINWINDOW_H
