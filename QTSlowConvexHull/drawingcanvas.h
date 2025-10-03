#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <QPoint>

class DrawingCanvas : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingCanvas(QWidget *parent = nullptr);

    void setDrawingText(const QString& text);

    void clearPoints();

    void drawConvexHull();

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    QVector<QPoint> m_points; // Stores all clicked points (dots)
    QVector<QPoint> m_convexHull;     // Stores the points that form the outer perimeter
    bool m_showHull = false;
    QString m_currentText;

    int m_iterationCount = 0;
};

#endif // DRAWINGCANVAS_H
