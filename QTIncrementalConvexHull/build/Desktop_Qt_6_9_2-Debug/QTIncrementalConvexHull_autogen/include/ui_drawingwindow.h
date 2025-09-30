/********************************************************************************
** Form generated from reading UI file 'drawingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGWINDOW_H
#define UI_DRAWINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingWindow
{
public:
    QWidget *centralwidget;
    QPushButton *convexHullButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DrawingWindow)
    {
        if (DrawingWindow->objectName().isEmpty())
            DrawingWindow->setObjectName("DrawingWindow");
        DrawingWindow->resize(800, 600);
        DrawingWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(DrawingWindow);
        centralwidget->setObjectName("centralwidget");
        convexHullButton = new QPushButton(centralwidget);
        convexHullButton->setObjectName("convexHullButton");
        convexHullButton->setGeometry(QRect(10, 400, 211, 27));
        convexHullButton->setAutoFillBackground(false);
        convexHullButton->setCheckable(false);
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(240, 400, 211, 27));
        clearButton->setAutoFillBackground(false);
        clearButton->setCheckable(false);
        DrawingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DrawingWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        DrawingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DrawingWindow);
        statusbar->setObjectName("statusbar");
        DrawingWindow->setStatusBar(statusbar);

        retranslateUi(DrawingWindow);

        QMetaObject::connectSlotsByName(DrawingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DrawingWindow)
    {
        DrawingWindow->setWindowTitle(QCoreApplication::translate("DrawingWindow", "DrawingCanvas", nullptr));
        convexHullButton->setText(QCoreApplication::translate("DrawingWindow", "Solve Convex Hull", nullptr));
        clearButton->setText(QCoreApplication::translate("DrawingWindow", "Clear All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawingWindow: public Ui_DrawingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGWINDOW_H
