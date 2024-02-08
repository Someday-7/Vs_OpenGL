QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += $$PWD/lib/libglad.a
INCLUDEPATH += $$PWD/include

SOURCES += \
    Camera.cpp \
    GLWidget.cpp \
    MyShader.cpp \
    RenderBase.cpp \
    RenderManager.cpp \
    Simple/cameraSys.cpp \
    Simple/rectangle.cpp \
    main.cpp \
    mainwindow.cpp \
    stbimage_loader.cpp

HEADERS += \
    Camera.h \
    GLWidget.h \
    MyShader.h \
    RenderBase.h \
    RenderManager.h \
    Simple/cameraSys.h \
    Simple/rectangle.h \
    mainwindow.h \
    stbimage_loader.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    glsl/dog.jpg \
    glsl/fragment.glsl \
    glsl/laugh.jpg \
    glsl/vertex.glsl \
    glsl/wood.jpg
