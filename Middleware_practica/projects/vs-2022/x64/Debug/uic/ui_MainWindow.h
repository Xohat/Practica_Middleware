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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit_2;
    QAction *actionSave_As;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *ImageShowerLayou;
    QVBoxLayout *EditButtonLayout;
    QVBoxLayout *ZoomLayout;
    QHBoxLayout *ImageShowerLayout;
    QLabel *placeholder;
    QSlider *zoomSlider;
    QLabel *zoomLabelNumber;
    QPushButton *brushPushButton;
    QPushButton *colorPushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(631, 506);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName("actionExit");
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName("actionSave");
        actionExit_2 = new QAction(MainWindowClass);
        actionExit_2->setObjectName("actionExit_2");
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName("actionSave_As");
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        ImageShowerLayou = new QHBoxLayout();
        ImageShowerLayou->setSpacing(6);
        ImageShowerLayou->setObjectName("ImageShowerLayou");
        EditButtonLayout = new QVBoxLayout();
        EditButtonLayout->setSpacing(6);
        EditButtonLayout->setObjectName("EditButtonLayout");
        ZoomLayout = new QVBoxLayout();
        ZoomLayout->setSpacing(6);
        ZoomLayout->setObjectName("ZoomLayout");
        ImageShowerLayout = new QHBoxLayout();
        ImageShowerLayout->setSpacing(6);
        ImageShowerLayout->setObjectName("ImageShowerLayout");
        placeholder = new QLabel(centralWidget);
        placeholder->setObjectName("placeholder");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(placeholder->sizePolicy().hasHeightForWidth());
        placeholder->setSizePolicy(sizePolicy1);
        placeholder->setAutoFillBackground(true);
        placeholder->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);"));

        ImageShowerLayout->addWidget(placeholder);


        ZoomLayout->addLayout(ImageShowerLayout);

        zoomSlider = new QSlider(centralWidget);
        zoomSlider->setObjectName("zoomSlider");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(zoomSlider->sizePolicy().hasHeightForWidth());
        zoomSlider->setSizePolicy(sizePolicy2);
        zoomSlider->setOrientation(Qt::Horizontal);

        ZoomLayout->addWidget(zoomSlider);

        zoomLabelNumber = new QLabel(centralWidget);
        zoomLabelNumber->setObjectName("zoomLabelNumber");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(zoomLabelNumber->sizePolicy().hasHeightForWidth());
        zoomLabelNumber->setSizePolicy(sizePolicy3);
        zoomLabelNumber->setAutoFillBackground(true);
        zoomLabelNumber->setStyleSheet(QString::fromUtf8("Color:rgb(0, 0, 0)"));

        ZoomLayout->addWidget(zoomLabelNumber);

        brushPushButton = new QPushButton(centralWidget);
        brushPushButton->setObjectName("brushPushButton");
        sizePolicy.setHeightForWidth(brushPushButton->sizePolicy().hasHeightForWidth());
        brushPushButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../resources/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushPushButton->setIcon(icon);
        brushPushButton->setIconSize(QSize(28, 28));
#if QT_CONFIG(shortcut)
        brushPushButton->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        ZoomLayout->addWidget(brushPushButton);

        colorPushButton = new QPushButton(centralWidget);
        colorPushButton->setObjectName("colorPushButton");
        sizePolicy.setHeightForWidth(colorPushButton->sizePolicy().hasHeightForWidth());
        colorPushButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../resources/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorPushButton->setIcon(icon1);
        colorPushButton->setIconSize(QSize(28, 28));
#if QT_CONFIG(shortcut)
        colorPushButton->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        ZoomLayout->addWidget(colorPushButton);


        EditButtonLayout->addLayout(ZoomLayout);


        ImageShowerLayou->addLayout(EditButtonLayout);


        horizontalLayout->addLayout(ImageShowerLayou);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 631, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        MainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);

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
        actionExit_2->setText(QCoreApplication::translate("MainWindowClass", "Exit", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindowClass", "Save As", nullptr));
        placeholder->setText(QString());
        zoomLabelNumber->setText(QCoreApplication::translate("MainWindowClass", "100% Zoom", nullptr));
        brushPushButton->setText(QString());
        colorPushButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
