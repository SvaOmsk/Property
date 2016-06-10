#include "editor.h"
#include "line.h"
#include "rect.h"

Editor::Editor(QWidget *parent) : QGraphicsView(parent), mRubber(QRubberBand::Rectangle,this)
{
    setScene(new QGraphicsScene(0,0,1000,600,this));
    setBackgroundBrush(Qt::black);
    setViewportUpdateMode(FullViewportUpdate);
    setMouseTracking(true);
}

void Editor::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsView::drawBackground(painter, rect);
    painter->setPen(Qt::cyan);
    painter->drawRect(sceneRect());
}

void Editor::mousePressEvent(QMouseEvent *event)
{
    // левая кнопка - выделение объектов
    if(event->button() == Qt::LeftButton)
    {
        QGraphicsItem *gi = scene()->itemAt(mapToScene(event->pos()));
        //если попали по пустому месту, снимаем выделение со всех
        if(!gi)
        {
            foreach (QGraphicsItem *item, scene()->selectedItems())
            {
                item->setSelected(false);
            }
            mStartPoint = mapFromParent(event->pos());
            mRubber.setGeometry(QRect(mStartPoint, QPoint(0, 0)));
            mRubber.show();
        }
        //если попали по элементу - инвертируем его выделение
        else
        {
            gi->setSelected(!gi->isSelected());
        }
    }

    // средняя кнопка - добавление на сцену объекта
    else if(event->button() == Qt::MidButton)
    {
        scene()->addItem(new Rect(mapToScene(event->pos())));
    }

    // правая кнопка - добавление на сцену примитива
    else if(event->button() == Qt::RightButton)
    {
        scene()->addItem(new Line(mapToScene(event->pos())));
    }
}

void Editor::mouseMoveEvent(QMouseEvent *event)
{
    if(mRubber.isVisible())
    {
        mRubber.setGeometry(QRect(mStartPoint, event->pos()).normalized());
    }
}

void Editor::mouseReleaseEvent(QMouseEvent *event)
{
    if(mRubber.isVisible())
    {
        foreach (QGraphicsItem *item, scene()->items(mapToScene(QRect(mStartPoint, event->pos()).normalized())))
        {
            item->setSelected(true);
        }
        mRubber.hide();
    }
}
