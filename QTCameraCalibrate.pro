QT       += core gui
#QT       += network
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += link_pkgconfig

CONFIG += c++11

SOURCES += \
    onvifcontrol.cpp \
    main.cpp \
    mainwindow.cpp \
    camera.cpp \
    cameralistmodel.cpp \
    mainsettings.cpp \
    dialogcoordedit.cpp \
    videowidget.cpp \
    cameramath.cpp

HEADERS += \
    onvifcontrol.h \
    mainwindow.h \
    camera.h \
    cameralistmodel.h \
    mainsettings.h \
    dialogcoordedit.h \
    videowidget.h \
    cameramath.h

FORMS += \
    mainwindow.ui \
    dialogcoordedit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += \
    include/libonvif/ \
    include/libonvif/gsoap \
    include/libonvif/generated \
    libonvif \
    /usr/include/openssl \
LIBS += -L/usr/local/lib
LIBS += \
    -lonvifcommon \
    -lonvifdevice \
    -lonvifmedia \
    -lonvifptz \
    -lonvifdiscovery

RESOURCES += \
    calibrator_images.qrc
