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
