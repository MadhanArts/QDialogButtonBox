#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filters = "All Files (*.*) ;; Text Files (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://", filters);
    // QMessageBox::information(this, "File Demo", file_name);

    QFile file(file_name);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(this, "Warning", "File not opened");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    file.close();
}
