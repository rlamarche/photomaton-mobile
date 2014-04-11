#ifndef GPHOTOCAMERACONTROLLER_H
#define GPHOTOCAMERACONTROLLER_H

#include <QObject>
#include <QPixmap>

#include <gphoto2/gphoto2-camera.h>
#include <gphoto2/gphoto2-context.h>
#include <gphoto2/gphoto2-port-info-list.h>

#include "gphoto/gphotocamerahandle.h"
#include "gphoto/gphotocommandthread.h"
#include "gphoto/abstractgphotocommand.h"

class GPhotoListCamerasCommand;
class GPhotoOpenCameraCommand;
class GPhotoCapturePreviewCommand;

class GPhotoCameraController : public QObject
{
    friend class GPhotoListCamerasCommand;
    friend class GPhotoOpenCameraCommand;
    friend class GPhotoCapturePreviewCommand;

    Q_OBJECT
public:
    explicit GPhotoCameraController(QObject *parent = 0);
    ~GPhotoCameraController();

    void executeCommand(AbstractGPhotoCommand* command);

    void detectCameras();
    void openCamera(QString model, QString port);
    void capturePreview();
protected:

    QList<GPhotoCameraHandle> internalDetectCameras();
    void internalOpenCamera(QString model, QString port);
    void internalCapturePreview();

    bool checkGPhotoSuccess(int ret);
private:
    GPhotoCameraHandle cameraHandle;
    GPhotoCommandThread commandThread;

    GPContext* gp_context;
    Camera* gp_camera;

    QPixmap* lockedPixmap;
    QPixmap* readyPixmap;

signals:
    void camerasDetected(QList<GPhotoCameraHandle> detectedCameras);
    void cameraOpened();
    void previewReady(const QImage image);
public slots:
    //void camerasDetected(QList<GPhotoCameraHandle>* detectedCameras);
};

#endif // GPHOTOCAMERACONTROLLER_H
