#include "gphotolistcamerascommand.h"

GPhotoListCamerasCommand::GPhotoListCamerasCommand(QObject *parent) :
    AbstractGPhotoCommand(parent)
{
}

void GPhotoListCamerasCommand::execute()
{
    int count;
    CameraList *list;
    const char *name = NULL, *value = NULL;
    QList<GPhotoCameraHandle>* detectedCameras = new QList<GPhotoCameraHandle>();

    if (!context) {
        // TODO throw error
    }

    gp_list_new (&list);
    count = gp_camera_autodetect(list, context);

    for (int i = 0; i < count; i ++) {
        gp_list_get_name  (list, i, &name);
        gp_list_get_value (list, i, &value);

        detectedCameras->append(GPhotoCameraHandle(i, QString(name), QString(value)));
    }

    gp_list_free(list);

    emit camerasDetected(detectedCameras);
}
