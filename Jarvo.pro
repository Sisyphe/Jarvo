TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEPENDPATH += ./inc ./src

OBJECTS_DIR = ./tmp

DESTDIR = ./bin

INCLUDEPATH += ./inc ../Graf/inc ../Graf/src

LIBS += -L ../Graf/lib -lGraf

SOURCES += src/main.cpp \
           src/thing.cpp \
           src/entity.cpp \
           src/jarvo.cpp \
           src/nodecontent.cpp \
           src/property.cpp \
           src/relationcontent.cpp \
           src/parser.cpp \
    src/dictionnary.cpp \
    src/word.cpp \
    src/adjective.cpp \
    src/noun.cpp

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
    inc/adjective.h \
    inc/noun.h
