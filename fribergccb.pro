QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    gameendmsg.cpp \
    gamelogic.cpp \
    guessitemdelegate.cpp \
    guessresult.cpp \
    main.cpp \
    mainwindow.cpp \
    statsdialog.cpp \
    statsmanager.cpp

HEADERS += \
    character.h \
    gameendmsg.h \
    gamelogic.h \
    guessitemdelegate.h \
    guessresult.h \
    mainwindow.h \
    statsdialog.h \
    statsmanager.h

FORMS += \
    mainwindow.ui \
    statsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/characters.json \
    characters.json
