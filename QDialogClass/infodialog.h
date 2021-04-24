#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getPosition() const;

    QString getFavorite() const;

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::InfoDialog *ui;
    QString position;
    QString favorite;
};

#endif // INFODIALOG_H
