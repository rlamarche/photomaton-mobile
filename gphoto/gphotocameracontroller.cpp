#include "gphotocameracontroller.h"

#include "gphoto/commands/gphotolistcamerascommand.h"

#include <iostream>

GPhotoCameraController::GPhotoCameraController(QObject *parent) :
    QObject(parent)
{
    // Create the GPhoto context
    context = gp_context_new();

    commandThread.start();

    // Detect cameras
    detectCameras();
}

GPhotoCameraController::~GPhotoCameraController()
{
    commandThread.stop();

    gp_context_unref(context);
}

void GPhotoCameraController::executeCommand(AbstractGPhotoCommand* command)
{
    command->setGPContext(context);
    commandThread.enqueue(command);
}

void GPhotoCameraController::detectCameras() {
    GPhotoListCamerasCommand* listCommand = new GPhotoListCamerasCommand();

    connect(listCommand, SIGNAL(camerasDetected(QList<GPhotoCameraHandle>*)), this, SLOT(camerasDetected(QList<GPhotoCameraHandle>*)));

    executeCommand(listCommand);
}

void GPhotoCameraController::camerasDetected(QList<GPhotoCameraHandle>* detectedCameras) {
    std::cout << "Detected " << detectedCameras->length() << " cameras.\n";

    for (int i = 0; i < detectedCameras->length(); i++) {
        std::cout << detectedCameras->at(i).model.toStdString() << "\n";
    }

    std::cout.flush();
}
