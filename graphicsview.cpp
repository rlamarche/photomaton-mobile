#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    setWindowTitle(tr("Photomaton mobile"));
    //setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //setRenderHints(QPainter::SmoothPixmapTransform);
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
       if (scene())
           scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
       QGraphicsView::resizeEvent(event);
}
