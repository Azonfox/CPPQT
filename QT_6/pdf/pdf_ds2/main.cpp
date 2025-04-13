// Построение PDF файла от DS второй вариант с полями страницы

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QPageSize>
#include <QPageLayout>

class PdfGenerator : public QWidget {
public:
    PdfGenerator(QWidget *parent = nullptr) : QWidget(parent) {
        // Создаем кнопку
        QPushButton *generateButton = new QPushButton("Сгенерировать PDF", this);

        // Настраиваем layout
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(generateButton);
        setLayout(layout);

        // Подключаем сигнал кнопки к слоту генерации PDF
        connect(generateButton, &QPushButton::clicked, this, &PdfGenerator::generatePdf);
    }

private:
    void generatePdf() {
        // Текстовые переменные для вывода в PDF
        QString headerText = "Заголовок документа";
        QString text1 = "Текст 1";
        QString text2 = "Текст 2";
        QString text3 = "Текст 3";

        // Настройки полей страницы (в миллиметрах)
        double leftMargin = 20.0;
        double topMargin = 20.0;
        double rightMargin = 20.0;
        double bottomMargin = 20.0;

        // Создаем PDF writer
        QPdfWriter pdfWriter("output.pdf");
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));

        // Настраиваем поля страницы
        QPageLayout pageLayout = pdfWriter.pageLayout();
        pageLayout.setMargins(QMarginsF(leftMargin, topMargin, rightMargin, bottomMargin));
        pageLayout.setUnits(QPageLayout::Millimeter);
        pdfWriter.setPageLayout(pageLayout);

        // Получаем размеры страницы в миллиметрах
        QSizeF pageSize = pageLayout.pageSize().size(QPageSize::Millimeter);

        // Рассчитываем область для рисования (с учетом полей)
        double paintWidth = pageSize.width() - leftMargin - rightMargin;
        double paintHeight = pageSize.height() - topMargin - bottomMargin;

        // Создаем painter для рисования в PDF
        QPainter painter(&pdfWriter);

        // Настраиваем шрифт
        QFont font("Arial", 12);
        painter.setFont(font);

        // Рисуем заголовок (верхняя часть листа)
        QRectF headerRect(leftMargin, topMargin, paintWidth, 30);
        drawTextWithBorder(painter, headerRect, headerText, Qt::AlignCenter);

        // Рисуем три текстовых блока в один ряд (ниже заголовка)
        double blockWidth = (paintWidth - 20) / 3; // -20 для промежутков
        double blockHeight = 50;
        double startY = headerRect.bottom() + 10;

        // Первый блок
        QRectF block1Rect(leftMargin, startY, blockWidth, blockHeight);
        drawTextWithBorder(painter, block1Rect, text1, Qt::AlignCenter);

        // Второй блок
        QRectF block2Rect(leftMargin + blockWidth + 10, startY, blockWidth, blockHeight);
        drawTextWithBorder(painter, block2Rect, text2, Qt::AlignCenter);

        // Третий блок
        QRectF block3Rect(leftMargin + 2*(blockWidth + 10), startY, blockWidth, blockHeight);
        drawTextWithBorder(painter, block3Rect, text3, Qt::AlignCenter);

        // Завершаем рисование
        painter.end();

        QMessageBox::information(this, "Готово", "PDF файл успешно создан: output.pdf");
    }

    // Вспомогательная функция для рисования текста с рамкой
    void drawTextWithBorder(QPainter &painter, const QRectF &rect,
                           const QString &text, Qt::Alignment alignment) {
        // Рисуем рамку
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        // Рисуем текст
        painter.drawText(rect, alignment, text);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("PDF Generator");
    window.setFixedSize(300, 150);

    PdfGenerator *generator = new PdfGenerator(&window);
    window.setCentralWidget(generator);

    window.show();
    return app.exec();
}
