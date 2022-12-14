QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/gwngui.cpp

HEADERS += \
    src/gwngui.h

FORMS += \
    src/forms/gwngui.ui

TRANSLATIONS += \
    src/res/locale/GreatWhiteNorth_en_150.ts
    
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = src/res/images/ca-round.ico

RESOURCES += \
    src/res/gwn.qrc
