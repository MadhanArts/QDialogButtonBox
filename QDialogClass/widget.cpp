#include "widget.h"
#include "ui_widget.h"
#include <infodialog.h>
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


void Widget::on_provideInfoPushButton_clicked()
{
    // Modal
    /*InfoDialog *dialog = new InfoDialog(this);
    dialog->setModal(true);
    int result = dialog->exec();
    if(result == QDialog::Accepted)
    {
        QString position = dialog->getPosition();
        QString favorite = dialog->getFavorite();

        qDebug() << "Dialog Accepted.... Position is : " << position << " and favorite OS: " << favorite;
        ui->infoLabel->setText("Your Position is : " + position + " and Your Favorite OS is : " + favorite);

    }
    else
    {
        qDebug() << "Dialog Rejected";
    }*/



    // Non Modal
    InfoDialog *dialog = new InfoDialog(this);

    connect(dialog, &InfoDialog::accepted, [=](){
        QString position = dialog->getPosition();
        QString favorite = dialog->getFavorite();
        qDebug() << "Dialog Accepted.... Position is : " << position << " and favorite OS: " << favorite;
        ui->infoLabel->setText("Your Position is : " + position + " and Your Favorite OS is : " + favorite);

    });

    connect(dialog, &InfoDialog::rejected, [=](){
        qDebug() << "Dialog Rejected";
    });

    dialog->show();
    dialog->raise();
    dialog->activateWindow();

}
