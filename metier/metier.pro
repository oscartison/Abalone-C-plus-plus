TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    board.h \
    game.h \
    marble.h \
    observable.h \
    observer.h \
    player.h \
    position.h
