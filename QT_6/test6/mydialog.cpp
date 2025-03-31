#include "mydialog.h"
#include "./ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}

// мои Функции при вызове окна Диалога
void myDialog::setLabelText(const QString &text) {
    ui->labelDialog->setText(text);
}
void myDialog::setLabelColor(const QString &color) {
    ui->labelDialog->setStyleSheet(color);
}

