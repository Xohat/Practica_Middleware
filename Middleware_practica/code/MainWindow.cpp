
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

        //Menu
        connect (actionExit,      SIGNAL(triggered   (   )), this, SLOT(menuExitTriggered     (   )));

        //File
        connect (actionNew,       SIGNAL(triggered   (   )), this, SLOT(menuFileNewTriggered  (   )));
        connect (actionOpen,      SIGNAL(triggered   (   )), this, SLOT(menuFileOpenTriggered (   )));
        connect (actionSave,      SIGNAL(triggered   (   )), this, SLOT(menuFileSaveTriggered (   )));

        //Zoom
        connect (zoomLabelNumber, SIGNAL(triggered   (   )), this, SLOT(zoomChangeText        (int)));
        connect (zoomSlider,      SIGNAL(valueChanged(int)), this, SLOT(zoomSliderChanged     (int)));

        //Push button Signal --> clicked()
        //Menu button Signal --> triggered()
        //Slider Signal      --> valueChanged(int)
    }

    void MainWindow::zoomSliderChanged (int newValue)
    {
        //ZOOM EN SI
        if (oldZoomValue < newValue) zoomIn(newValue);
        else if (oldZoomValue > newValue) zoomOut(newValue);

        //ZOOM TEXTO (VA 0 a 100)
        if (newValue < 1) 
        {
            newValue = -1;
        }
        zoomChangeText((newValue) + 101);
    }

    void MainWindow::menuFileSaveTriggered()
    {
        // Saving image
        QString file_name_ = QFileDialog::getSaveFileName(this, "Save the file", "", "Images (*.png *.xpm *.jpg)");

        if (!currentImage.save(file_name_))
        {
            QMessageBox::warning(this, ". .", "Failed saving image");
            return;
        }
    }

    void MainWindow::menuFileSaveAsTriggered()
    {
        // Saving image as
        QString file_name_ = QFileDialog::getSaveFileName(this, "Save the file as", "", "Images (*.png *.xpm *.jpg)");

        if (!currentImage.save(file_name_))
        {
            QMessageBox::warning(this, ". .", "Failed saving image as");
            return;
        }
    }

    void MainWindow::menuFileOpenTriggered()
    {
        // Opening image
        QString file_name_ = QFileDialog::getOpenFileName(this, "Open the file", "", "Images (*.png *.xpm *.jpg)");

        if (!currentImage.load(file_name_))
        {
            QMessageBox::warning(this, ". .", "Failed opening image");
            return;
        }

        QLabel* placeholder = findChild<QLabel*>("placeholder", Qt::FindChildrenRecursively);
        if (placeholder)
        {
            // Scale pixmap to fit in label, maintaining aspect ratio.
            QPixmap pixmap = QPixmap::fromImage(currentImage).scaled(placeholder->width(), placeholder->height(),
                Qt::KeepAspectRatio, Qt::SmoothTransformation);

            placeholder->setPixmap(pixmap);
            placeholder->setFixedSize(placeholder->size());

            width = placeholder->width();
            height = placeholder->height();

            // Align image to Center of QLabel
            placeholder->setAlignment(Qt::AlignCenter);
        }
        else
        {
            QMessageBox::warning(this, ". .", "Failed to find placeholder widget");
        }
    }

    void MainWindow::updateImageDisplay()
    {
        QLabel* placeholder = findChild<QLabel*>("placeholder", Qt::FindChildrenRecursively);
        if (placeholder && !currentImage.isNull())
        {
            // Scale pixmap to fit in label, maintaining aspect ratio.
            QPixmap pixmap = QPixmap::fromImage(currentImage).scaled(width * scaleFactor,
                                                                     height * scaleFactor,
            Qt::KeepAspectRatio, Qt::SmoothTransformation);

            placeholder->setPixmap(pixmap);
        }
    }
}
