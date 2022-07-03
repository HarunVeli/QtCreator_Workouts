#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_but_uygula_clicked()
{
    QString font,yazi;
    int boyut;

    QFont fontlu_yazi=yazi;
    QPalette renk;

    font=ui->fontComboBox->currentText();
    yazi=ui->line_yazi->text();
    boyut=ui->spinBox_yazibuyut->value();

    renk.setColor(QPalette::WindowText,ui->comboBox_renk->currentText());

    fontlu_yazi.setBold(ui->checkBox_kalin->isChecked());
    fontlu_yazi.setItalic(ui->checkBox_italik->isChecked());
    fontlu_yazi.setFamily(font);
    fontlu_yazi.setPointSize(boyut);


    ui->label_yazdirmaekrani->setPalette(renk);
    ui->label_yazdirmaekrani->setFont(fontlu_yazi);
    ui->label_yazdirmaekrani->setText(ui->line_yazi->text());





}

