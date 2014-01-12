#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#include "graphicsview.h"
#include "graphicsscene.h"
#include "gphoto/gphotocameracontroller.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = 0);
    void show(void);

protected:
    GraphicsView graphicsView;
    GraphicsScene graphicsScene;
    GPhotoCameraController cameraController;

signals:

public slots:

};

#endif // APPLICATION_H
