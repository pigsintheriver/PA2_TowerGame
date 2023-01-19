#include "closetoweritem.h"
#include <QPainter>
#include <QDebug>
//CloseToweritem::CloseToweritem(QPointF originalpos):Creatureitem(QPixmap(":/image/clt_notinfight"),originalpos,CLOSETOWER_HP,CLOSETOWER_ATK)
//{
//    posinscene=originalpos;
//    type=0;
//}

CloseToweritem::CloseToweritem(std::pair<int, int> _gridpos):Creatureitem(QPixmap(":/image/clt_notinfight"),_gridpos,CLOSETOWER_HP,CLOSETOWER_ATK)
{
    type=0;
    this->setPos(_gridpos.first*WDOT,_gridpos.second*HDOT);

}

CloseToweritem::~CloseToweritem()
{

}

QRectF CloseToweritem::boundingRect() const
{

    return QRectF(0,0,100,100);
}

void CloseToweritem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect=this->boundingRect().toRect();
    painter->drawPixmap(rect.left()+25,rect.top()+25,50,50,this->pixmap());
}

void CloseToweritem::advance(int phase)
{
    if(phase==0){
        return;
    }
    timecnt++;
    if(timecnt==10){
        timecnt=0;
    }

    //近战塔死亡时
    if(hp<=0){
        Monsteritem::delete_barrier(gridpos);
        emit dead(this);
    }
}
