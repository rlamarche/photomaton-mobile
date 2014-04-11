/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef GPHOTOOPENCAMERACOMMAND_H
#define GPHOTOOPENCAMERACOMMAND_H

#include "gphoto/abstractgphotocommand.h"

class GPhotoOpenCameraCommand : public AbstractGPhotoCommand
{
    Q_OBJECT
public:
    explicit GPhotoOpenCameraCommand(QString model, QString port, QObject *parent = 0);
    void execute(GPhotoCameraController* controller);

private:
    QString model;
    QString port;

signals:
    void cameraOpened();
public slots:

};

#endif // GPHOTOOPENCAMERACOMMAND_H
