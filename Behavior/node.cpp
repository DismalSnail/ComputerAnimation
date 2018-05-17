//////////////////////////////////////////////////////////////////////////
// node.cpp -- Source file for display the nodes in QT canvas.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include "node.h"

Node::Node(GraphWidget *graphWidget, NodeType type)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(0.0);
    nodeType = type;

    switch(nodeType)
    {
    case InterpPoints:
        this->setEnabled(true);
        this->setVisible(true);
        setZValue(1.0);
        break;
    case PseudoPoints:
        this->setEnabled(true);
        this->setVisible(true);
        setZValue(0.5);
        break;
    case ControlPoints:
        this->setEnabled(false);
        this->setVisible(true);
        break;
    case CurvePoints:
        this->setEnabled(false);
        this->setVisible(false);
        break;
    default:
        this->setEnabled(false);
        this->setVisible(false);
        break;
    }
}

QRectF Node::boundingRect() const
{
    if (this->isVisible())
    {
        qreal adjust = 2;
        return QRectF( -10 - adjust, -10 - adjust,
                       23 + adjust, 23 + adjust);
    }
    else
        return QRectF(0, 0, 0, 0);
}

QPainterPath Node::shape() const
{
    QPainterPath path;

    path.addEllipse(-10, -10, 20, 20);

    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);
    QColor color;
    QColor colorDark;

    switch(nodeType)
    {
    case InterpPoints:
        color = QColor(Qt::blue);
        colorDark = QColor(Qt::darkBlue);
        break;
    case PseudoPoints:
        color = QColor(Qt::green);
        colorDark = QColor(Qt::darkGreen);
        break;
    case ControlPoints:
        color = QColor(Qt::yellow);
        colorDark = QColor(Qt::darkYellow);
        break;
    default:
        color = QColor(Qt::gray);
        colorDark = QColor(Qt::darkGray);
        break;
    }

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, color.light(120));
        gradient.setColorAt(0, colorDark.light(120));
    } else {
        gradient.setColorAt(0, color);
        gradient.setColorAt(1, colorDark);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    //qDebug() << event->scenePos();
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        if (this->nodeType == PseudoPoints)
        {
            graph->spline->PaintPseudeLines();
        }
        else if (this->nodeType == InterpPoints)
        {
            graph->spline->Interpolate();
            graph->spline->Paint();
        }
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

vec3 Node::getPosition()
{
    return vec3(this->x(), this->y(), 0.0);
}

void Node::setPosition(vec3 pos)
{
    this->setPos(pos[0], pos[1]);
}
