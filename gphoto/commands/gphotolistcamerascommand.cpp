/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

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
