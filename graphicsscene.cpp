/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "graphicsscene.h"


#include <QFrame>



GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    //addWidget(&cameraSelectorWidget);
    //connect(this, SIGNAL(sceneRectChanged(QRectF)), &cameraSelectorWidget, SLOT(sceneRectChanged(QRectF)));
}
