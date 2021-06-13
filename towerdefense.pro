QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = towerdefense
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    bullet2.cpp \
    bullet3.cpp \
    enemy.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    myrule.cpp \
    selectbutton.cpp \
    selectbutton2.cpp \
    tower.cpp \
    tower2.cpp \
    tower3.cpp \
    towerposition.cpp \
    waypoint.cpp

HEADERS += \
    bullet.h \
    bullet2.h \
    bullet3.h \
    enemy.h \
    form.h \
    mainwindow.h \
    myrule.h \
    selectbutton.h \
    selectbutton2.h \
    tower.h \
    tower2.h \
    tower3.h \
    towerposition.h \
    utility.h \
    waypoint.h

FORMS += \
    form.ui \
    mainwindow.ui \
    myrule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

