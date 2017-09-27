QT += core
QT -= gui

CONFIG += c++11

TARGET = LcJsonDemo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


win32{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = LcJsonDemo
        } else {
            target_path = build_/debug
            TARGET  = LcJsonDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}
unix{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = LcJsonDemo
        } else {
            target_path = build_/debug
            TARGET  = LcJsonDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}

DEPENDPATH += Bin

HEADERS +=\
    cJson.h

SOURCES +=\
     main.cpp   \
     cJson.c
