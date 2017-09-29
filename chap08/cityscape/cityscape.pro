greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE      = app
HEADERS       = annotation.h \
                cityblock.h \
                cityscape.h \
                cityview.h
SOURCES       = annotation.cpp \
                cityblock.cpp \
                cityscape.cpp \
                cityview.cpp \
                main.cpp
