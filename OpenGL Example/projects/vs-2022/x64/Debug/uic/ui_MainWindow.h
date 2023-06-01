/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionExit_2;
    QAction *actionConfiguration;
    QWidget *centralWidget;
    QWidget *placeholder;
    QLabel *ZoomLabel;
    QSlider *zoomSlider;
    QLabel *zoomLabelNumber;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuFile;
    QMenu *menuDocument;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(676, 505);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName("actionExit");
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName("actionSave");
        actionExport = new QAction(MainWindowClass);
        actionExport->setObjectName("actionExport");
        actionExit_2 = new QAction(MainWindowClass);
        actionExit_2->setObjectName("actionExit_2");
        actionConfiguration = new QAction(MainWindowClass);
        actionConfiguration->setObjectName("actionConfiguration");
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        placeholder = new QWidget(centralWidget);
        placeholder->setObjectName("placeholder");
        placeholder->setGeometry(QRect(40, 20, 621, 431));
        placeholder->setAutoFillBackground(false);
        placeholder->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 224, 255);"));
        ZoomLabel = new QLabel(centralWidget);
        ZoomLabel->setObjectName("ZoomLabel");
        ZoomLabel->setGeometry(QRect(180, 450, 31, 31));
        zoomSlider = new QSlider(centralWidget);
        zoomSlider->setObjectName("zoomSlider");
        zoomSlider->setGeometry(QRect(40, 460, 91, 16));
        zoomSlider->setOrientation(Qt::Horizontal);
        zoomLabelNumber = new QLabel(centralWidget);
        zoomLabelNumber->setObjectName("zoomLabelNumber");
        zoomLabelNumber->setGeometry(QRect(140, 450, 31, 31));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 676, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName("menuMenu");
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuDocument = new QMenu(menuBar);
        menuDocument->setObjectName("menuDocument");
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName("menuAbout");
        MainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDocument->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuMenu->addAction(actionExit);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport);
        menuDocument->addAction(actionConfiguration);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindowClass", "Exit", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindowClass", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindowClass", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindowClass", "Save", nullptr));
        actionExport->setText(QCoreApplication::translate("MainWindowClass", "Export", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindowClass", "Exit", nullptr));
        actionConfiguration->setText(QCoreApplication::translate("MainWindowClass", "Configuration", nullptr));
        ZoomLabel->setText(QCoreApplication::translate("MainWindowClass", "Zoom", nullptr));
        zoomLabelNumber->setText(QCoreApplication::translate("MainWindowClass", "100%", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindowClass", "Menu", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindowClass", "File", nullptr));
        menuDocument->setTitle(QCoreApplication::translate("MainWindowClass", "Document", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindowClass", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
