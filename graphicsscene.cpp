#include "graphicsscene.h"


#include <QFrame>



GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    //addWidget(&cameraSelectorWidget);
    //connect(this, SIGNAL(sceneRectChanged(QRectF)), &cameraSelectorWidget, SLOT(sceneRectChanged(QRectF)));
}
