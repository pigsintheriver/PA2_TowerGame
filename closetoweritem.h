#ifndef CLOSETOWERITEM_H
#define CLOSETOWERITEM_H
//#include <QGraphicsPixmapItem>
#include "creatureitem.h"
#include "monsteritem.h"
#define CLOSETOWER_HP 5
#define CLOSETOWER_ATK 1
class CloseToweritem:public Creatureitem
{
    Q_OBJECT
public:
    CloseToweritem(QPointF originalpos);
    CloseToweritem(pair<int,int> _gridpos);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void advance(int phase);

};

#endif // CLOSETOWERITEM_H
