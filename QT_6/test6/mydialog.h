#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = nullptr);
    // Способ передачи текста новому окну
    void setLabelText(const QString &text);
    void setLabelColor(const QString &color);

  ~myDialog();

private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
