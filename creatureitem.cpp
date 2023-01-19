#include "creatureitem.h"
#include <QGraphicsItem>
Creatureitem::Creatureitem(const QPixmap &pixmap, std::pair<int, int> _gridpos, int _hp, int _attack):Myitem(pixmap)
{
    gridpos=_gridpos;
    hp=_hp;
    attack=_attack;
    posinscene.setX(gridpos.first*WDOT);
    posinscene.setY(gridpos.second*HDOT);
}

Creatureitem::~Creatureitem()
{

}

int Creatureitem::getitemtype()
{

    return type;
}

void Creatureitem::getattack(int enemyATK)
{
    hp=(hp>enemyATK?hp-enemyATK:0);
    Bloodminusitem* bloodminus=new Bloodminusitem(1,this->pos());
    scene()->addItem(bloodminus);
    QTimer* timer=new QTimer(bloodminus);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,bloodminus,&Bloodminusitem::endshow);
    connect(timer,&QTimer::timeout,[=](){
        delete bloodminus;
    });
    timer->start(500);


}

void Creatureitem::atk(Creatureitem *enemy)
{
    enemy->getattack(attack);
//    Bloodminusitem* tmp=new Bloodminusitem();
    //    QGraphicsItem* minus1=new QGraphicsItem(this);
}

void Creatureitem::test(Bloodminusitem *_item)
{
    scene()->removeItem(_item);
    delete _item;
}

void Creatureitem::advance(int phase)
{
    if(phase==0) return;

    //如果生物的死了则发送dead信号给scene，删除该生物
    if(hp<=0){
        emit dead(this);
    }

}
