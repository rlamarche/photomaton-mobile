#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include "widgets/cameraselectorwidget.h"

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = 0);
protected:
    CameraSelectorWidget cameraSelectorWidget;

signals:

public slots:

};

#endif // GRAPHICSSCENE_H
