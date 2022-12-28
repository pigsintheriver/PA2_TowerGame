#ifndef MONSTERITEM_H
#define MONSTERITEM_H
#include "creatureitem.h"
#include <vector>
#define MONSTER_HP 5
#define MONSTER_ATK 1
using std::vector;
class Monsteritem:public Creatureitem
{
    Q_OBJECT
public:
    Monsteritem(QPointF originalpos);
    Monsteritem(pair<int,int> _gridpos);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

    void setwalkstatus(bool walkstatus);//怪物若遇到阻拦则无法继续前进
    //int pathidx=0;//记录怪物此时走到了路径的第几格
    static vector<pair<int,int>> path_barrier;//怪兽类中的静态变量，存储整个道路上的种有近战植物而无法前进的道路
private:
    bool walk=true;//该怪兽此时是否能活动

};

#endif // MONSTERITEM_H
