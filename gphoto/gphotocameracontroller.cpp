/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "gphotocameracontroller.h"

#include "gphoto/commands/gphotolistcamerascommand.h"
#include "gphoto/commands/gphotoopencameracommand.h"
#include "gphoto/commands/gphotocapturepreviewcommand.h"

#include <iostream>
#include <gphoto2/gphoto2-camera.h>
#include <QFile>

GPhotoCameraController::GPhotoCameraController(QObject *parent) :
    QObject(parent),
    commandThread(this),
    gp_camera(0)
{
    // Create the GPhoto context
    gp_context = gp_context_new();

    // Start the command thread
    commandThread.start();
}

GPhotoCameraController::~GPhotoCameraController()
{
    // Stop the command thread
    commandThread.stop();

    // Unref the context
    gp_context_unref(gp_context);
}

void GPhotoCameraController::executeCommand(AbstractGPhotoCommand* command)
{
    commandThread.enqueue(command);
}

void GPhotoCameraController::detectCameras() {
    GPhotoListCamerasCommand* listCommand = new GPhotoListCamerasCommand();
    executeCommand(listCommand);
}

void GPhotoCameraController::openCamera(QString model, QString port) {
    GPhotoOpenCameraCommand* openCommand = new GPhotoOpenCameraCommand(model, port);
    executeCommand(openCommand);
}

void GPhotoCameraController::capturePreview() {
    GPhotoCapturePreviewCommand* captureCommand = new GPhotoCapturePreviewCommand();
    executeCommand(captureCommand);
}

QList<GPhotoCameraHandle> GPhotoCameraController::internalDetectCameras() {
    int count;
    CameraList *list;
    const char *name = NULL, *value = NULL;
    QList<GPhotoCameraHandle> detectedCameras;

    gp_list_new (&list);
    count = gp_camera_autodetect(list, gp_context);

    for (int i = 0; i < count; i ++) {
        gp_list_get_name  (list, i, &name);
        gp_list_get_value (list, i, &value);

        detectedCameras.append(GPhotoCameraHandle(QString(name), QString(value)));
    }

    gp_list_free(list);

    emit camerasDetected(detectedCameras);
    return detectedCameras;

}

bool GPhotoCameraController::checkGPhotoSuccess(int ret) {
    if (ret != GP_OK) {
        // TODO emit application error
        return false;
    }

    return true;
}

void GPhotoCameraController::internalOpenCamera(QString model, QString port) {
    int ret;
    // the port handle
    int p;

    // model index
    int gp_modelIndex;
    GPPortInfoList *gp_port_info_list;
    GPPortInfo gp_port_info;
    CameraAbilitiesList *gp_camera_abilities_list;
    CameraAbilities gp_camera_abilities;

    CameraEventType gp_evttype;
    void *gp_evtdata;

    // If a camera is already opened, close it
    if (gp_camera) {
        // TODO put it in a closeCamera fuction
        gp_camera_exit(gp_camera, gp_context);
    }

    // Create a camera object
    ret = gp_camera_new(&gp_camera);
    if (!checkGPhotoSuccess(ret)) {
        return;
    }

    // Lookup camera model
    gp_abilities_list_new    (&gp_camera_abilities_list);
    gp_abilities_list_load(gp_camera_abilities_list, gp_context);

    gp_modelIndex = gp_abilities_list_lookup_model (gp_camera_abilities_list, model.toStdString().c_str());
    if (gp_modelIndex < 0) {
        gp_abilities_list_free(gp_camera_abilities_list);

        checkGPhotoSuccess(gp_modelIndex);
        return;
    }

    ret = gp_abilities_list_get_abilities (gp_camera_abilities_list, gp_modelIndex, &gp_camera_abilities);
    if (!checkGPhotoSuccess(ret)) {
        gp_abilities_list_free(gp_camera_abilities_list);

        return;
    }

    ret = gp_camera_set_abilities (gp_camera, gp_camera_abilities);
    if (!checkGPhotoSuccess(ret)) {
        gp_abilities_list_free(gp_camera_abilities_list);

        return;
    }

    // Get usb port
    ret = gp_port_info_list_new(&gp_port_info_list);
    if (!checkGPhotoSuccess(ret)) {
        return;
    }

    ret = gp_port_info_list_load(gp_port_info_list);
    if (!checkGPhotoSuccess(ret)) {
        gp_abilities_list_free(gp_camera_abilities_list);
        gp_port_info_list_free(gp_port_info_list);

        return;
    }

    p = gp_port_info_list_lookup_path (gp_port_info_list, port.toStdString().c_str());
    if (p < 0) {
        gp_abilities_list_free(gp_camera_abilities_list);
        gp_port_info_list_free(gp_port_info_list);

        return; // TODO throw error
    }

    ret = gp_port_info_list_get_info (gp_port_info_list, p, &gp_port_info);

    ret = gp_camera_set_port_info (gp_camera, gp_port_info);
    if (!checkGPhotoSuccess(ret)) {
        gp_abilities_list_free(gp_camera_abilities_list);
        gp_port_info_list_free(gp_port_info_list);

        return;
    }

    gp_camera_init(gp_camera, gp_context);

    gp_abilities_list_free(gp_camera_abilities_list);
    gp_port_info_list_free(gp_port_info_list);

    do {
        ret = gp_camera_wait_for_event (gp_camera, 10, &gp_evttype, &gp_evtdata, gp_context);
    } while ((ret == GP_OK) && (gp_evttype != GP_EVENT_TIMEOUT));

    emit cameraOpened();
}

void GPhotoCameraController::internalCapturePreview() {
    CameraFile *cameraFile;
    unsigned long int size;
    const char *data;
    //CameraEventType evttype;;
    //void *evtdata;

    int ret = gp_file_new(&cameraFile);
    if (!checkGPhotoSuccess(ret)) {
        // TODO error
        return;
    }

    ret = gp_camera_capture_preview(gp_camera, cameraFile, gp_context);
    if (!checkGPhotoSuccess(ret)) {
        // TODO error
        gp_file_free(cameraFile);
        return;
    }

    ret = gp_file_get_data_and_size(cameraFile, &data, &size);
    if (!checkGPhotoSuccess(ret)) {
        // TODO error
        gp_file_free(cameraFile);
        return;
    }
    //gp_camera_wait_for_event(gp_camera, 5000, &evttype, &evtdata, gp_context);
/*
    do {
    gp_camera_wait_for_event(gp_camera, 5000, &evttype, &evtdata, gp_context);
    } while (ret == GP_OK && (evttype != GP_EVENT_CAPTURE_COMPLETE || evttype != GP_EVENT_TIMEOUT));
*/
    //gp_file_save(cameraFile, "output.jpg");

    QImage image;
   /* char* buffer = new char[size];
    memcpy(buffer, data, size);

    QFile f("preview.jpg");
    f.open(QIODevice::WriteOnly);
    f.write(buffer, size);
    f.close();*/

    image.loadFromData((uchar*) data, size, "JPG");

    emit previewReady(image);
    gp_file_free(cameraFile);
    //delete [] buffer;
}
