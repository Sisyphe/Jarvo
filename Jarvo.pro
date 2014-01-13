TEMPLATE = app
CONFIG += console debug
CONFIG -= app_bundle
CONFIG -= qt

DEPENDPATH += ./inc ./src

OBJECTS_DIR = ./tmp

DESTDIR = ./bin

INCLUDEPATH += ./inc ../Graf/inc ../Graf/src /usr/include/espeak

LIBS += -L ../Graf/lib -lGraflib -lportaudio -lespeak

QMAKE_CXXFLAGS += -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable

SOURCES +=  src/main.cpp \
            src/thing.cpp \
            src/jarvo.cpp \
            src/nodecontent.cpp \
            src/relationcontent.cpp \
            src/parser.cpp \
            src/dictionnary.cpp \
            src/sentence.cpp \
            src/link.cpp \
            src/findthing.cpp \
            src/linkgraph.cpp \
            src/mouth.cpp \
            src/findpath.cpp \
            src/brain.cpp \
            src/findlink.cpp \
            src/openlink.cpp \
            src/handler.cpp \
            src/openfileaction.cpp \
            src/openfolderaction.cpp \
            src/commandlink.cpp \
            src/wordgroup.cpp \
            src/word.cpp \
            src/wordgrouplist.cpp \
            src/dictionaryparser.cpp \
            src/findqualifiers.cpp \

HEADERS +=  inc/thing.h \
            inc/node.h \
            inc/jarvo.h \
            inc/nodecontent.h \
            inc/relationcontent.h \
            inc/parser.h \
            inc/dictionnary.h \
            inc/word.h \
            inc/sentence.h \
            inc/link.h \
            inc/findthing.h \
            inc/linkgraph.h \
            inc/mouth.h \
            inc/findpath.h \
            inc/brain.h \
            inc/findlink.h \
            inc/openlink.h \
            inc/handler.h \
            inc/openfileaction.h \
            inc/openfolderaction.h \
            inc/commandlink.h \
            inc/saylink.h \
            inc/openprogramaction.h \
            inc/wordgroup.h \
            inc/wordgrouplist.h \
            inc/dictionaryparser.h \
            inc/findqualifiers.h \
