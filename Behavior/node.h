//////////////////////////////////////////////////////////////////////////
// node.h -- Header file for display the nodes in QT canvas.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

#include "graphwidget.h"
#include "edge.h"
#include "enums.h"
#include "Transformation.h"

class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node : public QGraphicsItem
{
public:
    Node(GraphWidget *graphWidget, NodeType nodeType = InterpPoints);

    enum { Type = UserType + 1 };
    int type() const { return Type; }

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    vec3 getPosition();
    void setPosition(vec3 pos);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    NodeType nodeType;

private:
    GraphWidget *graph;
};

#endif
