#include "monsteritem.h"
#include <QPainter>
Monsteritem::Monsteritem(QPointF originalpos):Creatureitem(QPixmap(":/image/monster1"),originalpos,MONSTER_HP,MONSTER_ATK)
{
    type=3;
}

Monsteritem::Monsteritem(std::pair<int, int> _gridpos):Creatureitem(QPixmap(":/image/monster1"),_gridpos,MONSTER_HP,MONSTER_ATK)
{
    type=3;
//    this->setTransformOriginPoint(posinscene.rx()+50,posinscene.ry()+50);
    this->setPos(_gridpos.first*WDOT,_gridpos.second*HDOT);

    this->setTransformOriginPoint(mapToScene(50,50));
}

QRectF Monsteritem::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Monsteritem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect rect=this->boundingRect().toRect();
//    qDebug()<<rect;
//    qDebug()<<rect.top()<<rect.left();
    painter->drawPixmap(rect.left()+25,rect.top()+25,50,50,this->pixmap());
}

void Monsteritem::advance(int phase)
{

    //TODO
    if(phase==0) return;
    qDebug()<<this->scenePos();
//    qDebug()<<this->mapToScene(0,100);
//    qDebug()<<this->mapToParent(0,100);
    timecnt++;
    if(timecnt==4) {
        timecnt=0;
        //设置完之后,通过旋转改变了原有坐标系的方向
/*        qDebug()<<this->transformOriginPoint();
        qDebug()<<"setRotation";
        setRotation(90);*/
        this->setPos(mapToParent(WDOT,0));

    }
    if(timecnt%2) this->setPixmap(QPixmap(":/image/monster1_2"));
    else this->setPixmap(QPixmap(":/image/monster1"));

    Creatureitem::advance(phase);
}

void Monsteritem::setwalkstatus(bool walkstatus)
{
    walk=walkstatus;
}
