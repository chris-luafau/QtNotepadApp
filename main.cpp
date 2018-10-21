#include "mainwindow.h"
#include <QApplication> // handles widgets, event handling, mouse movement, overall feel of windows

int main(int argc, char *argv[])    // where program execution begins...duh
{
    QApplication a(argc, argv); // creates the application object
    MainWindow w;   // create the window object
    w.show();   // display on screen

    return a.exec();    // puts application into a loop
}
