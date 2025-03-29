#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // В ui Designer на этой кнопке ПКМ и "Перейти к слоту..."
    // Тогда получаем этот код здесь и в mainwindow.cpp файле
    // Добавляем наш код по типу VFP в mainwindow.cpp
    void on_pushButton1_clicked();

    void on_colorButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
