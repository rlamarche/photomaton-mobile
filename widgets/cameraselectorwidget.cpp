#include "cameraselectorwidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>

CameraSelectorWidget::CameraSelectorWidget(QWidget *parent) :
    QWidget(parent)
{
    QFormLayout *layout = new QFormLayout(this);
    setLayout(layout);

    QLabel *label = new QLabel(tr("Detected cameras:"), this);

    QComboBox *cameraSelectorComboBox = new QComboBox(this);
    cameraSelectorComboBox->addItem(QString("mock camera 1"));
    layout->addRow(label, cameraSelectorComboBox);
}

void CameraSelectorWidget::setSceneRect(const QRectF &rect) {
    resize(rect.width(), 50);
}

void CameraSelectorWidget::sceneRectChanged(const QRectF &rect) {
    setSceneRect(rect);
}
