#ifndef GPHOTOCAPTUREPREVIEWCOMMAND_H
#define GPHOTOCAPTUREPREVIEWCOMMAND_H

#include "gphoto/abstractgphotocommand.h"

class GPhotoCapturePreviewCommand : public AbstractGPhotoCommand
{
    Q_OBJECT
public:
    explicit GPhotoCapturePreviewCommand(QObject *parent = 0);
    void execute(GPhotoCameraController* controller);
signals:

public slots:

};

#endif // GPHOTOCAPTUREPREVIEWCOMMAND_H
