#ifndef GPHOTOCAMERAHANDLE_H
#define GPHOTOCAMERAHANDLE_H

//#include <QObject>
#include <QString>

#include <gphoto2/gphoto2-camera.h>

class GPhotoCameraHandle// : public QObject
{
  //  Q_OBJECT
public:
    GPhotoCameraHandle(int cameraNumber = -1, QString model = QString(), QString port = QString(), Camera* camera = 0, GPPort* gpport = 0, CameraWidget* window = 0);
//private:
    int cameraNumber;
    QString model;
    QString port;
    Camera *camera;
    GPPort *gpport;
    CameraWidget *window;
//signals:

//public slots:

};

#endif // GPHOTOCAMERAHANDLE_H
