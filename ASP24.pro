QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/cpp/cdatetimeedit.cpp \
    src/cpp/cframe.cpp \
    src/cpp/cgroupbox.cpp \
    src/cpp/clabel.cpp \
    src/cpp/clineedit.cpp \
    src/cpp/cpushbutton.cpp \
    src/cpp/ctablewidget.cpp \
    src/cpp/ctabwidget.cpp \
    src/cpp/db.cpp \
    src/cpp/histogramview.cpp \
    src/cpp/main.cpp \
    src/cpp/mainview.cpp \
    src/cpp/scanview.cpp \
    src/cpp/statview.cpp

HEADERS += \
    src/h/cdatetimeedit.h \
    src/h/cframe.h \
    src/h/cgroupbox.h \
    src/h/clabel.h \
    src/h/clineedit.h \
    src/h/cpushbutton.h \
    src/h/ctablewidget.h \
    src/h/ctabwidget.h \
    src/h/cwidgets.h \
    src/h/db.h \
    src/h/histogramview.h \
    src/h/mainview.h \
    src/h/scanview.h \
    src/h/statview.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/resources.qrc
