QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = B25
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        glavniprozor.cpp\
        konekcija.cpp \
    profesori.cpp \
    profesorikojiimajumail.cpp

HEADERS += \
        glavniprozor.h\
        konekcija.h \
    profesori.h \
    profesorikojiimajumail.h

FORMS += \
        glavniprozor.ui \
    profesori.ui \
    profesorikojiimajumail.ui
