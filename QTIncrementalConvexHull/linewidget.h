#ifndef LINEWIDGET_H
#define LINEWIDGET_H

#include <QVector>
#include <QPoint>
#include <cstddef>


class LineWidget
{
    LineWidget() = default;

public:
    static QVector<QPoint> incrementalConvexHull(const QVector<QPoint>& points, int& iterationCount);

private:
    static int crossProduct(const QPoint& o, const QPoint& a, const QPoint& b);
};

#endif // LINEWIDGET_H
