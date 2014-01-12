#include "application.h"

Application::Application(QObject *parent) :
    QObject(parent)
{
    graphicsView.setScene(&graphicsScene);
}

void Application::show() {
    graphicsView.show();
}
