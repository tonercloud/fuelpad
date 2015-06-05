# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-fuelpad

CONFIG += sailfishapp

DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QT += sql

RESOURCES += resources.qrc

HEADERS += src/sqlquerymodel.h \
    src/DatabaseManager.h

SOURCES += src/harbour-fuelpad.cpp \
    src/sqlquerymodel.cpp \
    src/DatabaseManager.cpp

OTHER_FILES += qml/harbour-fuelpad.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FuelpadPage.qml \
    qml/pages/AboutDialog.qml \
    qml/pages/CarRecordsPage.qml \
    qml/pages/ManageDrivers.qml \
    rpm/harbour-fuelpad.changes.in \
    rpm/harbour-fuelpad.spec \
    rpm/harbour-fuelpad.yaml \
    translations/*.ts \
    harbour-fuelpad.desktop

# to disable building translations every time, comment out the
# following CONFIG line
# CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
# TRANSLATIONS += translations/harbour-fuelpad-de.ts

