/**
@file ImageLoader.h
@brief Archivo encargado de representar la window principal
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QColorDialog>
#include <QMouseEvent>

#include "ImageLoader.h"
#include "Brush.h"
#include "ImageController.h"

#include "ui_MainWindow.h"

namespace esne
{

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
            zoomLabelNumber->setText(QString::number(newValue) + "% Zoom");
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

        //Zoom
        qreal scaleFactor = 1.0;
        int oldZoomValue = 0;

        //Carga de imagenes
        QString file_path_;
        QImage image_to_load_Qt;
        HeightBuffer* current_image_HB;
        ImageLoader* image_loader = nullptr;
        int width = 0;
        int height = 0;

        //Manejo de imagen
        ImageController* image_controller = nullptr;

        //Configuración de la Brush
        Brush* new_brush;
        float new_color = 0;

        
    };
}
