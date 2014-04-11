#include "application.h"

#include <iostream>

Application::Application(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType< QList<GPhotoCameraHandle> >("QList<GPhotoCameraHandle>");


    QObject::connect(&cameraController, SIGNAL(camerasDetected(QList<GPhotoCameraHandle>)), this, SLOT(camerasDetected(QList<GPhotoCameraHandle>)));
    QObject::connect(&cameraController, SIGNAL(cameraOpened()), this, SLOT(cameraOpened()));
    QObject::connect(&cameraController, SIGNAL(previewReady(QImage)), this, SLOT(handlePreview(QImage)));

  //  liveviewTimer.setInterval(5000);

//    QObject::connect(&liveviewTimer, SIGNAL(timeout()), this, SLOT(capturePreview()));
}

QStandardItemModel* Application::cameraListModel()
{
    return &m_cameraListModel;
}

void Application::camerasDetected(QList<GPhotoCameraHandle> detectedCameras) {
    m_cameraListModel.clear();

    m_cameraListModel.appendRow(new QStandardItem(QString(tr("Detected %1 cameras")).arg(detectedCameras.length())));

    for (QList<GPhotoCameraHandle>::iterator i = detectedCameras.begin(); i != detectedCameras.end(); i++) {
        QStandardItem* item = new QStandardItem(i->model());
        item->setData(QVariant(i->port()));

        m_cameraListModel.appendRow(item);
    }
}

void Application::cameraSelected(int index) {
    QStandardItem *selectedCamera = m_cameraListModel.item(index);

    std::cout << "Camera selected : " << m_cameraListModel.item(index)->text().toStdString() << "\n";
    std::cout.flush();

    cameraController.openCamera(selectedCamera->text(), selectedCamera->data().toString());
}

void Application::cameraOpened() {
    std::cout << "Camera opened\n";
    std::cout.flush();

        capturePreview();
    //liveviewTimer.start();
}

void Application::handlePreview(const QImage image) {
    emit previewReady(image);
}

void Application::capturePreview() {
    cameraController.capturePreview();
}

void Application::autodetect() {
    cameraController.detectCameras();
}
