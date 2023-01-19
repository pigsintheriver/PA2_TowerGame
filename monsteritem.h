#ifndef MONSTERITEM_H
#define MONSTERITEM_H
#include "creatureitem.h"
#include "myitem.h"
#include <vector>
#define MONSTER_HP 5
#define MONSTER_ATK 1

#define DEBUG
using std::vector;

//记录走在路径上的怪兽的方向
enum Direction{
    LEFT,RIGHT,UP,DOWN,END
};

class Pathgrid{
public:
    pair<int,int> coord;//记录路径的坐标信息
    Direction d=RIGHT;
    bool barrier=false;//记录此时此格上是否有近战塔
};

class Monsteritem:public Creatureitem
{
    Q_OBJECT
public:
//    Monsteritem(QPointF originalpos);
    Monsteritem(pair<int,int> _gridpos);
    ~Monsteritem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

    void setwalkstatus(bool walkstatus);//怪物若遇到阻拦则无法继续前进

    static void init_pathvec(vector<pair<int,int>>& _pathvec);
    static void addpathbarrier(pair<int,int> _barrierpos);
    static void delete_barrier(pair<int,int> _barrier);//删除死去的近战塔坐标的函数
    static vector<Pathgrid> path_vec;
signals:
    void gameend();
private:
    bool walk;//该怪兽此时是否能活动
    int pathidx;//该怪兽此时行走到路径第几格
};

#endif // MONSTERITEM_H
