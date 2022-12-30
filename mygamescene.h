#ifndef MYGAMESCENE_H
#define MYGAMESCENE_H
//#define DEBUG

#include <QObject>
#include <QGraphicsScene>
#include <vector>
#include<utility>
#include<algorithm>
#include "monsteritem.h"
#include "closetoweritem.h"
using namespace std;
class Grid{
public:
    int cltcnt=0;
    int fartcnt=0;
    int mstcnt=0;
};
class mygamescene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit mygamescene(int w,int h,QObject *parent = nullptr);
    ~mygamescene();
    mygamescene(QObject *parent = nullptr);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void addcltitem(QPointF scenepos);
    void addfartitem(QPointF scenepos);
public slots:
    void creat_a_monster();
    void myadvance();

private:
    void getrandpath();//给定地图的长宽之后随机生成路径的函数  TODO
    int scenew;
    int sceneh;
    vector<pair<int,int>> path;
    vector<vector<Grid*>> grids;

};

#endif // MYGAMESCENE_H
