//////////////////////////////////////////////////////////////////////////
// graphicsscene.h -- Header file for hard coded QT canvas
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QtGui/QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>

#include "graphwidget.h"
#include "node.h"
#include "graphwidget.h"

class GraphWidget;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(GraphWidget* graphWiget);

protected:
    void mousePressEvent (QGraphicsSceneMouseEvent * mouseEvent);

private:
    bool hasSelection(QPointF mousePos);
    GraphWidget *graph;
};

#endif // GRAPHICSSCENE_H
