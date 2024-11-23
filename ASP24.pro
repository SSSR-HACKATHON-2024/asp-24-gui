QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cdatetimeedit.cpp \
    cframe.cpp \
    cgroupbox.cpp \
    clabel.cpp \
    clineedit.cpp \
    cpushbutton.cpp \
    ctablewidget.cpp \
    ctabwidget.cpp \
    histogram.cpp \
    main.cpp \
    mainview.cpp \
    tasksview.cpp

HEADERS += \
    cdatetimeedit.h \
    cframe.h \
    cgroupbox.h \
    clabel.h \
    clineedit.h \
    cpushbutton.h \
    ctablewidget.h \
    ctabwidget.h \
    cwidgets.h \
    histogram.h \
    mainview.h \
    tasksview.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
