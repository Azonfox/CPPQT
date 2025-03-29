#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


// В ui Designer на этой кнопке ПКМ и "Перейти к слоту..."
// Тогда получаем этот код здесь и в mainwindow.h файле
// Добавляем сюда наш код по типу VFP.
// А в самом ui файле графически стрелками делаем простейшие
// соединения сигналов+слотов, как у нас кнопка для закрытия окна.
void MainWindow::on_pushButton1_clicked()
{
    // При нажатии на кнопку pushButton1  "Моя Button"
    // выводим на терминал текст ...
    qDebug() << "Кнопкень нажжатая!";
    // ...и меняем надпись на форме
    ui->label_1->setText("Кнопкень\nнажжатая!");
}

// При нажатии на кнопку colorButton  "COLOR"
// меняем цвет надписи
void MainWindow::on_colorButton_clicked()
{
    ui->label_1->setStyleSheet("color: red; font-weight: bold;");
}
