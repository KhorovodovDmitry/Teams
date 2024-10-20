QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT       += core gui network

SOURCES += \
    authregform.cpp \
    functionsforclient.cpp \
    main.cpp \
    mainwindow.cpp \
    net.cpp \
    stat.cpp \
    task1.cpp \
    task2.cpp

HEADERS += \
    authregform.h \
    functionsforclient.h \
    mainwindow.h \
    net.h \
    stat.h \
    task1.h \
    task2.h

FORMS += \
    authregform.ui \
    mainwindow.ui \
    stat.ui \
    task1.ui \
    task2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
