######################################################################
# Automatically generated by qmake (3.1) Mon Dec 25 20:17:17 2023
######################################################################

TEMPLATE = app
TARGET = win
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += mainwindow.h
FORMS += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp
QT+=gui widgets

#For Mac12 QT5142 без этих двух волшебных строк запускается в трее и не работает
#CONFIG+=sdk_no_version_check
#QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
