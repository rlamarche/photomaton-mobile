/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QtQml/QQmlApplicationEngine>
#include <QStandardItemModel>
#include <QTimer>

#include "graphicsview.h"
#include "graphicsscene.h"
#include "gphoto/gphotocameracontroller.h"


class Application : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStandardItemModel* cameraListModel READ cameraListModel NOTIFY cameraListModelChanged)
public:
    explicit Application(QObject *parent = 0);
    QStandardItemModel* cameraListModel();
protected:
    GPhotoCameraController cameraController;
    QTimer liveviewTimer;
private:
    QStandardItemModel m_cameraListModel;

signals:
    void cameraListModelChanged(QStandardItemModel* cameraListModel);
    void applicationError(QString error);
    void previewReady(const QImage image);
public slots:
    void camerasDetected(QList<GPhotoCameraHandle> detectedCameras);
    void cameraSelected(int index);
    void cameraOpened();
    void handlePreview(const QImage image);
    void capturePreview();
    void autodetect();
};

#endif // APPLICATION_H
