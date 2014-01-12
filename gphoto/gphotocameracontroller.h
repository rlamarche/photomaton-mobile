#ifndef GPHOTOCAMERACONTROLLER_H
#define GPHOTOCAMERACONTROLLER_H

#include <QObject>

#include <gphoto2/gphoto2-camera.h>
#include <gphoto2/gphoto2-context.h>
#include <gphoto2/gphoto2-port-info-list.h>

#include "gphoto/gphotocamerahandle.h"
#include "gphoto/gphotocommandthread.h"
#include "gphoto/abstractgphotocommand.h"

class GPhotoCameraController : public QObject
{
    Q_OBJECT
public:
    explicit GPhotoCameraController(QObject *parent = 0);
    ~GPhotoCameraController();

    void executeCommand(AbstractGPhotoCommand* command);

protected:
    void detectCameras(void);
private:
    GPContext* context;
    GPhotoCameraHandle cameraHandle;
    GPhotoCommandThread commandThread;
signals:

public slots:
    void camerasDetected(QList<GPhotoCameraHandle>* detectedCameras);
};

#endif // GPHOTOCAMERACONTROLLER_H
