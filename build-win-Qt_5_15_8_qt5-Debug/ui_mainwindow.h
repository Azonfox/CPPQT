/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QLabel *label;
    QToolButton *toolButton;
    QCommandLinkButton *commandLinkButton;
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QSlider *horizontalSlider;
    QScrollBar *verticalScrollBar;
    QSplitter *splitter;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(393, 366);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 70, 102, 24));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 100, 102, 24));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(170, 100, 85, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 331, 37));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        label->setFrameShadow(QFrame::Sunken);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(280, 150, 41, 41));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(160, 70, 168, 41));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 210, 166, 26));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 130, 256, 71));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 260, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(350, 90, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 280, 371, 26));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"color: rgb(165, 29, 45);\n"
""));
        splitter->addWidget(pushButton);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 393, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Azonfox Window", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#e01b24;\">\320\237\320\265\321\200\320\262\320\276\320\265 \320\276\320\272\320\276\321\210\320\272\320\276</span></p></body></html>", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "CommandLinkButton", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
