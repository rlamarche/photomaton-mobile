#include "gphotocamerahandle.h"
/*
GPhotoCameraHandle::GPhotoCameraHandle(QObject *parent) :
    QObject(parent)
{
}
*/

GPhotoCameraHandle::GPhotoCameraHandle(QString model, QString port) :
    m_model(model),
    m_port(port)
{

}

QString GPhotoCameraHandle::model() {
    return m_model;
}

QString GPhotoCameraHandle::port() {
    return m_port;
}
