#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
//    QWidget *w = new QWidget;
     QPushButton button("Click me");
     button.resize(100,100);
 //   w->resize(400,300);
  //  w->setWindowTitle("Azonfox");
   // w->move(100, 100);
  //  w->show();
    button.show();
    return a.exec();
}
