
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2023.05

#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_MainWindow.h"

namespace esne
{

    class OpenGLWidget;

    /** Esta es la ventana principal de la aplicación. Es la que se abre directamente cuando esta
      * se inicia. Cuenta con una barra de menú y un widget central en el que se incrustan otros
      * widgets.
      */
    class MainWindow : public QMainWindow, public Ui::MainWindowClass
    {
        Q_OBJECT

    public:

        /** Inicializa todos los widgets creados con QtDesigner e inserta el OpenGLWidget dentro
          * del widget 'placeholder' que ya está puesto. También conecta algunas señales con los
          * slots de la clase.
          */
        MainWindow(QWidget *parent = nullptr);

    public slots:

        /** Este método está conectado con la acción File / Open del menú. Abre un archivo de formato imagen soportado ().
          */
        void menuFileOpenTriggered()
        {
            
        }

        /** Este método está conectado con la acción Exit del menú. Cierra la aplicación.
          */
        void menuExitTriggered ()
        {
            QApplication::quit ();
        }

        // Estos métodos están conectados con las señales que emiten los sliders:

        void xRotationSliderChanged (int newValue);
        void yRotationSliderChanged (int newValue);
        void zRotationSliderChanged (int newValue);

        void zoomChangeText(int newValue);    
    };
}
