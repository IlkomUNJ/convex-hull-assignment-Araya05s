#include "drawingcanvas.h"
#include "linewidget.h"
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QPoint>
#include <QFont>
#include <QMouseEvent> // Required for mouse event handling
#include <QDebug>

DrawingCanvas::DrawingCanvas(QWidget *parent) : QWidget{parent}
{
    setFixedSize(600, 300);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setStyleSheet("background-color: #e6f0ff; border: 2px dashed #99c2ff;");
}

void DrawingCanvas::setDrawingText(const QString& text)
{
    m_currentText = text;
    update();
}

void DrawingCanvas::drawConvexHull()
{
    if (m_points.size() < 3) {
        m_showHull = false;
        m_iterationCount = 0;
        qDebug() << "Need at least 3 points to draw a convex hull.";
    } else {
        int count = 0;

        m_convexHull = LineWidget::incrementalConvexHull(m_points, count);

        m_iterationCount = count;
        m_showHull = true;
    }
    update();
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event)
{
    QPoint clickedPoint = event->pos();

    m_points.append(clickedPoint);

    qDebug() << "Point added at:" << clickedPoint;

    update();
}

void DrawingCanvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    QPen pen(QColor(55, 55, 160));
    pen.setWidth(8);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);

    painter.setPen(pen);

    if (!m_points.isEmpty()) {
        painter.drawPoints(m_points.data(), m_points.size());
    }

    if (m_showHull && m_convexHull.size() > 1) {
        QPen linePen(QColor(0, 150, 200));
        linePen.setWidth(3);
        linePen.setStyle(Qt::DashLine);
        painter.setPen(linePen);

        painter.drawPolyline(m_convexHull.data(), m_convexHull.size());

        if (m_convexHull.size() > 2) {
            painter.drawLine(m_convexHull.last(), m_convexHull.first());
        }
    }

    QPen textPen(Qt::cyan);
    painter.setPen(textPen);
    painter.setFont(QFont("Arial", 12));

    QString countText = QString("Iterations: %1").arg(m_iterationCount);

    QRect countRect(300, 150, 140, 150);

    painter.drawText(countRect, Qt::AlignBottom | Qt::AlignRight, countText);
}

void DrawingCanvas::clearPoints()
{
    m_points.clear();
    m_showHull = false;
    m_iterationCount = 0;
    update();
}
