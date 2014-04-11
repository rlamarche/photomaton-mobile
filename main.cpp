/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QtQml>

#include "qtquick2applicationviewer.h"
#include "liveview.h"

#include "application.h"
#include "gphoto2/gphoto2-port-log.h"

#ifdef __GNUC__
#define __unused__ __attribute__((unused))
#else
#define __unused__
#endif


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    Application application;

    qmlRegisterType<QStandardItemModel>("com.mycompany.qmlcomponents", 1, 0, "QStandardItemModel");
    qmlRegisterType<Liveview>("org.rlamarche", 1, 0, "Liveview");

    viewer.rootContext()->setContextProperty("application", &application);
    viewer.setMainQmlFile(QStringLiteral("qml/photomaton-mobile/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
