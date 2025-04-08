#include "mainwindow.h"
#include "insulinpump.h"
#include "simulation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    Simulation sim;

    sim.createProfile();

}
