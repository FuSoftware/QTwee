TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    data/story.cpp \
    data/htmlfile.cpp \
    data/passage.cpp \
    data/format.cpp \
    controllers/tweeparser.cpp \
    tests.cpp \
    utils.cpp \
    html/htmlnode.cpp \
    controllers/storybuilder.cpp

HEADERS += \
    data/story.h \
    data/htmlfile.h \
    data/passage.h \
    data/format.h \
    controllers/tweeparser.h \
    tests.h \
    utils.h \
    html/htmlnode.h \
    controllers/storybuilder.h
