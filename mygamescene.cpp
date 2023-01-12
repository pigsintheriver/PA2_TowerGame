#include "mygamescene.h"
#include <QPen>
#include <QPainter>
#include <QDebug>
#define WDOT 100
#define HDOT 100

mygamescene::mygamescene(int w,int h,QObject *parent)
    : QGraphicsScene(parent)
{
    scenew=w;
    sceneh=h;
    getrandpath();
    for(int i=0;i<w;i++){
        grids.push_back(vector<Grid*>());
        for(int j=0;j<h;j++){
            Grid* tmp=new Grid();
            grids[i].push_back(tmp);
        }
    }

}

mygamescene::~mygamescene()
{
    for(int i=0;i<scenew;i++)
        for(int j=0;j<sceneh;j++)
            delete grids[i][j];
}

mygamescene::mygamescene(QObject *parent):QGraphicsScene(parent)
{

}

void mygamescene::drawBackground(QPainter *painter, const QRectF &rect){
    //draw all grid in black
    painter->setPen(QPen(Qt::black));
    for(int i=0;i<scenew;i++)
        for(int j=0;j<=sceneh;j++)
            painter->drawRect(i*WDOT,j*HDOT,WDOT,HDOT);

    //draw path grid:start is blue;end is red;middle is brown
    painter->setPen(QPen(Qt::green));
    for(int m=1;m<path.size()-1;m++){
        painter->drawRect(path[m].first*WDOT,path[m].second*HDOT,WDOT,HDOT);
    }
    painter->setPen(QPen(Qt::blue));
    painter->drawRect(path.begin()->first*WDOT,path.begin()->second*HDOT,WDOT,HDOT);
    painter->setPen(QPen(Qt::red));
    painter->drawRect(path[path.size()-1].first*WDOT,path[path.size()-1].second*HDOT,WDOT,HDOT);
//    qDebug()<<path[path.size()-1].first<<path[path.size()-1].second;

}

void mygamescene::addcltitem(QPointF scenepos)
{
    pair<int,int> mappos(int(scenepos.x()/100),int(scenepos.y()/100));
    //近战塔只能在路径上种植且一个格子内部只能种一个，路径首尾不能种
    if(grids[mappos.first][mappos.second]->cltcnt==0&&std::find(path.begin(),path.end(),make_pair(mappos.first,mappos.second))!=path.end()&&mappos!=path[0]&&mappos!=path[path.size()-1]){
        CloseToweritem* newclt=new CloseToweritem(mappos);
        this->addItem(newclt);
        grids[mappos.first][mappos.second]->cltcnt++;
        connect(newclt,&Creatureitem::dead,this,&mygamescene::delete_item);//将近战塔的死亡信号与清除函数绑定
        Monsteritem::addpathbarrier(mappos);//将种有植物的路径方格坐标添加至path_barrier
    }
}

void mygamescene::addfartitem(QPointF scenepos)
{

}

void mygamescene::creat_a_monster()
{
    Monsteritem* newmst=new Monsteritem(path[0]);
    this->addItem(newmst);
    connect(newmst,&Creatureitem::dead,this,&mygamescene::delete_item);
    connect(newmst,&Monsteritem::gameend,this,&mygamescene::gameended);
}

void mygamescene::delete_item(Creatureitem *_item)
{
    this->removeItem(_item);
    delete _item;
}


void mygamescene::myadvance()
{

    QGraphicsScene::advance();
}

void mygamescene::getrandpath()
{
    path.push_back(std::make_pair(0,1));
    path.push_back(std::make_pair(1,1));
    path.push_back(std::make_pair(2,1));
    path.push_back(std::make_pair(3,1));
    path.push_back(std::make_pair(3,2));
    path.push_back(std::make_pair(3,3));
    path.push_back(std::make_pair(3,4));

//    Monsteritem::pathgrid_vec=path;//将路径信息输入到怪兽类中记录路径的数组
    Monsteritem::init_pathvec(path);
}

