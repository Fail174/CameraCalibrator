QT       += core gui
QT       += network
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    source/cencode.c \
    source/onvif.c \
    source/sha1.c \
    main.cpp \
    mainwindow.cpp \
    camera.cpp \
    cameralistmodel.cpp \
    mainsettings.cpp \
    dialogcoordedit.cpp \
    videowidget.cpp \
    cameramath.cpp

HEADERS += \
    source/cencode.h \
    source/onvif.h \
    source/sha1.h \
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

# Linux with static libxml2, i.e. Ubuntu
# install libxml2 and libxml2-devel with apt
#unix {
#    message("build linux static libxml2")
#    INCLUDEPATH += ../libonvif


    #INCLUDEPATH += /usr/lib/x86_64-linux-gnu
    #DEPENDPATH += /usr/lib/x86_64-linux-gnu

    #unix:!macx: LIBS += -L/usr/lib/x86_64-linux-gnu/ -lxml2

#    INCLUDEPATH += /usr/include/libxml2
    #DEPENDPATH += /usr/include/libxml2

    #unix:!macx: PRE_TARGETDEPS += /usr/lib/x86_64-linux-gnu/libxml2.a
#}

# Linux with static libxml2, i.e. Ubuntu
# install libxml2 and libxml2-devel with apt
unix {
    message("build linux shared libxml2")
    unix:!macx: LIBS += -L/usr/lib64/ -lxml2

    INCLUDEPATH += ../source
    INCLUDEPATH += /usr/include/libxml2
    INCLUDEPATH += /usr/lib64
    DEPENDPATH += /usr/lib64
}

unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib64/ -lxml2

INCLUDEPATH += $$PWD/../../../../../usr/lib64
DEPENDPATH += $$PWD/../../../../../usr/lib64

RESOURCES += \
    calibrator_images.qrc
