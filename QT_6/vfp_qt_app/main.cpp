/* Программа в стиле VFP для Qt6.4.2 от ChatGPT

 Это простое приложение в ОДНОМ! main.cpp файле ,
  которое:
  открывает или создаёт базу SQLite в каталоге построения,
  показывает данные в QTableView основной формы,
  позволяет добавлять записи в другой форме,
  позволяет распечатать отчёт или сохранить его как PDF — всё
  через QTextDocument.
  Необходимо иметь библиотеки и записи в файле проекта.
*/
// main.cpp
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QLineEdit>
#include <QFormLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QPrintDialog>

#include <QPageSize>
#include <QPageLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QFontDatabase>


QSqlDatabase setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sample.db");
    db.open();
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS people (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)");
    return db;
}


QString generateHtmlReport(QSqlTableModel *model) {
    QString html = "<html><body style='margin: 10px;'>";
    html += "<h2>Отчёт: Список людей</h2>";
    html +="<b><font face='Arial' size='7' color='red'> Azfox </font></b>";
    html += "<table width='100%' border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr style='font-family: Arial; font-size: 8pt;'>";
    html += "<th>ID</th><th>Имя</th><th>Возраст</th></tr>";
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr style='font-family: Courier; font-size: 10pt;'>";
        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

/*      html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";

        html += "<td>" + model->data(model->index(row, 0)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 1)).toString() + "</td>";
        html += "<td>" + model->data(model->index(row, 2)).toString() + "</td>";
*/
        html += "</tr>";
    }
    html += "</table></body></html>";
    return html;
}

void printReport(QSqlTableModel *model) {
    QTextDocument doc;
    doc.setHtml(generateHtmlReport(model));

    QPrinter printer;
    QPrintDialog dialog(&printer);
    if (dialog.exec() == QDialog::Accepted) {
        doc.print(&printer);
    }
}

void exportPdf(QSqlTableModel *model) {
    QTextDocument doc;
    doc.setHtml(generateHtmlReport(model));
    // Настроим размер листа и общие поля
    doc.setPageSize(QSizeF(210*2.83465,297*2.83465));
    doc.setDocumentMargin(10);
    // Общие шрифты документа
    QFont defaultFont("Arial",10);
    doc.setDefaultFont(defaultFont);
    QFontDatabase database;
       qDebug()<< database.families();

    // Вывод в HTML файл для контроля PDF принтера
    if(true){
        QFile debugFile("debug.html");
        debugFile.open(QIODevice::WriteOnly);
        debugFile.write(doc.toHtml().toUtf8());
        debugFile.close();
    }

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Сохранить как PDF", "", "PDF Files (*.pdf)");
    if (!fileName.isEmpty()) {
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        // Разные способы изменения полей
         // Размер = контенту
        printer.setPageSize(QPageSize(QPageSize::A4));
        // Задаем поля в миллиметрах
        printer.setPageMargins(QMarginsF(25,0,0,0),QPageLayout::Millimeter);

        // на весь лист, отменяя поля
        //printer.setFullPage(true);

        // Точная печать и прочее
//        QSizeF contentSize = doc.size();
//        printer.setPageSize(QPageSize(contentSize,QPageSize::Point));

        doc.print(&printer); // Выполнить
        // Закрыть приложение при отладке сразу же, чтоб не болталось
        QCoreApplication::quit();
    }
}



void addRecord(QSqlTableModel *model) {
    QDialog dialog;
    dialog.setWindowTitle("Добавить запись");
    QFormLayout form;
    QLineEdit *editName = new QLineEdit;
    QLineEdit *editAge = new QLineEdit;
    form.addRow("Имя:", editName);
    form.addRow("Возраст:", editAge);
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    form.addWidget(&buttonBox);
    dialog.setLayout(&form);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, [&]() {
        QString name = editName->text();
        int age = editAge->text().toInt();
        if (!name.isEmpty()) {
            QSqlQuery query;
            query.prepare("INSERT INTO people (name, age) VALUES (?, ?)");
            query.addBindValue(name);
            query.addBindValue(age);
            query.exec();
            model->select();
        }
        dialog.accept();
    });
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    dialog.exec();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont font("Arial",14);
    app.setFont(font);
    QMainWindow window;
    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(central);

    QSqlDatabase db = setupDatabase();
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);
    model->setTable("people");
    model->select();

    QTableView *table = new QTableView;
    table->setModel(model);
    layout->addWidget(table);

    QPushButton *btnAdd = new QPushButton("Добавить запись");
    QPushButton *btnPrint = new QPushButton("Печать отчёта");
    QPushButton *btnPdf = new QPushButton("Сохранить в PDF");
    layout->addWidget(btnAdd);
    layout->addWidget(btnPrint);
    layout->addWidget(btnPdf);

    QObject::connect(btnAdd, &QPushButton::clicked, [&]() { addRecord(model); });
    QObject::connect(btnPrint, &QPushButton::clicked, [&]() { printReport(model); });
    QObject::connect(btnPdf, &QPushButton::clicked, [&]() { exportPdf(model); });

    window.setCentralWidget(central);
    window.resize(600, 400);
    window.setWindowTitle("VFP-style app на Qt");
    window.show();

    return app.exec();
}
