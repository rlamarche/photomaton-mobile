/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef LIVEVIEW_H
#define LIVEVIEW_H

#include <QQuickPaintedItem>
#include <QImage>

class Liveview : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit Liveview(QQuickItem *parent = 0);

    void paint(QPainter *painter);
private:
    QImage image;
signals:

public slots:
    void updateImage(const QImage image);
};

#endif // LIVEVIEW_H
