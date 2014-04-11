/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "gphotocapturepreviewcommand.h"

#include "gphoto/gphotocameracontroller.h"

GPhotoCapturePreviewCommand::GPhotoCapturePreviewCommand(QObject *parent) :
    AbstractGPhotoCommand(parent)
{
}


void GPhotoCapturePreviewCommand::execute(GPhotoCameraController *controller) {
    controller->internalCapturePreview();
}
