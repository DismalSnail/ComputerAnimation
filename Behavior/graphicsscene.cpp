//////////////////////////////////////////////////////////////////////////
// graphicsscene.cpp -- Source file for hard coded QT canvas
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include "graphicsscene.h"

GraphicsScene::GraphicsScene(GraphWidget* graphWiget) :
    graph(graphWiget)
{
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (!this->hasSelection(mouseEvent->scenePos()))
    {
        Node * newNode = new Node(this->graph, InterpPoints);
        newNode->setPos(mouseEvent->scenePos());

        this->graph->AddInterpPoints(newNode);
        this->graph->spline->Interpolate();
        this->graph->spline->Paint();
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

bool GraphicsScene::hasSelection(QPointF mousePos)
{

    for (int i = 0; i < this->graph->spline->interpPoints.size(); ++i) {
        QPointF temp = this->graph->spline->interpPoints.at(i)->pos() - mousePos;
        if (temp.x()*temp.x() + temp.y()*temp.y() < 400)
        {
            return true;
        }
    }

    for (int i = 0; i < this->graph->spline->controlPoints.size(); ++i) {
        QPointF temp = this->graph->spline->controlPoints.at(i)->pos() - mousePos;
        if (temp.x()*temp.x() + temp.y()*temp.y() < 400)
        {
            return true;
        }
    }
    if (this->graph->spline->startPoint != NULL)
    {
        QPointF temp = this->graph->spline->startPoint->pos() - mousePos;
        if (temp.x()*temp.x() + temp.y()*temp.y() < 400)
        {
            return true;
        }
    }
    if (this->graph->spline->endPoint != NULL)
    {
        QPointF temp = this->graph->spline->endPoint->pos() - mousePos;
        if (temp.x()*temp.x() + temp.y()*temp.y() < 400)
        {
            return true;
        }
    }

    return false;
}
