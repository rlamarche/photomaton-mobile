#include "mainwindow.h"
#include <QApplication>

#include "application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Application application;
    application.show();


  //  GraphicsView view;
   /* view.setViewport(widget);
    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setScene(&scene);*/
   // view.show();

    /*
    MainWindow w;
    w.show();
*/
    return a.exec();
}
