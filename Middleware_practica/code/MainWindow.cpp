
/**
@file MainWindow.h
@brief Archivo encargado la ventana principal con QT
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#include "MainWindow.hpp"

namespace esne
{

    MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
    {
        setupUi (this);

        setWindowFlag (Qt::MSWindowsFixedSizeDialogHint, true);

        //Tengo que inicializar las variables con algun valor
        current_image_HB = new HeightBuffer(0, 0);
        new_brush = new Brush(0, 0);

        //Aqui se concetan los botones de QT con las funciones de código

        //Menu
        connect (actionExit_2,    SIGNAL(triggered   (   )), this, SLOT(menuExitTriggered       (   )));

        //File
        connect (actionNew,       SIGNAL(triggered   (   )), this, SLOT(menuFileNewTriggered    (   )));
        connect (actionOpen,      SIGNAL(triggered   (   )), this, SLOT(menuFileOpenTriggered   (   )));
        connect (actionSave,      SIGNAL(triggered   (   )), this, SLOT(menuFileSaveTriggered   (   )));
        connect (actionSave_As,   SIGNAL(triggered   (   )), this, SLOT(menuFileSaveAsTriggered (   )));

        //Zoom -> Deshabilitado por problemas con el refresco de la imagen
        // connect (zoomLabelNumber, SIGNAL(triggered   (   )), this, SLOT(zoomChangeText        (int)));
        // connect (zoomSlider,      SIGNAL(valueChanged(int)), this, SLOT(zoomSliderChanged     (int)));

        connect (brushPushButton, SIGNAL(clicked     (   )), this, SLOT(pressBrushButton      (   )));
        connect (colorPushButton, SIGNAL(clicked     (   )), this, SLOT(change_color          (   )));

        //Push button Signal --> clicked()
        //Menu button Signal --> triggered()
        //Slider Signal      --> valueChanged(int)
    }

    void MainWindow::zoomSliderChanged (int newValue)
    {
        //Efecto de Zoom
        if (oldZoomValue < newValue) zoomIn(newValue);
        else if (oldZoomValue > newValue) zoomOut(newValue);

        //Texto de zoom
        if (newValue < 1) 
        {
            newValue = -1;
        }
        zoomChangeText((newValue) + 101);
    }

    void MainWindow::menuFileSaveTriggered()
    {
        if (!image_to_load_Qt.save(QString::fromStdString(current_image_HB->get_path())))
        {
            QMessageBox::warning(this, ". .", "Failed saving image");
            return;
        }
    }

    void MainWindow::menuFileSaveAsTriggered()
    {
        // Saving image as
        QString file_name_ = QFileDialog::getSaveFileName(this, "Save the file as", "", "Images (*.png *.xpm *.jpg)");

        if (!image_to_load_Qt.save(file_name_))
        {
            QMessageBox::warning(this, ". .", "Failed saving image as");
            return;
        }
    }

    void MainWindow::menuFileOpenTriggered()
    {
        // Open popup
        QString file_name_ = QFileDialog::getOpenFileName(this, "Open the file", "", "Images (*.png *.xpm *.jpg)");
        current_image_HB->set_path(file_name_.toStdString());

        // Crea un Image loader si no existe y si existe cambia la imagen actual por la nueva
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

    void MainWindow::QtLoadImage(HeightBuffer& current_image) 
    {
        // Now we'll create a QImage from the height buffer data
        width = current_image.get_width();
        height = current_image.get_depth();

        QImage image(width, height, QImage::Format_RGB32);

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                // Get the height value as a color
                int colorValue = static_cast<int>(current_image.get_height(x, y));

                // We'll use the height value for all RGB channels to create a grayscale color
                QColor color(colorValue, colorValue, colorValue);
                image.setPixel(x, y, color.rgb());
            }
        }

        // You can then convert the QImage to a QPixmap
        QPixmap pixmap = QPixmap::fromImage(image);

        // Now you can use the QPixmap with a QLabel or any other widget
        // For example, if you have a QLabel named "label"

        pixmap = pixmap.scaled(placeholder->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Update width and height after scaling
        width = pixmap.width();
        height = pixmap.height();

        placeholder->setPixmap(pixmap);
        placeholder->setAlignment(Qt::AlignCenter);

        image_to_load_Qt = image;
    }

    void MainWindow::updateImageDisplay()
    {
        QLabel* placeholder = findChild<QLabel*>("placeholder", Qt::FindChildrenRecursively);
        if (placeholder && current_image_HB != nullptr)
        {
            QImage image(width, height, QImage::Format_RGB32);

            // Scale pixmap to fit in label, maintaining aspect ratio.
            QPixmap pixmap = QPixmap::fromImage(image).scaled(width * scaleFactor,
                height * scaleFactor,
                Qt::KeepAspectRatio, Qt::SmoothTransformation);

            placeholder->setPixmap(pixmap);
        }
    }

    void MainWindow::mousePressEvent(QMouseEvent* event)
    {
        QLabel* placeholder = findChild<QLabel*>("placeholder", Qt::FindChildrenRecursively);

        if (placeholder)
        {
            // Obtiene la imagen actual
            QPixmap pixmap = placeholder->pixmap();

            if (!pixmap.isNull())
            {
                // Calcula el offset por el AlignmenctCenter
                int xOffset = (placeholder->width() - pixmap.width()) / 2;
                int yOffset = (placeholder->height() - pixmap.height()) / 2;

                // Convierte la posicion de raton en posición de imagen
                // Parece haber desviaciones standard de 12 y 34
                int x = ((event->x() - xOffset) / scaleFactor);
                int y = ((event->y() - yOffset) / scaleFactor);

                int testxTotal = pixmap.width();
                int testyTotal = pixmap.height();

                int clickX = event->x();
                int clickY = event->y();

                // Comprueba si el click esta dentro de la width de la imagen (Requisito para poder pintar)
                if (x >= 0 && y >= 0 && x < pixmap.width() && y < pixmap.height())
                {
                    // Esto hace las coordenadas de x e y relativas a la imagen
                    qDebug() << "Mouse clicked at pixmap coordinates:" << x << y;

                    // Proceso de paint
                    // Si la brocha no esta activa no se puede pintar
                    if (new_brush->get_active())
                    {
                        //Pinta
                        qDebug() << "Painting started on pixel(" << x << "," << y << ")";

                        //Se settea un width y un height estandar
                        new_brush->set_width(20);
                        new_brush->set_height(20);

                        //Se itera por todos los pixeles del tamaño de la brush
                        for (int i = 0; i < new_brush->get_width(); i++)
                        {
                            for (int j = 0; j < new_brush->get_height(); j++)
                            {
                                paintPixel(*current_image_HB, new_brush->get_color(), x + i, y + j);
                            }
                        }

                        //Tras haber pintado todos los pixeles se actualiza la imagen de manera visual en QT
                        QtLoadImage(*current_image_HB);
                    }
                    else
                    {
                        qDebug() << "No brush selected, cant paint";
                    }
                }
                else
                {
                    qDebug() << "Mouse clicked outside the pixmap";
                }
            }
        }
    }
}
