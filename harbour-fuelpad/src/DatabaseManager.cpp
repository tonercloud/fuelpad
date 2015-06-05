#include "DatabaseManager.h"

#include <QStringList>
#include <QDir>
#include <QVariant>
#include <QBuffer>
#include <QFile>
#include <QDesktopServices>
#include <QDebug>

// ---------------------------------------------------------------------------
// DatabaseManager
// ---------------------------------------------------------------------------
DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
}

DatabaseManager::~DatabaseManager()
{
    close();
}

void DatabaseManager::open()
{
    openfuelpaddb();
}

void DatabaseManager::close()
{
    if (fuelpaddb.isOpen())
        fuelpaddb.close();
}

bool DatabaseManager::openfuelpaddb()
{
    // Find SQLite Driver
    fuelpaddb = QSqlDatabase::addDatabase("QSQLITE");

    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/fuelpad.db";

    QDir dir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    if (!dir.exists()) {
        dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    }
    fuelpaddb.setDatabaseName(path);

    return fuelpaddb.open();
}

QSqlError DatabaseManager::lastError()
{
    return DatabaseManager::lastError();
}
