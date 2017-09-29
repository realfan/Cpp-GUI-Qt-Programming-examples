greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += designer
TEMPLATE      = lib
CONFIG       +=  plugin release
HEADERS       = ../iconeditor/iconeditor.h \
                iconeditorplugin.h
SOURCES       = ../iconeditor/iconeditor.cpp \
                iconeditorplugin.cpp
RESOURCES     = iconeditorplugin.qrc
DESTDIR       = $$[QT_INSTALL_PLUGINS]/designer
