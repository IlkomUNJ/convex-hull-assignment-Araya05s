#include "linewidget.h"
#include <QDebug>
#include <algorithm>

int LineWidget::crossProduct(const QPoint& o, const QPoint& a, const QPoint& b)
{
    return (a.x() - o.x()) * (b.y() - o.y()) - (a.y() - o.y()) * (b.x() - o.x());
}

QVector<QPoint> LineWidget::incrementalConvexHull(const QVector<QPoint>& points, int& iterationCount)
{
    iterationCount = 0;

    if (points.size() <= 2) return points;

    QVector<QPoint> sortedPoints = points;

    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const QPoint& a, const QPoint& b) {
        if (a.x() != b.x()) return a.x() < b.x();
        return a.y() < b.y();
    });

    QVector<QPoint> hull;
    hull.append(sortedPoints[0]);
    hull.append(sortedPoints[1]);
    hull.append(sortedPoints[2]);

    if (crossProduct(hull[0], hull[1], hull[2]) <= 0) {
        std::swap(hull[1], hull[2]);
    }

    for (int i = 3; i < sortedPoints.size(); ++i) {

        iterationCount++;

        const QPoint& p = sortedPoints[i];

        bool isOutside = false;

        for (int j = 0; j < hull.size(); ++j) {
            const QPoint& p1 = hull[j];
            const QPoint& p2 = hull[(j + 1) % hull.size()];

            if (crossProduct(p1, p2, p) < 0) {
                isOutside = true;
                break;
            }
        }

        if (!isOutside) continue;

        int hull_size = hull.size();
        int i_start = -1;
        int i_end = -1;

        for (int j = 0; j < hull_size; ++j) {
            const QPoint& p_prev = hull[(j - 1 + hull_size) % hull_size];
            const QPoint& p_curr = hull[j];
            const QPoint& p_next = hull[(j + 1) % hull_size];

            if (crossProduct(p_prev, p_curr, p) <= 0 && crossProduct(p_curr, p_next, p) > 0) {
                i_start = j;
            }

            if (crossProduct(p_prev, p_curr, p) > 0 && crossProduct(p_curr, p_next, p) <= 0) {
                i_end = j;
            }
        }

        if (i_start == -1 || i_end == -1) {
            qDebug() << "Error: Tangent indices not found correctly.";
            continue;
        }

        QVector<QPoint> newHull;

        int current = i_end;
        while (current != i_start) {
            newHull.append(hull[current]);
            current = (current + 1) % hull_size;
        }
        newHull.append(hull[i_start]);

        newHull.append(p);

        hull = newHull;
    }

    return hull;
}

