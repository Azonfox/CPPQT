QT       += core gui widgets sql printsupport
CONFIG += c++11
#CONFIG -=app_bundle
SOURCES += main.cpp
TARGET = test1
TEMPLATE = app

#For Mac12 QT5142 без этих двух волшебных строк запускается в трее и не работает
CONFIG+=sdk_no_version_check
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

