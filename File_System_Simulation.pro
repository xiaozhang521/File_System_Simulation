#-------------------------------------------------
#
# Project created by QtCreator 2017-07-05T09:27:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = File_System_Simulation
TEMPLATE = app


SOURCES += main.cpp \
    loginwindow.cpp \
    file_upper_deal.cpp \
    file_manage.cpp \
    text_edit.cpp \
    attribute.cpp

HEADERS  += \
    loginwindow.h \
    file_upper_deal.h \
    file_manage.h \
    text_edit.h \
    attribute.h

FORMS    += \
    loginwindow.ui \
    file_manage.ui \
    text_edit.ui \
    attribute.ui
