
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QT       += core gui widgets
CONFIG += c++11
#CONFIG -=app_bundle
SOURCES += main.cpp
TARGET = test1
TEMPLATE = app

#For Mac12 QT5142 без этих двух волшебных строк запускается в трее и не работает
CONFIG+=sdk_no_version_check
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15


#DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
