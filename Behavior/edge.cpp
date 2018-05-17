//////////////////////////////////////////////////////////////////////////
// edge.cpp -- Source file for display edges in QT
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania


#include "edge.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Edge::Edge(QPointF src, QPointF dst, int lType)
{
    setAcceptedMouseButtons(0);
    sourcePoint = src;
    destPoint = dst;

    linkedType = lType;
    this->setZValue(1.0);
}

//void Edge::adjust()
//{
//    QLineF line(sourcePoint, destPoint);
//    qreal length = line.length();

//    prepareGeometryChange();
//}

QRectF Edge::boundingRect() const
{
    qreal penWidth = 1;
    qreal extra = penWidth / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLineF line(sourcePoint, destPoint);
    QColor col = (linkedType == 0) ? Qt::blue : ((linkedType == 1) ? Qt::yellow : Qt::green);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line itself
    painter->setPen(QPen(col, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
}
