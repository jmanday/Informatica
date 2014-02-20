HEADERS = \
  user_code.h \
    ../../../../user_code.h
  
SOURCES = \
 # user_code.cc \
  practica1.cc \
    ../../../../user_code.cpp

LIBS += -L/usr/lib/i386-linux-gnu \
    -lglut

CONFIG += console
QT += opengl

OTHER_FILES += \
    ../../../../beethoven.ply

