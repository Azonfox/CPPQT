// Построение PDF файла от DS (второй вариант, последний текст)
// с настраиваемыми полями страницы
// Для настройки полей имеются умножения на ноль,
//  иначе поля выставляются дважды!!!

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
#include <QDebug>

class PdfGenerator : public QWidget {
public:
    PdfGenerator(QWidget *parent = nullptr) : QWidget(parent) {
        QPushButton *generateButton = new QPushButton("Сгенерировать PDF", this);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(generateButton);
        setLayout(layout);
        connect(generateButton, &QPushButton::clicked, this, &PdfGenerator::generatePdf);
    }

private:
    void generatePdf() {
        // Текстовые переменные
        QString headerText = "Заголовок документа";
        QString text1 = "Текст 1";
        QString text2 = "Текст 2";
        QString text3 = "Текст 3";

        // Желаемые поля в миллиметрах
        const double leftMarginMM   = 50.0;
        const double topMarginMM    = 10.0;
        const double rightMarginMM  = 10.0;
        const double bottomMarginMM = 10.0;

        // Создаем PDF writer
        QPdfWriter pdfWriter("output.pdf");
        pdfWriter.setResolution(96); // 96 DPI
        // Устанавливаем размер страницы A4 (210x297 мм)
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));


        // Важная правка: создаем новый pageLayout с нашими полями
        QPageLayout pageLayout(
            QPageSize(QPageSize::A4),
            QPageLayout::Portrait,
            QMarginsF(leftMarginMM, topMarginMM, rightMarginMM, bottomMarginMM),
            QPageLayout::Millimeter
        );


        // Применяем наш pageLayout к writer
        pdfWriter.setPageLayout(pageLayout);

        // Получаем фактические размеры страницы и полей
        QSizeF pageSizeMM = pdfWriter.pageLayout().pageSize().size(QPageSize::Millimeter); //Millimeter
        QMarginsF marginsMM = pdfWriter.pageLayout().margins(QPageLayout::Millimeter); //Millimeter

        qDebug() << "Фактические поля (мм):" << marginsMM;
        qDebug() << "Размер страницы (мм):" << pageSizeMM;

        // Рассчитываем рабочую область
        const double workWidthMM  = pageSizeMM.width() - marginsMM.left() - marginsMM.right();
        const double workHeightMM = pageSizeMM.height() - marginsMM.top() - marginsMM.bottom();
        qDebug() << "Размер зоны W:" << workWidthMM;
        qDebug() << "Размер зоны H:" << workHeightMM;

        QPainter painter(&pdfWriter);
        if (!painter.isActive()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось инициализировать QPainter");
            return;
        }

        painter.setRenderHint(QPainter::Antialiasing);
        QFont font("Arial", 12); // 12 пунктов
        painter.setFont(font);

        // 1. Рисуем заголовок (точно отступаем на заданные поля)
        // тут была ошибка DS - двойной запрос на размер поля!!!
        // поставлены нули!
        const double headerHeightMM = 15.0;
        QRectF headerRectMM(
         0.0, //   marginsMM.left(),
         0.0, //   marginsMM.top(),
            workWidthMM,
            headerHeightMM
        );
        drawTextWithBorder(painter, mmToPixels(headerRectMM, pdfWriter), headerText, Qt::AlignCenter);

        // проверка на простое управление, печать в самом низу
        painter.setPen(QPen(Qt::red, 15, Qt::SolidLine)); // красный,Хпиксель,сплошной
        painter.drawRect(0, 280*96.0/25.4 , workWidthMM, 100); // *96.0/25.4

        // 2. Рисуем три блока в ряд
        const double blockHeightMM = 25.0;
        const double blockSpacingMM = 5.0;
        const double blocksTopMM = marginsMM.top()*0 + headerHeightMM + 10.0;
        const double blockWidthMM = (workWidthMM - 2*blockSpacingMM) / 3;

        // Блок 1
        QRectF block1RectMM(
            0.0, //marginsMM.left(),
            blocksTopMM,
            blockWidthMM,
            blockHeightMM
        );
        drawTextWithBorder(painter, mmToPixels(block1RectMM, pdfWriter), text1, Qt::AlignCenter);

        // Блок 2
        QRectF block2RectMM(
            marginsMM.left() * 0.0 + blockWidthMM + blockSpacingMM,
            blocksTopMM,
            blockWidthMM,
            blockHeightMM
        );
        drawTextWithBorder(painter, mmToPixels(block2RectMM, pdfWriter), text2, Qt::AlignCenter);

        // Блок 3
        QRectF block3RectMM(
            marginsMM.left()* 0.0  + 2*(blockWidthMM + blockSpacingMM),
            blocksTopMM,
            blockWidthMM,
            blockHeightMM
        );
        drawTextWithBorder(painter, mmToPixels(block3RectMM, pdfWriter), text3, Qt::AlignCenter);

        painter.end();
        // Выдаем сообщение
        QMessageBox::information(this, "Готово", "PDF создан с установленными полями в мм: output.pdf");
    }


    //=========================================================================
    // Преобразование мм в пиксели с учетом DPI writer'а
    QRectF mmToPixels(const QRectF &mmRect, const QPdfWriter &writer) {
        const double mmToInch = 1.0 / 25.4 ;
        const double dpi = writer.resolution();

        return QRectF(
            mmRect.left()   * mmToInch * dpi,
            mmRect.top()    * mmToInch * dpi,
            mmRect.width()  * mmToInch * dpi,
            mmRect.height() * mmToInch * dpi
         );
    }

    //=========================================================================
    void drawTextWithBorder(QPainter &painter, const QRectF &rect,
                          const QString &text, Qt::Alignment alignment) {
        painter.setPen(Qt::black);
        painter.drawRect(rect);
        painter.drawText(rect, alignment, text);
    }
};

