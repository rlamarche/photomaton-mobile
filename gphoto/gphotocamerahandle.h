#ifndef GPHOTOCAMERAHANDLE_H
#define GPHOTOCAMERAHANDLE_H

//#include <QObject>
#include <QString>

#include <gphoto2/gphoto2-camera.h>

class GPhotoCameraHandle// : public QObject
{
  //  Q_OBJECT
public:
    GPhotoCameraHandle(QString model = QString(), QString port = QString());

    QString model();
    QString port();
private:
    QString m_model;
    QString m_port;
//signals:

//public slots:

};

#endif // GPHOTOCAMERAHANDLE_H
