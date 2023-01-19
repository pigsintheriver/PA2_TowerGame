#include "bloodminusitem.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
//TODO:
//血量不同显示的图片不同
Bloodminusitem::Bloodminusitem(int atk,QPointF itempos):Myitem(QPixmap(":/image/bloodminus1"))
{
    this->setPos(itempos);
    type=ICON;
    srand((int)time(0));
    int num=rand()%100;
    this->setPos(mapToParent(num,0));
}

Bloodminusitem::~Bloodminusitem()
{

}

QRectF Bloodminusitem::boundingRect() const
{
    return QRectF(0,0,10,10);

}

void Bloodminusitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect=this->boundingRect().toRect();
    painter->drawPixmap(rect.left(),rect.top(),10,10,this->pixmap());

}

void Bloodminusitem::endshow()
{
    scene()->removeItem(this);

}


