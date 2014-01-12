#ifndef CAMERASELECTORWIDGET_H
#define CAMERASELECTORWIDGET_H

#include <QWidget>

class CameraSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraSelectorWidget(QWidget *parent = 0);

protected:
    void setSceneRect(const QRectF & rect);

signals:

public slots:
    void sceneRectChanged(const QRectF & rect);
};

#endif // CAMERASELECTORWIDGET_H
