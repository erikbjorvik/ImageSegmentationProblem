#include "mainwindow.h"
#include <QApplication>
//#include <glpk.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Image Segmentation Problem");

    w.show();

    return a.exec();
    return 0;
}
