/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

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
