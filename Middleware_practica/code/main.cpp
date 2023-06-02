
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2023.05

#include "MainWindow.hpp"
#include <QtWidgets/QApplication>

int main (int number_of_arguments, char * arguments[])
{
    QApplication application(number_of_arguments, arguments);
    
    esne::MainWindow window;
    
    window.show ();

    return application.exec ();
}
