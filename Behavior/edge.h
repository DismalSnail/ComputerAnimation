//////////////////////////////////////////////////////////////////////////
// edge.h -- Header file for display edges in QT
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include "node.h"

class Node;

class Edge : public QGraphicsItem
{
public:
    Edge(QPointF src, QPointF dst, int lType = 0);

//    void adjust();

    enum { Type = UserType + 2 };
    int type() const { return Type; }

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int linkedType;

    QPointF sourcePoint;
    QPointF destPoint;
};

#endif // EDGE_H
