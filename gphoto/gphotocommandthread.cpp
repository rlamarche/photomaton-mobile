#include "gphotocommandthread.h"

GPhotoCommandThread::GPhotoCommandThread(QObject *parent) :
    QThread(parent)
{
    abort = false;
}

void GPhotoCommandThread::enqueue(AbstractGPhotoCommand* command) {
    commandQueue.append(command);
    condition.wakeOne();
}

void GPhotoCommandThread::stop() {
    mutex.lock();
    abort = true;
    condition.wakeOne();
    mutex.unlock();

    wait();
}


void GPhotoCommandThread::run()
{
    forever {
       // bool liveview = false;
        if (abort) {
            return;
        }
        AbstractGPhotoCommand *command;
        bool empty;


        mutex.lock();
        if (!commandQueue.isEmpty()) {
            empty = false;
            command = commandQueue.dequeue();
        } else {
            empty = true;
        }
        mutex.unlock();

        /*
        if (command.cameraNumber > -1) {
            PMCamera* camera = cameras->at(command.cameraNumber);
            if (camera->liveviewThread && camera->liveviewThread->isRunning() && command.type != START_LIVEVIEW && command.type != STOP_LIVEVIEW) {
                liveview = true;
                camera->liveviewThread->stopNow();
            }
        }*/

        if (!empty)
        {
            // TODO send gp context & widget
            command->execute();
            delete command;
        }
/*
        if (command.cameraNumber > -1) {
            PMCamera* camera = cameras->at(command.cameraNumber);
            if (liveview) {
                camera->liveviewThread->restart();
            }

        }*/

        mutex.lock();
        if (commandQueue.isEmpty()) {
            condition.wait(&mutex);
        }
        mutex.unlock();
    }
}
