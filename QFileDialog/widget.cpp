#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // To open multiple files
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Select one or more files"),
                                                      "E://",
                                                      "Images (*.jpg *.png) ;; Text Files (*.txt)");
    qDebug() << "Choosen files are : " << files;

}

void Widget::on_pushButton_2_clicked()
{
    // To open an Existing directory
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "C://",
                                                    QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    qDebug() << "Choosen Directory is : " << dir;
}

void Widget::on_pushButton_4_clicked()
{
    // To open a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QDir::homePath(), tr("Images (*.jpg *.png)"));
    qDebug() << "Choosen File is : " << fileName;
}

void Widget::on_pushButton_3_clicked()
{
    // To Save a file
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "C://", "Text Files (*.txt) ;; Image Files (*.jpg *.png)");
    qDebug() << "Choosen files path : " << fileName;

    QFile file(fileName);
    file.open(QFile::WriteOnly|QFile::Text);

    QTextStream out(&file);
    out << "Hello";
    file.close();


}
