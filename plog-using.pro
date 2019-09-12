TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        loggerencryptkey.cpp \
        main.cpp

INCLUDEPATH += /home/ainr/Garage/ext_libraries/plog/include

HEADERS += \
    logencrypt.h \
    loggerencryptkey.h

