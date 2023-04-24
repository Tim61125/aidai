QT += location
QT += positioning
QT += core gui svg
QT += svgwidgets
QT += widgets
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets
CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mainwindow.cpp\
    demoitem.cpp \
    main.cpp \
#    mainwindow.cpp \
    selectordialog.cpp \
    samples/background.cpp \
    samples/customtiles.cpp \
    samples/ellipse.cpp \
    samples/flags.cpp \
    samples/items.cpp \
    samples/mouse.cpp \
    samples/mytiles.cpp \
    samples/mytile.cpp \
    samples/placemark.cpp \
    samples/rectangle.cpp \
    samples/utilities.cpp \
    samples/waveanimation.cpp \
    samples/widgets.cpp

HEADERS += \
    mainwindow.h\
    demoitem.h \
#    mainwindow.h \
    selectordialog.h \
    samples/background.h \
    samples/customtiles.h \
    samples/ellipse.h \
    samples/flags.h \
    samples/items.h \
    samples/mouse.h \
    samples/mytiles.h \
    samples/mytile.h \
    samples/placemark.h \
    samples/rectangle.h \
    samples/utilities.h \
    samples/widgets.h
FORMS += \
    mainwindow.ui

include(C:/Users/acer/Documents/NanoSpace/qfi/qfi.pri)
include(C:/Users/acer/Documents/NanoSpace/lib/lib.pri)
INCLUDEPATH += C:/Qt/Docs/Qt-6.5.0/qtlocation
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc
