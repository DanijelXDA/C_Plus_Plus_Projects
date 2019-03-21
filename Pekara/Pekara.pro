#-------------------------------------------------
#
# Project created by QtCreator 2019-01-07T11:12:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pekara
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        glavniprozor.cpp \
    magacindodaj.cpp \
    magacinazuriraj.cpp \
    konekcija.cpp \
    magacinpregled.cpp \
    proizvoddodaj.cpp \
    proizvodazuriraj.cpp \
    proizvodpregled.cpp \
    proizvodukloni.cpp \
    gproizvoddodaj.cpp \
    gproizvodazuriraj.cpp \
    gproizvodukloni.cpp \
    gproizvodpregled.cpp \
    istorijaizmenamagacin.cpp \
    trebovanjemagacin.cpp \
    trebovanjegproizvod.cpp \
    otpis.cpp \
    prodajamaloprodaja.cpp \
    izborprodavca.cpp

HEADERS += \
        glavniprozor.h \
    magacindodaj.h \
    magacinazuriraj.h \
    konekcija.h \
    magacinpregled.h \
    proizvoddodaj.h \
    proizvodazuriraj.h \
    proizvodpregled.h \
    proizvodukloni.h \
    gproizvoddodaj.h \
    gproizvodazuriraj.h \
    gproizvodukloni.h \
    gproizvodpregled.h \
    istorijaizmenamagacin.h \
    trebovanjemagacin.h \
    trebovanjegproizvod.h \
    otpis.h \
    prodajamaloprodaja.h \
    izborprodavca.h

FORMS += \
        glavniprozor.ui \
    magacindodaj.ui \
    magacinazuriraj.ui \
    magacinpregled.ui \
    proizvoddodaj.ui \
    proizvodazuriraj.ui \
    proizvodpregled.ui \
    proizvodukloni.ui \
    gproizvoddodaj.ui \
    gproizvodazuriraj.ui \
    gproizvodukloni.ui \
    gproizvodpregled.ui \
    istorijaizmenamagacin.ui \
    trebovanjemagacin.ui \
    trebovanjegproizvod.ui \
    otpis.ui \
    prodajamaloprodaja.ui \
    izborprodavca.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resursi.qrc
