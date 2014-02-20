TEMPLATE = app
CONFIG += console opengl
CONFIG -= qt

LIBS += -L/usr/lib/i386-linux-gnu \
    -lglut

SOURCES += tulipa.cpp \
    brazo_superior.cpp \
    brazo_inferior.cpp \
    lampara.cpp \
    file_ply_stl.cpp \
    og3d.cpp \
    main.cpp


HEADERS += \
    tulipa.h \
    brazo_superior.h \
    brazo_inferior.h \
    lampara.h \
    vertex.h \
    file_ply_stl.h \
    og3d.h

