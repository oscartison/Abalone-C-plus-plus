include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier \

SOURCES += main.cpp \
    testboard.cpp \
    testgame.cpp

HEADERS += \
    catch.hpp
