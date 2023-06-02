
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2023.05

#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QColorDialog>
#include <QMouseEvent>

#include "RoundBrush.h"
#include "ImageLoader.h"
#include "RoundBrush.h"
#include "ImageController.h"

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

        // Estos métodos están conectados con las señales que emiten los sliders:
        void zoomSliderChanged(int newValue);

        void menuFileNewTriggered() 
        {
            file_path_ = "";
            current_image_HB->set_path("../../assets/new_image.png");

            // Create an ImageLoader and load the image into the height buffer if necessary
            if (image_loader == nullptr)
            {
                image_loader = new ImageLoader(*current_image_HB);
            }
            else
            {
                image_loader->change_image(*current_image_HB);
            }

            QtLoadImage(*current_image_HB);
        }

        /** Este método está conectado con la acción File / Open del menú. Abre un archivo de formato imagen soportado ().
          */
        void menuFileOpenTriggered();
        void menuFileSaveTriggered();
        void menuFileSaveAsTriggered();

        void zoomChangeText(int newValue)
        {
            zoomLabelNumber->setText(QString::number(newValue) + "%");
        }

        /** Este método está conectado con la acción Exit del menú. Cierra la aplicación.
          */
        void menuExitTriggered ()
        {
            QApplication::quit ();
        }

        void zoomIn(int newValue)
        {
            scaleFactor = 1 + newValue / 100.f;
            oldZoomValue = newValue;
            updateImageDisplay();
        }

        void zoomOut(int newValue)
        {
            scaleFactor = 1 + newValue / 100.f;
            oldZoomValue = newValue;
            updateImageDisplay();
        }

        void updateImageDisplay();

        void pressBrushButton() 
        {
            new_brush->set_active();
        }

        void mousePressEvent (QMouseEvent* event) override;

        void paintPixel (HeightBuffer& current_image, float new_color, int pixel_x, int pixel_y)
        {
            if (image_controller == nullptr) 
            {
                image_controller = new ImageController(*current_image_HB);
            }
            else 
            {
                image_controller->paint(current_image, new_color, pixel_x, pixel_y);
            }
        }

        void QtLoadImage (HeightBuffer& current_image);

        void change_color() 
        {
            QColor color = QColorDialog::getColor(Qt::white, this, "Select a color, all colors must be the same value");
            if (color.isValid()) 
            {
                if (new_brush->get_active()) 
                {
                    // toma el promedio de los valores de color
                    int average = (color.red() + color.green() + color.blue()) / 3;
                    new_brush->set_color(average);
                }
                else 
                {
                    QMessageBox::warning(this, ". .", "Brush not selected");
                }
            }
            else 
            {
                QMessageBox::warning(this, ". .", "Failed putting color");
            }
        }

        void set_brush_width() 
        {

        }

        void set_brush_height()
        {

        }

    private:

        QString file_path_;
        qreal scaleFactor = 1.0;
        QImage image_to_load_Qt;

        QPoint imageOffset;
        bool dragging = false;
        QPoint lastMousePos;

        int oldZoomValue = 0;
        int width;
        int height;

        float new_color = 0;

        RoundBrush* new_brush;
        HeightBuffer* current_image_HB;
        ImageLoader* image_loader = nullptr;
        ImageController* image_controller = nullptr;
    };
}
