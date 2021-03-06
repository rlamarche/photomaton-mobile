/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H


#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = 0);
protected:
    //CameraSelectorWidget cameraSelectorWidget;

signals:

public slots:

};

#endif // GRAPHICSSCENE_H
