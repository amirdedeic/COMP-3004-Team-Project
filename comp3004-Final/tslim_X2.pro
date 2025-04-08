#-------------------------------------------------
# Fixed Insulin Pump Simulator Application
#-------------------------------------------------
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tslim_X2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

# Add Qt include paths
INCLUDEPATH += $$[QT_INSTALL_HEADERS]

HEADERS += \
    src/simulation.h \
    src/insulinpump.h \
    src/dbmanager.h \
    src/mainwindow.h \
    src/homescreen.h \
    src/boluscalculator.h \
    src/screenmanager.h

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/simulation.cpp \
    src/insulinpump.cpp \
    src/dbmanager.cpp \
    src/homescreen.cpp \
    src/boluscalculator.cpp \
    src/screenmanager.cpp

FORMS += \
    ui/mainwindow.ui \
    ui/homescreen.ui \
    ui/boluscalculator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target 