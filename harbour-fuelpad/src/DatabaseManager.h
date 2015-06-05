#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include"sqlquerymodel.h"

#include<QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

// ---------------------------------------------------------------------------
// DatabaseManager
// ---------------------------------------------------------------------------
class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    DatabaseManager(QObject *parent = 0);
    ~DatabaseManager();

public:
    Q_INVOKABLE void open();
    Q_INVOKABLE void close();

    QSqlError lastError();

private:
    bool openfuelpaddb();

private: QSqlDatabase fuelpaddb;

};

#endif // DATABASEMANAGER_H
