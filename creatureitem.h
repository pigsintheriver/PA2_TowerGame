#ifndef CREATUREITEM_H
#define CREATUREITEM_H
#include <QGraphicsPixmapItem>
#include "myitem.h"
#include "bloodminusitem.h"
#include <utility>
#include <algorithm>
#include <QGraphicsScene>
//#include <QThread>
#define WDOT 100
#define HDOT 100

#define CLOSETOWER 0 //近战塔
#define FARTOWER 1 //远战塔
#define BULLET 2 //子弹
#define MONSTER 3 //怪物

class Creatureitem:public Myitem
{
    Q_OBJECT
public:
    Creatureitem(const QPixmap &pixmap,QPointF originalpos,int _hp,int _attack);
    Creatureitem(const QPixmap &pixmap,pair<int,int> _gridpos=std::make_pair(0,0),int _hp=0,int _attack=0);
    virtual ~Creatureitem();
    int getitemtype();
    void getattack(int enemyATK);
    void atk(Creatureitem* enemy);
    void test(Bloodminusitem* _item);
signals:
    void dead(Creatureitem* deaditem);
public slots:
    void advance(int phase);
protected:
//    QTimer* timer;
    int timecnt=0;//用来计时
    int hp=0;//每种生物的血条
    int attack=0;//每种生物的攻击力

};

#endif // CREATUREITEM_H
