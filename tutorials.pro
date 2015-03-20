#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T15:02:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = tutorials
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/AbstractSprite.cpp \
    src/AnimatedSprite.cpp \
    src/Background.cpp \
    src/BmpFont.cpp \
    src/Button.cpp \
    src/Cursor.cpp \
    src/Functions.cpp \
    src/Game.cpp \
    src/ImageInstruments.cpp \
    src/LineText.cpp \
    src/SdlApplication.cpp \
    src/SpriteManager.cpp \
    src/StaticSprite.cpp \
    gsrc/FifteenGame.cpp \
    src/TextMessage.cpp \
    gsrc/Game15.cpp \
    gsrc/GameState.cpp \
    gsrc/Numbers.cpp

LIBS += -L/usr/lib -lSDL2 -lSDL2_image
INCLUDEPATH = usr/include

HEADERS += \
    include/AbstractGame.h \
    include/AbstractSprite.h \
    include/AnimatedSprite.h \
    include/Background.h \
    include/BmpFont.h \
    include/Button.h \
    include/Constants.h \
    include/Cursor.h \
    include/Functions.h \
    include/Game.h \
    include/ImageInstruments.h \
    include/LineText.h \
    include/SdlApplication.h \
    include/SpriteManager.h \
    include/StaticSprite.h \
    gsrc/FifteenGame.h \
    include/TextMessage.h \
    gsrc/FConstants.h \
    gsrc/Game15.h \
    gsrc/GameState.h \
    gsrc/Numbers.h
