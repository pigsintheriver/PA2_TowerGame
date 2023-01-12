#include "creatureitem.h"

Creatureitem::Creatureitem(const QPixmap &pixmap, QPointF originalpos, int _hp, int _attack):QGraphicsPixmapItem(pixmap)
{
    posinscene=originalpos;
    gridpos.first=int(posinscene.x()/WDOT);
    gridpos.second=int(posinscene.y()/HDOT);
    hp=_hp;
    attack=_attack;
}

Creatureitem::Creatureitem(const QPixmap &pixmap, std::pair<int, int> _gridpos, int _hp, int _attack):QGraphicsPixmapItem(pixmap)
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
    qDebug()<<"be attacked";
}

void Creatureitem::atk(Creatureitem *enemy)
{
    enemy->getattack(attack);
}

void Creatureitem::advance(int phase)
{
    if(phase==0) return;

    //如果生物的死了则发送dead信号给scene，删除该生物
    if(hp<=0){
        emit dead(this);
    }
}
