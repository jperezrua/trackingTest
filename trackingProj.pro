#-------------------------------------------------
#
# Project created by QtCreator 2013-11-26T21:04:02
#
#-------------------------------------------------

QT       += core gui

TARGET = bin/trackingProject
TEMPLATE = app

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/lib/*.cpp

HEADERS  += includes/mainwindow.h\
            src/lib/*.hpp

FORMS    += ui/mainwindow.ui

INCLUDEPATH += includes \
            src/lib
unix {
#    CONFIG += link_pkgconfig
#    PKGCONFIG += opencv
INCLUDEPATH += /usr/local/include/opencv/ \
            /usr/local/include/opencv2/
LIBS+=-L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_objdetect \
    -lgomp \
    -lopencv_nonfree \
    -lopencv_features2d \
    -lopencv_flann \
    -lopencv_calib3d \
    -lopencv_shape \
    -lopencv_tracking \
    -lopencv_video \
    -lm
}

OBJECTS_DIR += objects
RESOURCES += resources/list.qrc
