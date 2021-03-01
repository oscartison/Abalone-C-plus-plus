TEMPLATE = app
CONFIG += console c++17
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
