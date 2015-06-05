/*
 * Fuelpad, Sailfish application to track expenses and fuel usage for vehicles
 *
 * Copyright (C) 2015 Chris Walker
 *
 * This file is part of Fuelpad.
 *
 * Fuelpad is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Fuelpad is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details. You should have received a copy of the GNU
 * General Public License along with Fuelpad. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Chris Walker
 */

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>

#include <sailfishapp.h>
#include "DatabaseManager.h"
#include "sqlquerymodel.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->rootContext()->setContextProperty("APP_VERSION", APP_VERSION);

    // qDebug() << "App Version is : " << APP_VERSION;

    DatabaseManager* fuelpaddb = new DatabaseManager();
    fuelpaddb->open();

    view->rootContext()->setContextProperty("fuelpaddb", fuelpaddb);

    view->setSource(SailfishApp::pathTo("qml/harbour-fuelpad.qml"));

    view->show();

    return app->exec();
}
