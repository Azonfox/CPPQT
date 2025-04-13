// Построение PDF файла от DS первый вариант без полей страницы
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QRect>

void generatePDF() {
    // Текстовые переменные для вывода в PDF
    QString headerText = "Заголовок документа без полей DS1";
    QString text1 = "Текст 00000 0 0 0 0 0 0 00  -111";
    QString text2 = "Текст 222";
    QString text3 = ">>Текст 333";

    // Выбор места сохранения файла - пока отключим
    //QString fileName = QFileDialog::getSaveFileName(nullptr, "Сохранить PDF", "", "PDF файлы (*.pdf)");
    //if (fileName.isEmpty())
    //    return;

    // Создание файла PDF-документа
    QPdfWriter pdfWriter("111.pdf"); // было QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300); // 300 DPI

    QPainter painter(&pdfWriter);


/*  DS2
 *     // Настройки полей страницы (в миллиметрах)
    double leftMargin = 70.0;
    double topMargin = 20.0;
    double rightMargin = 20.0;
    double bottomMargin = 20.0;
    // Настраиваем поля страницы
    QPageLayout pageLayout = pdfWriter.pageLayout();
    pageLayout.setMargins(QMarginsF(leftMargin, topMargin, rightMargin, bottomMargin));
    pageLayout.setUnits(QPageLayout::Millimeter);
    pdfWriter.setPageLayout(pageLayout);
*/



    // Установка шрифтов
    QFont headerFont("Arial", 16, QFont::Bold);
    QFont textFont("Courier", 12);

    // Рисуем заголовок вверху листа
    painter.setFont(headerFont);
    painter.drawText(QRect(0, 70, pdfWriter.width(), 70), Qt::AlignCenter, headerText);

    // Рисуем спецпером горизонтальную линию под заголовком
    painter.setPen(QPen(Qt::red, 15, Qt::SolidLine)); // красный,Хпиксель,сплошной
    painter.drawLine(50, 150, pdfWriter.width() - 50, 330);

    // Вычисляем ширину для трех колонок
    int columnWidth = (pdfWriter.width() - 200) / 3; // 200 - отступы слева и справа
    int startY = 400; // От верха

    // Рисуем три текстовых блока в один ряд
    painter.setFont(textFont);

    // Первый блок с рамкой
    painter.setPen(QPen(Qt::blue,6));
    painter.drawRect(50, startY, columnWidth, 100);
    painter.setPen(QPen(Qt::green,10));
    painter.drawText(QRect(50, startY, columnWidth, 100), Qt::AlignRight, text1);

    // Второй блок с рамкой (с отступом)
    painter.setPen(QPen(Qt::yellow,30));
    painter.drawRect(100 + columnWidth, startY, columnWidth, 100);
    painter.drawText(QRect(100 + columnWidth, startY, columnWidth, 100), Qt::AlignCenter, text2);

    // Третий блок с рамкой (с отступом)
    painter.setPen(QPen(Qt::black,15));
    painter.drawRect(150 + 2 * columnWidth, startY, columnWidth, 100);
    // Выводим текст со смещением 111
    painter.drawText(QRect(150+111 + (2 * columnWidth), startY, columnWidth, 100), Qt::AlignLeft, text3);

    painter.end();
    // Закрыть приложение при отладке сразу же, чтоб не болталось
    QCoreApplication::quit();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем главное окно
    QWidget window;
    window.setWindowTitle("Генератор PDF_DS1");
    window.resize(300, 200);

    // Создаем кнопку
    QPushButton button("Создать PDF", &window);
    button.setGeometry(50, 50, 200, 50);

    // Подключаем сигнал кнопки к функции генерации PDF
    QObject::connect(&button, &QPushButton::clicked, &generatePDF);

    window.show();
    return app.exec();
}
