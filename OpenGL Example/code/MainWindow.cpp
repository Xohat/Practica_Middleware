
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2023.05

#include "MainWindow.hpp"

namespace esne
{

    MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
    {
        setupUi (this);

        setWindowFlag (Qt::MSWindowsFixedSizeDialogHint, true);

        //Aqui se concetan los botones de QT con las funciones de código
        connect (actionNew,       SIGNAL(triggered   (   )), this, SLOT(menuExitTriggered     (   )));
        connect (actionExit,      SIGNAL(triggered   (   )), this, SLOT(menuExitTriggered     (   )));
        connect (zoomLabelNumber, SIGNAL(triggered   (   )), this, SLOT(zoomChangeText        (int)));
        connect (zoomSlider,      SIGNAL(valueChanged(int)), this, SLOT(zRotationSliderChanged(int)));
    }

    void MainWindow::xRotationSliderChanged (int newValue)
    {

    }

    void MainWindow::yRotationSliderChanged (int newValue)
    {

    }

    void MainWindow::zRotationSliderChanged (int newValue)
    {
        //ZOOM EN SI

        //ZOOM TEXTO
        zoomChangeText((6.2831853f * newValue / 100.f) + 100);
    }

    void MainWindow::zoomChangeText(int newValue)
    {
        zoomLabelNumber->setText(QString::number(newValue) + "%");
    }
}
