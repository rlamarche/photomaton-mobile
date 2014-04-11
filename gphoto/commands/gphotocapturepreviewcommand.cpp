#include "gphotocapturepreviewcommand.h"

#include "gphoto/gphotocameracontroller.h"

GPhotoCapturePreviewCommand::GPhotoCapturePreviewCommand(QObject *parent) :
    AbstractGPhotoCommand(parent)
{
}


void GPhotoCapturePreviewCommand::execute(GPhotoCameraController *controller) {
    controller->internalCapturePreview();
}
