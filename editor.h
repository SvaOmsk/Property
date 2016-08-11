#ifndef EDITOR_H
#define EDITOR_H

#include <QGraphicsView>
#include <QRubberBand>
#include <QtGui>

class Editor : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = 0);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sigSelectedChanged(const QList<QGraphicsItem*> &items);

private:
    QRubberBand mRubber;
    QPoint     mStartPoint;
};

#endif // EDITOR_H
