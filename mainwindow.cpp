#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_name="";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
   //This a comment
    QString file_n=QFileDialog::getOpenFileName(this,"Open file","/home/afromana/Documents","Text file(*.txt)");
    QFile file(file_n);
    file_name=file_n;
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
   out<<text;
   file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_n=QFileDialog::getSaveFileName(this,"Save file","/home/afromana","Text file(*.txt)");
    QFile file(file_n);
    file_name=file_n;
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
   out<<text;
   file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_notepad_triggered()
{
    QMessageBox::about(this,"Notepad","Simple notepad example with QT and C++");
}
