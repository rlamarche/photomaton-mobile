/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef GPHOTOCAPTUREPREVIEWCOMMAND_H
#define GPHOTOCAPTUREPREVIEWCOMMAND_H

#include "gphoto/abstractgphotocommand.h"

class GPhotoCapturePreviewCommand : public AbstractGPhotoCommand
{
    Q_OBJECT
public:
    explicit GPhotoCapturePreviewCommand(QObject *parent = 0);
    void execute(GPhotoCameraController* controller);
signals:

public slots:

};

#endif // GPHOTOCAPTUREPREVIEWCOMMAND_H
