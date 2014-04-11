#include "gphotoopencameracommand.h"

#include "gphoto/gphotocameracontroller.h"

GPhotoOpenCameraCommand::GPhotoOpenCameraCommand(QString model, QString port, QObject *parent) :
    AbstractGPhotoCommand(parent),
    model(model),
    port(port)
{
}

void GPhotoOpenCameraCommand::execute(GPhotoCameraController *controller) {
    controller->internalOpenCamera(model, port);

    emit cameraOpened();
}
