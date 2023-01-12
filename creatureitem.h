#ifndef CREATUREITEM_H
#define CREATUREITEM_H
#include <QGraphicsPixmapItem>
#include <utility>
#include <algorithm>

#define WDOT 100
#define HDOT 100

#define CLOSETOWER 0
#define FARTOWER 1
#define BULLET 2
#define MONSTER 3
using std::pair;
class Creatureitem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Creatureitem(const QPixmap &pixmap,QPointF originalpos,int _hp,int _attack);
    Creatureitem(const QPixmap &pixmap,pair<int,int> _gridpos,int _hp,int _attack);
    virtual ~Creatureitem();
    int getitemtype();
    void getattack(int enemyATK);
    void atk(Creatureitem* enemy);
signals:
    void dead(Creatureitem* deaditem);
public slots:
    void advance(int phase);
protected:
    QPointF posinscene;//物种此时的坐标,左上角坐标
    pair<int,int> gridpos;//物种在地图上哪一格位置
    int type=-1;//0:clt  1:fart  2:bullet  3:monster
    int timecnt=0;//用来计时
    int hp=0;//每种生物的血条
    int attack=0;//每种生物的攻击力

};

#endif // CREATUREITEM_H
