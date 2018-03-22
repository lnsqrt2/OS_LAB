QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaskManager
TEMPLATE = app


SOURCES += main.cpp\
        taskmanager.cpp

HEADERS  += taskmanager.h

FORMS    += taskmanager.ui

CONFIG += C++11
