QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += $$PWD/lib/libglad.a
INCLUDEPATH += $$PWD/include

SOURCES += \
    GLWidget.cpp \
    RenderBase.cpp \
    RenderManager.cpp \
    Simple/rectangle.cpp \
    loadShader.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GLWidget.h \
    RenderBase.h \
    RenderManager.h \
    Simple/rectangle.h \
    global_func.h \
    loadShader.h \
    mainwindow.h

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
