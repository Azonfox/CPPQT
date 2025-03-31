#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // manual_ управление сигналом без QT-Designer
    // При автоматическом названия on_...
    connect(ui->FocusButton, &QPushButton::clicked,
        this, &MainWindow::manual_FocusButton_clicked);

    // Начинаем с поля ввода
    ui->lineEdit->setFocus();
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
void MainWindow::on_TextButton_clicked()
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

// Проверяем выход из поля (типа Valid VFP):
//  изменяем надпись и переходим дальше.
// Далее в UI Designer для editingFinished() стрелкой ставим слот
// setFocus() для следующего виджета -  кнопки "COLOR",
// ...или как здесь - программно переставляем Фокус
void MainWindow::on_lineEdit_editingFinished()
{
    // Если ввели "1" даже с пробелами, то
    // печатаем соотвтетсвующее уведомление
    // в label_1 и не выходим из поля, попутно
    // удаляем все лишние пробелы
    if (ui->lineEdit->text().trimmed()=="1") {
        ui->label_1->setText("Ошибка!\nВведено 1");
        ui->lineEdit->setText("1");
    } else {
        ui->label_1->setText("Выход из\nполя!");
        // и переходим на кнопку "COLOR" программно
        ui->colorButton->setFocus();
    }
}

// Это для Ручного управления через connect(...
// При нажатии на кнопку FocusButton
// переходим на текстовае поле и меняем текст
void MainWindow::manual_FocusButton_clicked()
{
        ui->lineEdit->setFocus();
        ui->lineEdit->setText("FocusButton");
        qDebug() << "Фокус установлен!";
}
