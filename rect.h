#ifndef RECT_H
#define RECT_H

#include <QGraphicsItem>
#include <QtGui>

class Rect : public QGraphicsItem
{
    //Q_OBJECT
public:
    explicit Rect(QPointF pos, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void  SetWidth(float value);
    float Width();

    void  SetStyle(Qt::BrushStyle style);
    Qt::BrushStyle Style();

private:
    float  mWidth;
    QRectF mRect;
    Qt::BrushStyle mStyle;

public slots:

};

#endif // RECT_H
