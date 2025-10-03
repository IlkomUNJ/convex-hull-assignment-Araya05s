#include "linewidget.h"
#include <QDebug>
#include <algorithm>

int LineWidget::crossProduct(const QPoint& o, const QPoint& a, const QPoint& b)
{
    return (a.x() - o.x()) * (b.y() - o.y()) - (a.y() - o.y()) * (b.x() - o.x());
}

long long distanceSq(const QPoint& p1, const QPoint& p2) {
    long long dx = p1.x() - p2.x();
    long long dy = p1.y() - p2.y();
    return dx * dx + dy * dy;
}

// Implementation of the slow calculation function
QVector<QPoint> LineWidget::slowConvexHull(const QVector<QPoint>& points, int& iterationCount)
{
    iterationCount = 0;

    if (points.size() <= 2) return points;

    QSet<QPair<int, int>> valid_edges;
    int N = points.size();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            const QPoint& p = points[i];
            const QPoint& q = points[j];
            bool is_hull_edge = true;

            for (int k = 0; k < N; ++k) {
                if (k == i || k == j) continue;

                const QPoint& r = points[k];
                iterationCount++;

                int cp = crossProduct(p, q, r);

                if (cp > 0) {
                    is_hull_edge = false;
                    break;
                }

                if (cp == 0) {
                    bool r_is_interior_x = (r.x() >= std::min(p.x(), q.x())) && (r.x() <= std::max(p.x(), q.x()));
                    bool r_is_interior_y = (r.y() >= std::min(p.y(), q.y())) && (r.y() <= std::max(p.y(), q.y()));

                    if (r_is_interior_x && r_is_interior_y) {

                        if (distanceSq(p, r) > distanceSq(p, q)) {

                            is_hull_edge = false;
                            break;
                        }
                    }
                }
            }

            if (is_hull_edge) {
                valid_edges.insert({i, j});
            }
        }
    }

    QVector<QPoint> hull;
    if (valid_edges.isEmpty()) return hull;

    int start_index = -1;
    for (int i = 0; i < N; ++i) {
        if (start_index == -1 || points[i].y() < points[start_index].y() ||
            (points[i].y() == points[start_index].y() && points[i].x() < points[start_index].x()))
        {
            start_index = i;
        }
    }

    int current_point_index = start_index;
    int initial_start_index = start_index;

    do {
        hull.append(points[current_point_index]);

        int next_point_index = -1;
        long long max_dist_sq = -1;

        for (const auto& edge : valid_edges) {
            if (edge.first == current_point_index) {
                int potential_next_index = edge.second;

                long long dist_sq = distanceSq(points[current_point_index], points[potential_next_index]);

                if (dist_sq > max_dist_sq) {
                    max_dist_sq = dist_sq;
                    next_point_index = potential_next_index;
                }
            }
        }

        if (next_point_index == -1) {
            qDebug() << "Hull chain failed to find the next point.";
            break;
        }

        current_point_index = next_point_index;

    } while (current_point_index != initial_start_index && hull.size() <= N + 1); // Limit loop size


    if (!hull.isEmpty() && hull.last() == points[initial_start_index] && hull.size() > 1) {
        hull.removeLast();
    }

    return hull;

}

