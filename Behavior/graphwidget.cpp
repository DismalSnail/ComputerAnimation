//////////////////////////////////////////////////////////////////////////
// graphwidget.cpp -- Source file for QT graph widgets for display the curve.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include "graphwidget.h"
#include "edge.h"
#include "node.h"

#include <QtGui>
#include <math.h>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    GraphicsScene *scene = new GraphicsScene(this);

    actionShow_Control_Points = new QAction(this);
    actionShow_Control_Points->setObjectName(QString::fromUtf8("actionShow_Control_Points"));
    actionShow_Control_Points->setCheckable(true);
    actionShow_Control_Points->setChecked(false);

    actionClear_Scene = new QAction(this);
    actionClear_Scene->setObjectName(QString::fromUtf8("actionClear_Scene"));
    toolBar = new QToolBar(this);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));

    actionClear_Scene->setText(QApplication::translate("GraphWidget", "Clear Scene", 0, QApplication::UnicodeUTF8));
    actionShow_Control_Points->setText(QApplication::translate("GraphWidget", "Show Control Points", 0, QApplication::UnicodeUTF8));
    actionClear_Scene->setToolTip("Click to clear the curve editor scene.");
    actionClear_Scene->setStatusTip("Click to clear the curve editor scene.");
    actionShow_Control_Points->setToolTip("Enable to show the control points, disable to hide them.");
    actionShow_Control_Points->setStatusTip("Enable to show the control points, disable to hide them.");

    methodChooseComboBox = new QComboBox(this);
    methodChooseComboBox->setObjectName(QString::fromUtf8("methodChooseComboBox"));
    methodChooseComboBox->addItem("Bezier Berstein");
    methodChooseComboBox->addItem("Bezier de Casteljau");
    methodChooseComboBox->addItem("Bezier Matrix");
    methodChooseComboBox->addItem("BSpline");
    methodChooseComboBox->addItem("Hermite Spline (clamped)");
    methodChooseComboBox->addItem("Hermite Spline (natural)");

    toolBar->addAction(actionClear_Scene);
    toolBar->addSeparator();
    toolBar->addAction(actionShow_Control_Points);
    toolBar->addSeparator();
    toolBar->addWidget(methodChooseComboBox);
    toolBar->addSeparator();
    toolBar->setAutoFillBackground(true);

    QMetaObject::connectSlotsByName(this);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-534, -220, 1068, 440);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setMinimumSize(400, 400);
    this->spline = new Spline(this);

    this->spline->interpStyle = BezierBerstein;
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space:
        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)0.5, -event->delta() / 480.0));
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersect(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 1 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void GraphWidget::shuffle()
{
    foreach (QGraphicsItem *item, this->spline->interpPoints) {
        if (qgraphicsitem_cast<Node *>(item))
            item->setPos(-500 + qrand() % 1000, -200 + qrand() % 400);
    }
}

void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void GraphWidget::AddInterpPoints(Node * newNode)
{
    this->spline->AddPoint(newNode);
}

void GraphWidget::on_actionClear_Scene_triggered()
{
    //graphwidget->scene()->clear();
    spline->Clear();
}

void GraphWidget::on_actionShow_Control_Points_triggered(bool checked)
{
    spline->showControlPoints = checked;
    spline->Interpolate();
    spline->Paint();
}

void GraphWidget::on_methodChooseComboBox_currentIndexChanged(int index)
{
    //qDebug() << "index = " << index;
    switch(index)
    {
    case 0:
        this->spline->showPseudoPoints = true;
        this->spline->interpStyle = BezierBerstein;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    case 1:
        this->spline->showPseudoPoints = true;
        this->spline->interpStyle = BezierDeCasteljau;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    case 2:
        this->spline->showPseudoPoints = true;
        this->spline->interpStyle = BezierMatrix;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    case 3:
        this->spline->showPseudoPoints = false;
        this->spline->interpStyle = BSpline;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    case 4:
        this->spline->showPseudoPoints = true;
        this->spline->interpStyle = HermiteClamped;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    case 5:
        this->spline->showPseudoPoints = false;
        this->spline->interpStyle = HermiteNatural;
        this->spline->Interpolate();
        this->spline->Paint();
        break;
    default:
        break;
    }
    this->repaint();
}

