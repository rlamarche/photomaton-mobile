/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef ABSTRACTGPHOTOCOMMAND_H
#define ABSTRACTGPHOTOCOMMAND_H

#include <QObject>

#include <gphoto2/gphoto2-camera.h>

#include "gphoto/gphotocamerahandle.h"

class GPhotoCameraController;

class AbstractGPhotoCommand : public QObject
{
    Q_OBJECT
public:
    explicit AbstractGPhotoCommand(QObject *parent = 0);

    virtual void execute(GPhotoCameraController* controller) = 0;

signals:

public slots:

};

#endif // ABSTRACTGPHOTOCOMMAND_H
