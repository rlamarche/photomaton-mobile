#ifndef GPHOTOCOMMANDTHREAD_H
#define GPHOTOCOMMANDTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QQueue>

#include "gphoto/abstractgphotocommand.h"

class GPhotoCameraController;

class GPhotoCommandThread : public QThread
{
    Q_OBJECT
public:
    explicit GPhotoCommandThread(GPhotoCameraController *controller);

    void enqueue(AbstractGPhotoCommand* command);
    void stop(void);
protected:
    void run();
private:
    QMutex mutex;
    QWaitCondition condition;
    QQueue<AbstractGPhotoCommand*> commandQueue;
    bool abort;

    GPhotoCameraController* m_controller;
signals:

public slots:

};

#endif // GPHOTOCOMMANDTHREAD_H
