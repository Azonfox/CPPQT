#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QPageSize>
#include <QPageLayout>

void generatePdf(const QString &filePath) {
    // Настройки полей
    const int leftMargin   = 20;
    const int topMargin    = 20;
    const int rightMargin  = 10;
    const int bottomMargin = 20;

    // Размер листа A4
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(leftMargin, topMargin, rightMargin, bottomMargin), QPageLayout::Point);

    QPainter painter(&writer);

    // Текстовые переменные
    QString topText = "Верхний текст";
    QString var1 = "Переменная 1";
    QString var2 = "Переменная 2";
    QString var3 = "Переменная 3";

    // Получаем рабочую область
    QRectF pageRect = writer.pageLayout().paintRectPixels(writer.resolution());

    // Настройки шрифта  и пера
    QFont font("Arial", 18);
    painter.setFont(font);
    painter.setPen(QPen(Qt::black,15));

    // Верхний текст
    QRect topBox(pageRect.left(), pageRect.top(), pageRect.width()/2, 350);
    painter.drawRect(topBox);
    painter.drawText(topBox, Qt::AlignCenter, topText);

    // Три текста в один ряд
    int spacing = 20;
    int boxWidth = (pageRect.width() - 2 * spacing) / 3;
    int boxHeight = 350;
    int startY = topBox.bottom() + 350;

    QRect box1(pageRect.left(), startY, boxWidth, boxHeight);
    QRect box2(box1.right() + spacing, startY, boxWidth, boxHeight);
    QRect box3(box2.right() + spacing, startY, boxWidth, boxHeight);

    painter.drawRect(box1);
    painter.drawRect(box2);
    painter.drawRect(box3);

    painter.drawText(box1, Qt::AlignCenter, var1);
    painter.drawText(box2, Qt::AlignCenter, var2);
    painter.drawText(box3, Qt::AlignCenter, var3);

    painter.end();
    // Закрыть приложение при отладке сразу же, чтоб не болталось
    QCoreApplication::quit();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("PDF Generator GPT");

    QPushButton *button = new QPushButton("Создать PDF");
//    button->setGeometry(50, 150, 200, 150);
    QObject::connect(button, &QPushButton::clicked, [&]() {
       generatePdf("111.pdf");
    });

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    window.setLayout(layout);
    window.resize(300, 100);
    window.show();

    return app.exec();
}
