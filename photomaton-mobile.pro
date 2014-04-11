folder_01.source = qml/photomaton-mobile
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = photomaton-mobile
#TEMPLATE = app


SOURCES += main.cpp\
    graphicsview.cpp \
    application.cpp \
    graphicsscene.cpp \
    gphoto/abstractgphotocommand.cpp \
    gphoto/gphotocameracontroller.cpp \
    gphoto/gphotocommandthread.cpp \
    gphoto/gphotocamerahandle.cpp \
    gphoto/commands/gphotolistcamerascommand.cpp \
    gphoto/commands/gphotoopencameracommand.cpp \
    gphoto/commands/gphotocapturepreviewcommand.cpp \
    liveview.cpp

HEADERS  += \
    graphicsview.h \
    application.h \
    graphicsscene.h \
    gphoto/abstractgphotocommand.h \
    gphoto/gphotocameracontroller.h \
    gphoto/gphotocommandthread.h \
    gphoto/gphotocamerahandle.h \
    gphoto/commands/gphotolistcamerascommand.h \
    gphoto/commands/gphotoopencameracommand.h \
    gphoto/commands/gphotocapturepreviewcommand.h \
    liveview.h

#FORMS    += mainwindow.ui

LIBS     += -lgphoto2_port -lgphoto2

android {
    INCLUDEPATH += /home/romain/Projets/android/agphoto2/jni/libgphoto2/ \
                   /home/romain/Projets/android/agphoto2/jni/libgphoto2/libgphoto2_port/

    LIBS += -L/home/romain/Projets/android/agphoto2/libs/armeabi/

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}


#RESOURCES += photomaton-mobile.qrc

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

ANDROID_EXTRA_LIBS = ../../android/agphoto2/libs/armeabi/libcanon.so ../../android/agphoto2/libs/armeabi/libcasio.so ../../android/agphoto2/libs/armeabi/libdc120.so ../../android/agphoto2/libs/armeabi/libdc210.so ../../android/agphoto2/libs/armeabi/libdc240.so ../../android/agphoto2/libs/armeabi/libdc3200.so ../../android/agphoto2/libs/armeabi/libexif2.so ../../android/agphoto2/libs/armeabi/libez200.so ../../android/agphoto2/libs/armeabi/libfuji.so ../../android/agphoto2/libs/armeabi/libgphoto2_port.so ../../android/agphoto2/libs/armeabi/libgphoto2.so ../../android/agphoto2/libs/armeabi/libkonica.so ../../android/agphoto2/libs/armeabi/libltdl.so ../../android/agphoto2/libs/armeabi/libptp2.so ../../android/agphoto2/libs/armeabi/libptpip.so ../../android/agphoto2/libs/armeabi/libqm150.so ../../android/agphoto2/libs/armeabi/libregex.so ../../android/agphoto2/libs/armeabi/libusb.so ../../android/agphoto2/libs/armeabi/libusb2.so

OTHER_FILES += \
    android/AndroidManifest.xml
