#ifndef LINEWIDGET_H
#define LINEWIDGET_H

#include <QVector>
#include <QPoint>
#include <cstddef>


class LineWidget
{
    LineWidget() = default;
public:
    static QVector<QPoint> slowConvexHull(const QVector<QPoint>& points, int& iterationCount);

private:
    // Helper function used in the calculation (determines turn direction).
    // Returns < 0 for right turn, > 0 for left turn, 0 for collinear.
    static int crossProduct(const QPoint& o, const QPoint& a, const QPoint& b);
};

#endif // LINEWIDGET_H
