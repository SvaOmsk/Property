#include "rect.h"

Rect::Rect(QPointF pos, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setPos(pos);
    mWidth = 5;
    mRect.setCoords(-20,-20,20,20);
    mStyle = Qt::SolidPattern;
    setFlags(ItemIsSelectable | ItemIsMovable);
}

QRectF Rect::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Rect::shape() const
{
    QPainterPath path;
    path.addRect(mRect);

    return path;
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

    if(isSelected())
    {
        painter->setPen(QPen(Qt::red, mWidth));
        painter->setBrush(QBrush(Qt::darkRed, mStyle));
    }
    else
    {
        painter->setPen(QPen(Qt::green, mWidth));
        painter->setBrush(QBrush(Qt::darkGreen, mStyle));
    }

    painter->drawRect(mRect);
    //painter->drawPath(shape());
    painter->setPen(Qt::yellow);
    painter->drawRect(boundingRect());

    painter->restore();
}

void Rect::SetWidth(float value)
{
    if(value < 0) return;
    else
    {
        prepareGeometryChange();
        mWidth = value;
    }
}

float Rect::Width()
{
    return mWidth;
}

void Rect::SetStyle(Qt::BrushStyle style)
{
    prepareGeometryChange();
    mStyle = style;
}

Qt::BrushStyle Rect::Style()
{
    return mStyle;
}
