#ifndef GPHOTOLISTCAMERASCOMMAND_H
#define GPHOTOLISTCAMERASCOMMAND_H

#include "gphoto/abstractgphotocommand.h"

class GPhotoListCamerasCommand : public AbstractGPhotoCommand
{
    Q_OBJECT
public:
    explicit GPhotoListCamerasCommand(QObject *parent = 0);

    void execute(GPhotoCameraController* controller);
signals:
    void camerasDetected(QList<GPhotoCameraHandle> camerasDetected);
public slots:

};

#endif // GPHOTOLISTCAMERASCOMMAND_H
