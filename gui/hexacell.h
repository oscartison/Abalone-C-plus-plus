#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "position.h"
#include "observable.h"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

namespace abalone { namespace view {

class HexaCell : public QGraphicsPolygonItem, public Observable
{
    static const double zValMax; // z-val of selected items
    double zval; // z-val at instanciation
    std::list<Observer *> list_observer_;

protected :

    double rad, dx, dy; // hexagon radius, coordinate (x,y) of center

    bool mouseover, selected, moved; // mouse interaction booleans

public :

    void init();

    abalone::model::Position pos_;

    HexaCell(abalone::model::Position pos, double rad = 100, double dx = 0, double dy = 0, QGraphicsItem * parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);


protected :

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

};

}}

#endif // HEXACELL_H
