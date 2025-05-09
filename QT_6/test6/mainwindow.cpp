#include "mydialog.h"
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
    // Для того-же сигнала второй отладочный обработчик
    connect(ui->FocusButton, &QPushButton::clicked,
        this, &MainWindow::manual_FocusButton_clicked_debug);

    // Начинаем с поля ввода
    ui->lineEdit->setFocus();

    // Устанавливаем цвет фона
    //this->setStyleSheet("background-color: green;");
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
// читаем и меняем цвет надписи на другой
void MainWindow::on_colorButton_clicked()
{
    QColor textColor=ui->label_1->palette().color(QPalette::WindowText);
    qDebug() << "Цвет текста " << textColor.name();
    if(textColor.name()=="#ff0000")
        ui->label_1->setStyleSheet("color: blue; font-weight: bold;");
    else
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
        qDebug() << "Фокус первый обработчик";
}
// Для того-же сигнала второй обработчик
void MainWindow::manual_FocusButton_clicked_debug()
{
        qDebug() << "Фокус debug обработчик--------";
}

void MainWindow::on_dialogButton_clicked()
{
    qDebug() << "DIALOG WINDOW";
    myDialog dialog(this);
    // Передаем в диалоговое окно текст и цвет текста
    dialog.setLabelText("Передан текст и цвет");
    dialog.setLabelColor("color: red; font-weight: bold");

    dialog.exec(); // Модальное
//    dialog.show(); // nnnn
}

