#include "abstractgphotocommand.h"

AbstractGPhotoCommand::AbstractGPhotoCommand(QObject *parent) :
    QObject(parent)
{
}

void AbstractGPhotoCommand::setGPContext(GPContext *context)
{
    this->context = context;
}
