include(../common_actions.pri)
include(actions/actions.pri)
include(code/code.pri)
TARGET = ActionPackData
QT += script network sql
equals(QT_MAJOR_VERSION, 5) {
QT += widgets
OTHER_FILES += data.json
}
HEADERS += actionpackdata.h
win32:LIBS += -ladvapi32 \
	-lshell32

win32:INCLUDEPATH += $${BOOST_INCLUDE}

TRANSLATIONS = ../../locale/actionpackdata_fr_FR.ts \
                ../../locale/actionpackdata_de_DE.ts

RESOURCES += \
    actionpackdata.qrc

unix {
        locales.path = $${PREFIX}/share/actiona/locale
        locales.files = ../../locale/actionpackdata_fr_FR.qm \
                        ../../locale/actionpackdata_de_DE.qm
	locales.CONFIG = no_check_exist

	INSTALLS += locales
}
