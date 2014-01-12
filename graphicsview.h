#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

signals:

public slots:

};

#endif // GRAPHICSVIEW_H
