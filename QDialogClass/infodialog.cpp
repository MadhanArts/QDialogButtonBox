#include "infodialog.h"
#include "ui_infodialog.h"
#include<QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint|Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_submitButton_clicked()
{
    QString userPosition = ui->positionLineEdit->text();
    if(!userPosition.isEmpty())
    {
        // qDebug() << "In submit";
        position = userPosition;

        if(ui->macRadioButton->isChecked())
        {
            favorite = "Mac";
        }
        if(ui->windowsRadioButton->isChecked())
        {
            favorite = "Windows";
        }
        if(ui->linuxRadioButton->isChecked())
        {
            favorite = "Linux";
        }
    }
    accept();
}

void InfoDialog::on_cancelButton_clicked()
{
    reject();
}

QString InfoDialog::getFavorite() const
{
    return favorite;
}

QString InfoDialog::getPosition() const
{
    return position;
}
