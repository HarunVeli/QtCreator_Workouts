#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFont>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_baslat_clicked();

    void on_checkBox_kangrubu_toggled(bool checked);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
