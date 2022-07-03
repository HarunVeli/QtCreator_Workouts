#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);//plaintext ccentralwidgetin hepsini kaplıyor
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusbar->showMessage("New File Created");
}


void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this,"Open a file");
    QFile my_file(path);
    if(!my_file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"DİKKAT","Dosya açılamadı.");
        return;
    }
    QTextStream stream(&my_file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    my_file.close();
    ui->statusbar->showMessage(path);

}


void MainWindow::on_actionSvae_triggered()
{
    QString path=QFileDialog::getSaveFileName(this,"Save a file");
    QFile my_file(path);
    if(!my_file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"DİKKAT","Dosya açılamadı.");
        return;
    }
    QTextStream stream(&my_file);
    stream << ui->plainTextEdit->toPlainText();
    my_file.close();
    ui->statusbar->showMessage(path);

}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}


void MainWindow::on_actionSelect_None_triggered()
{
    ui->plainTextEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_actionToolbar_Movable_triggered()
{
    if(ui->toolBar->isMovable()){
        ui->toolBar->setMovable(false);
    }
    else{
        ui->toolBar->setMovable(true);
    }
}

void MainWindow::on_actionToolbar_Floatable_triggered()
{
    if(ui->toolBar->isFloatable()){
        ui->toolBar->setFloatable(false);
    }
    else{
        ui->toolBar->setFloatable(true);
    }
}

void MainWindow::on_actionToolbar_Top_triggered()
{
    addToolBar(Qt::TopToolBarArea ,ui->toolBar);
}

void MainWindow::on_actionToolbar_Bottom_triggered()
{
    addToolBar(Qt::BottomToolBarArea ,ui->toolBar);
}

void MainWindow::on_actionToolbar_Right_triggered()
{
    addToolBar(Qt::RightToolBarArea ,ui->toolBar);
}

void MainWindow::on_actionToolbar_Left_triggered()
{
    addToolBar(Qt::LeftToolBarArea ,ui->toolBar);
}

void MainWindow::on_actionOpen_Form_triggered()
{
    MainWindow2 *main =new MainWindow2(this);
    main->show();

}

