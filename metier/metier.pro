include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib


HEADERS += \
    board.h \
    game.h \
    marble.h \
    observable.h \
    observer.h \
    player.h \
    position.h

SOURCES += \
    board.cpp \
    game.cpp \
    marble.cpp \
    player.cpp \
    position.cpp
