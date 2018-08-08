TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core

SOURCES += \
        main.cpp \
    data/story.cpp \
    data/passage.cpp \
    data/format.cpp \
    controllers/tweeparser.cpp \
    tests.cpp \
    html/htmlnode.cpp \
    controllers/storybuilder.cpp
    controllers/commandlineparser.cpp \
    controllers/projectscanner.cpp

HEADERS += \
    data/story.h \
    data/passage.h \
    data/format.h \
    controllers/tweeparser.h \
    tests.h \
    html/htmlnode.h \
    controllers/storybuilder.h
    controllers/commandlineparser.h \
    controllers/projectscanner.h
