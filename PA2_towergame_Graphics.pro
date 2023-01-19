QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloodminusitem.cpp \
    closetoweritem.cpp \
    creatureitem.cpp \
    fartoweritem.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    monsteritem.cpp \
    mygamescene.cpp \
    mygraphicsview.cpp \
    myitem.cpp \
    settingsdialog.cpp

HEADERS += \
    bloodminusitem.h \
    closetoweritem.h \
    creatureitem.h \
    fartoweritem.h \
    gamescene.h \
    mainwindow.h \
    monsteritem.h \
    mygamescene.h \
    mygraphicsview.h \
    myitem.h \
    settingsdialog.h

FORMS += \
    gamescene.ui \
    mainwindow.ui \
    settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
