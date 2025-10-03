#include "drawingwindow.h"
#include "ui_drawingwindow.h"
#include "drawingcanvas.h" // Include the new canvas
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QSpacerItem>

DrawingWindow::DrawingWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::DrawingWindow)
{
    ui->setupUi(this);

    setWindowTitle("Qt Interactive Drawing App");

    setFixedSize(500, 450);

    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(ui->centralwidget->layout());

    if (!mainLayout) {
        mainLayout = new QVBoxLayout(ui->centralwidget);
        qDebug() << "Warning: No layout found in UI form. Created a new QVBoxLayout.";
    }

    m_drawingWidget = new DrawingCanvas(this);

    QLabel *instructionLabel = new QLabel("Click inside the purple box to draw points. Use input field to update text.", this);
    instructionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
    instructionLabel->setStyleSheet("font-size: 12px; color: #77777777;");
    mainLayout->addWidget(instructionLabel);

    mainLayout->addStretch();

    mainLayout->addWidget(m_drawingWidget, 0, Qt::AlignCenter);

    mainLayout->addStretch();
}

DrawingWindow::~DrawingWindow()
{
    delete ui;
}

void DrawingWindow::on_clearButton_clicked()
{
    m_drawingWidget->clearPoints();

    m_drawingWidget->setDrawingText("Cleared!");

    qDebug() << "Clear button clicked. Canvas points removed.";
}

void DrawingWindow::on_convexHullButton_clicked()
{
    qDebug() << "Solve button clicked. Calculating Convex Hull.";

    m_drawingWidget->drawConvexHull();
    m_drawingWidget->setDrawingText("Solved!");
}
