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
