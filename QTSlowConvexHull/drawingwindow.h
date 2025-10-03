#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <QMainWindow>
#include <QString>

class DrawingCanvas;

QT_BEGIN_NAMESPACE
namespace Ui {
class DrawingWindow;
}
QT_END_NAMESPACE

class DrawingWindow : public QMainWindow
{
    Q_OBJECT

public:
    DrawingWindow(QWidget *parent = nullptr);
    ~DrawingWindow();

private slots:
    void on_clearButton_clicked();
    void on_convexHullButton_clicked();

private:
    Ui::DrawingWindow *ui;
    DrawingCanvas *m_drawingWidget;
};

#endif // DRAWINGWINDOW_H
