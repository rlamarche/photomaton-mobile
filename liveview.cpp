/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "liveview.h"

#include <QPainter>

Liveview::Liveview(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
}

void Liveview::paint(QPainter *painter) {
    painter->drawImage(0, 0, image);
}

void Liveview::updateImage(const QImage image) {
    this->image = image;
    update();
}
