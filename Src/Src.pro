#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T19:19:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = properties
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editor.cpp \
    line.cpp \
    rect.cpp

HEADERS  += mainwindow.h \
    editor.h \
    line.h \
    rect.h

exists("$$PWD/../QtnProperty/QtnProperty.pri") {
    include("$$PWD/../QtnProperty/QtnProperty.pri")
    PEG_TOOL = $$PWD/../QtnProperty/bin-win/QtnPEG.exe
    include($$PWD/../QtnProperty/PEG.pri)
} else {
    error("QtnProperty is not found. Did you forget to 'git submodule init/update'")
}

PEG_SOURCES += Properties/Example.pef