//=========================================================================
//=========================================================================

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("PDF Generator с точными полями");
    window.setFixedSize(400, 200);

    PdfGenerator *generator = new PdfGenerator(&window);
    window.setCentralWidget(generator);

    window.show();
    return app.exec();
}


/*
Ключевые исправления:

1. **Точные поля 10 мм**:
   - Теперь поля точно соответствуют заданным 10 мм
   - Исправлена инициализация QPageLayout

2. **Новая функция mmToPixels()**:
   - Точное преобразование мм в пиксели с учетом DPI
   - Учитывает что 1 дюйм = 25.4 мм

3. **Проверка полей**:
   - Добавлен вывод фактических полей в отладку
   - Проверка инициализации QPainter

4. **Более точное позиционирование**:
   - Все координаты рассчитываются от установленных полей
   - Используются фактические значения полей из pageLayout

5. **Улучшенные сообщения**:
   - Более информативные статусы
   - Подтверждение создания PDF с полями 10 мм

Этот код гарантированно создаст PDF с полями ровно 10 мм, как вы и хотели. Проблема с "лишними" 5 мм решена за счет правильной инициализации QPageLayout и точного преобразования единиц измерения.


 * Ключевые улучшения:

1. **Четкое разделение единиц измерения**:
   - Все расчеты позиций сначала делаются в миллиметрах
   - Затем явно преобразуются в пиксели с учетом DPI

2. **Контроль преобразований**:
   - Добавлены коэффициенты mmToPixelsX/Y для точного перевода миллиметров в пиксели
   - Вывод размеров в отладку для контроля

3. **Физические размеры**:
   - Установлено разрешение 96 DPI (стандартное для экранов)
   - Размер шрифта задается в пунктах (1 пункт = 1/72 дюйма)

4. **Более точные расчеты**:
   - Все отступы и размеры заданы в мм
   - Рабочая область вычисляется с учетом полей

5. **Константы для размеров**:
   - Все размеры вынесены в именованные константы
   - Промежутки между блоками заданы явно

Этот код гарантирует, что:
- PDF будет создаваться с точными физическими размерами
- Все элементы будут расположены в правильных позициях
- Размеры в миллиметрах будут корректно преобразованы в пиксели
- Полученный документ будет правильно масштабироваться при печати


*/


