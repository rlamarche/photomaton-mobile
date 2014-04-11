#include "gphotolistcamerascommand.h"

#include "gphoto/gphotocameracontroller.h"

GPhotoListCamerasCommand::GPhotoListCamerasCommand(QObject *parent) :
    AbstractGPhotoCommand(parent)
{
}

void GPhotoListCamerasCommand::execute(GPhotoCameraController* controller)
{
    QList<GPhotoCameraHandle> detectedCameras = controller->internalDetectCameras();

 //   emit camerasDetected(detectedCameras);
}
