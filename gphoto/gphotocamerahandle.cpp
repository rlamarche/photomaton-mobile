/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

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
