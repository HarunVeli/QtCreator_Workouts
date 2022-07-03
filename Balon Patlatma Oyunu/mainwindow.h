#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QIcon>
#include <QSize>
#include <QPixmap>
#include <QTimer>
#include <butonlar.h>
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
    void BalonOlustur();
    void zamanlayıcı();
    void vurulan_balon();

private slots:
    void on_pushButton_bitir_clicked();

private:
    Ui::MainWindow *ui;
    QList<butonlar*> buttons;
    QList<int> silinecek;
};
#endif // MAINWINDOW_H
