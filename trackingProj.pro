#-------------------------------------------------
#
# Project created by QtCreator 2013-11-26T21:04:02
#
#-------------------------------------------------
QT += widgets core gui
QT += multimedia
CONFIG += qt staticlib

TARGET = bin/trackingProject
TEMPLATE = app

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/lib/mcv_tracker.cpp\
        src/lib/meanShift_tracker.cpp\
        src/lib/spatiogram.cpp\
        src/lib/spatiogram_tracker.cpp\
        src/lib/spatial_pf_tracker.cpp\
        src/lib/qt_opencv.cpp

HEADERS  += includes/mainwindow.h\
        src/lib/mcv_tracker.hpp\
        src/lib/meanShift_tracker.hpp\
        src/lib/spatiogram.hpp\
        src/lib/spatiogram_tracker.hpp\
        src/lib/spatial_pf_tracker.hpp\
        src/lib/qt_opencv.hpp
INCLUDEPATH += includes \
            src/lib
FORMS    += ui/mainwindow.ui
RESOURCES += resources/list.qrc

android{
ANDROID_EXTRA_LIBS = ../Android/OpenCV-3.0.0-android-sdk/sdk/native/libs/armeabi-v7a/libnative_camera_r4.2.0.so \
                     ../Android/OpenCV-3.0.0-android-sdk/sdk/native/libs/armeabi-v7a/libopencv_info.so \
                     ../Android/OpenCV-3.0.0-android-sdk/sdk/native/libs/armeabi-v7a/libopencv_java.so \

A_OPENCV = /home/juanma/Documents/SRC/Android/OpenCV-3.0.0-android-sdk/sdk/native
LIBS += -L$$A_OPENCV/libs/armeabi-v7a/
LIBS+=-lopencv_highgui \
    -lopencv_video \
    -lopencv_androidcamera \
    -lopencv_imgproc \
    -lopencv_core \
    -lm

INCLUDEPATH += $$A_OPENCV/jni/include/opencv
INCLUDEPATH += $$A_OPENCV/jni/include/opencv2
INCLUDEPATH += $$A_OPENCV/jni/include

LIBS+= -L$$PWD/../Android/OpenCV-3.0.0-android-sdk/sdk/native/3rdparty/libs/armeabi-v7a/ \
        -lIlmImf -llibjasper -llibjpeg -llibtiff -llibwebp -llibpng
INCLUDEPATH += $$PWD/../Android/OpenCV-3.0.0-android-sdk/sdk/native/3rdparty/libs/armeabi-v7a
}

unix:!android{
INCLUDEPATH += /usr/local/include/opencv/ \
            /usr/local/include/opencv2/
LIBS+=-L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_objdetect \
    -lgomp \
    -lopencv_features2d \
    -lopencv_flann \
    -lopencv_calib3d \
    -lopencv_shape \
    -lopencv_tracking \
    -lopencv_video \
    -lm
    OBJECTS_DIR += objects
}

