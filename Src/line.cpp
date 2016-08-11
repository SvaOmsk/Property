#include "line.h"

Line::Line(QPointF pos, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    mWidth = 3;
    setPos(pos);
    mLine.setP2(QPointF(50,0));
    setFlags(ItemIsSelectable | ItemIsMovable);
}

QRectF Line::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Line::shape() const
{
    QPainterPath path;
    path.moveTo(mLine.p1());
    path.lineTo(mLine.p2());

    QPainterPathStroker stroker;
    stroker.setCapStyle(Qt::RoundCap);
    stroker.setJoinStyle(Qt::RoundJoin);
    stroker.setWidth(mWidth+5);

    return stroker.createStroke(path);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

    if(isSelected())
        painter->setPen(QPen(Qt::red, mWidth));
    else
        painter->setPen(QPen(Qt::green, mWidth));

    painter->drawLine(mLine);
    //painter->drawPath(shape());
    painter->setPen(Qt::yellow);
    painter->drawRect(boundingRect());

    painter->restore();
}

void Line::SetWidth(float value)
{
    if(value < 0) return;
    else
    {
        prepareGeometryChange();
        mWidth = value;
    }
}

float Line::Width()
{
    return mWidth;
}
