QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttons.cpp \
    dice.cpp \
    interface.cpp \
    main.cpp \
    dnd_encounter.cpp

HEADERS += \
    buttons.h \
    dice.h \
    dnd_encounter.h \
    interface.h

FORMS += \
    dnd_encounter.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../background.jpg \
    ../background.png \
    background.png \
    background.png

RESOURCES += \
    Atacar.qrc \
    Boleadeira.qrc \
    Defender.qrc \
    Intimidar.qrc \
    background.qrc \
    enemy.qrc \
    player.qrc \
    player.qrc
