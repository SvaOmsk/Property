#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QtGui>

class Line : public QGraphicsItem
{
    //Q_OBJECT
public:
    explicit Line(QPointF pos, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void  SetWidth(float value);
    float Width();

private:
    float  mWidth;
    QLineF mLine;


public slots:

};

#endif // LINE_H
