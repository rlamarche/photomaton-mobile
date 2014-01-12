#-------------------------------------------------
#
# Project created by QtCreator 2014-01-12T16:57:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = photomaton-mobile
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicsview.cpp \
    application.cpp \
    graphicsscene.cpp \
    widgets/cameraselectorwidget.cpp \
    gphoto/abstractgphotocommand.cpp \
    gphoto/gphotocameracontroller.cpp \
    gphoto/gphotocommandthread.cpp \
    gphoto/gphotocamerahandle.cpp \
    gphoto/commands/gphotolistcamerascommand.cpp

HEADERS  += mainwindow.h \
    graphicsview.h \
    application.h \
    graphicsscene.h \
    widgets/cameraselectorwidget.h \
    gphoto/abstractgphotocommand.h \
    gphoto/gphotocameracontroller.h \
    gphoto/gphotocommandthread.h \
    gphoto/gphotocamerahandle.h \
    gphoto/commands/gphotolistcamerascommand.h

FORMS    += mainwindow.ui

LIBS     += -lgphoto2_port -lgphoto2
