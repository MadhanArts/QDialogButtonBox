#include "infodialog.h"
#include "ui_infodialog.h"
#include <QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton=ui->buttonBox->standardButton(button);

    if(stdButton==QDialogButtonBox::Ok)
    {
        accept();
        qDebug()<<"Ok button clicked";
    }

    if(stdButton==QDialogButtonBox::Save)
    {
        qDebug()<<"Save button clicked";
    }

    if(stdButton==QDialogButtonBox::SaveAll)
    {
        qDebug()<<"Save All button clicked";
    }

    if(stdButton==QDialogButtonBox::Open)
    {
        qDebug()<<"Open button clicked";
    }

    if(stdButton==QDialogButtonBox::No)
    {
        qDebug()<<"No button clicked";
    }

    if(stdButton==QDialogButtonBox::NoToAll)
    {
        qDebug()<<"No To All button clicked";
    }

    if(stdButton==QDialogButtonBox::Cancel)
    {
        reject();
        qDebug()<<"Cancel button clicked";
    }
}
