/*
 * This file is part of the Photomaton-mobile package.
 *
 * (c) Romain Lamarche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1


Item {
    property string message
    anchors.fill: parent

    MouseArea {
       anchors.fill: parent

    }

    Rectangle {
        opacity: 0.5
        anchors.fill: parent
        color: "red"
    }

    Rectangle {
        id: errorMessage



        width: childrenRect.width + 20
        height: childrenRect.height + 20
        color: "red"

        Text {
            id: name
            text: qsTr(message)
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
        }

        anchors.centerIn: parent
    }
}
