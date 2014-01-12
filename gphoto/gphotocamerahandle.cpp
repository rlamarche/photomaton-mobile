#include "gphotocamerahandle.h"
/*
GPhotoCameraHandle::GPhotoCameraHandle(QObject *parent) :
    QObject(parent)
{
}
*/

GPhotoCameraHandle::GPhotoCameraHandle(int cameraNumber, QString model, QString port, Camera *camera, GPPort *gpport, CameraWidget *window) :
    cameraNumber(cameraNumber),
    model(model),
    port(port),
    camera(camera),
    gpport(gpport),
    window(window)
{

}
