//////////////////////////////////////////////////////////////////////////
// graphwidget.h -- Header file for QT graph widgets for display the curve.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
#include <QtGui/QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtGui/QComboBox>
#include "graphicsscene.h"
#include "spline.h"
#include "enums.h"

class Node;
class Spline;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);
    void AddInterpPoints(Node * newNode);

    Spline *spline;

    QToolBar *toolBar;
    QAction *actionClear_Scene;
    QAction *actionShow_Control_Points;
    QComboBox *methodChooseComboBox;

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();
    void on_actionClear_Scene_triggered();
    void on_methodChooseComboBox_currentIndexChanged(int index);
    void on_actionShow_Control_Points_triggered(bool checked);

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void drawBackground(QPainter *painter, const QRectF &rect);

    void scaleView(qreal scaleFactor);

private:
};

#endif // GRAPHWIDGET_H
