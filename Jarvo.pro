TEMPLATE = app
CONFIG += console debug
CONFIG -= app_bundle
CONFIG -= qt

DEPENDPATH += ./inc ./src

OBJECTS_DIR = ./tmp

DESTDIR = ./bin

INCLUDEPATH += ./inc ../Graf/inc ../Graf/src /usr/include/espeak

LIBS += -L ../Graf/lib -lGraf -lportaudio -lespeak

SOURCES += src/main.cpp \
           src/thing.cpp \
           src/entity.cpp \
           src/jarvo.cpp \
           src/nodecontent.cpp \
           src/property.cpp \
           src/relationcontent.cpp \
           src/parser.cpp \
    src/dictionnary.cpp \
    src/sentence.cpp \
    src/link.cpp \
    src/findthing.cpp \
    src/linkgraph.cpp \
    src/mouth.cpp \
    src/findconnection.cpp

HEADERS += inc/thing.h \
           inc/node.h \
           inc/entity.h \
           inc/jarvo.h \
           inc/nodecontent.h \
           inc/property.h \
           inc/relationcontent.h \
           inc/parser.h \
    inc/dictionnary.h \
    inc/word.h \
    inc/sentence.h \
    inc/link.h \
    inc/findthing.h \
    inc/linkgraph.h \
    inc/mouth.h \
    inc/findconnection.h
