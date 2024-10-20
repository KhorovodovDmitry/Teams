QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorization.cpp \
    funcforclient.cpp \
    generate_for_variant.cpp \
    graf.cpp \
    main.cpp \
    mainwindow.cpp \
    result_client.cpp \
    secant_method.cpp \
    singleton_client.cpp

HEADERS += \
    authorization.h \
    funcforclient.h \
    generate_for_variant.h \
    graf.h \
    mainwindow.h \
    result_client.h \
    secant_method.h \
    singleton_client.h

FORMS += \
    authorization.ui \
    graf.ui \
    mainwindow.ui \
    result_client.ui \
    secant_method.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
