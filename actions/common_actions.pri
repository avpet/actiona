include(../common.pri)

TEMPLATE = lib
CONFIG += plugin dll

INCLUDEPATH += ../../tools \
	../../actiontools
DESTDIR = ../../actions

LIBS += -L../.. \
	-ltools \
	-lactiontools

UI_DIR = generated
MOC_DIR = generated
RCC_DIR = generated
OBJECTS_DIR = generated