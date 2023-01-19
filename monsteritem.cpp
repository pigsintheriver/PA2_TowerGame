#include "monsteritem.h"
#include <QPainter>
#include <QList>
#include <QGraphicsScene>
vector<Pathgrid> Monsteritem::path_vec(0);//初始化类中的静态数据成员
//Monsteritem::Monsteritem(QPointF originalpos):Creatureitem(QPixmap(":/image/monster1"),originalpos,MONSTER_HP,MONSTER_ATK)
//{
//    type=3;
//}

Monsteritem::Monsteritem(std::pair<int, int> _gridpos):Creatureitem(QPixmap(":/image/monster1"),_gridpos,MONSTER_HP,MONSTER_ATK)
{
    type=MONSTER;
    walk=true;
    pathidx=0;
    this->setPos(_gridpos.first*WDOT,_gridpos.second*HDOT);
}

Monsteritem::~Monsteritem()
{

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
    if(phase==0) return;
//    for(auto item:path_vec){
//        qDebug()<<item.coord<<' '<<item.barrier;
//    }
    timecnt++;
    if(timecnt==2) {
        timecnt=0;
    }
//    int wide_1=WDOT;//怪兽水平方向行走一个单位的路程
//    int height_1=HDOT;//怪兽竖直方向行走一个单位的路程

    if(path_vec[pathidx].barrier) this->walk=false;
    else this->walk=true;
    if(this->walk){
        if(path_vec[pathidx].d==RIGHT) this->setPos(mapToParent(WDOT,0));
        else if(path_vec[pathidx].d==LEFT) this->setPos(mapToParent(-WDOT,0));
        else if(path_vec[pathidx].d==UP) this->setPos(mapToParent(0,-HDOT));
        else if(path_vec[pathidx].d==DOWN) this->setPos(mapToParent(0,HDOT));
        else if(path_vec[pathidx].d==END) emit gameend();
        pathidx++;
    }
    QList<QGraphicsItem*>collideitems=scene()->collidingItems(this);
    if(!collideitems.isEmpty()){
        //如果检测到有碰撞发生,遍历发生碰撞的item
        for(int i=0;i<collideitems.size();i++){
            Myitem* genitem=(Myitem*)collideitems.at(i);
            if(genitem->getgentype()>=0){//判断是生物
                Creatureitem* item=(Creatureitem*)collideitems.at(i);
                if(item->getitemtype()==CLOSETOWER||item->getitemtype()==FARTOWER){
                    //如果发生碰撞的item不是子弹或者怪兽的话则进行攻击
                    this->atk(item);
                }
            }
        }
    }

    Creatureitem::advance(phase);
}

void Monsteritem::setwalkstatus(bool walkstatus)
{
    walk=walkstatus;
}

void Monsteritem::init_pathvec(std::vector<std::pair<int, int> > &_pathvec)
{
    for(int i=0;i<_pathvec.size();i++){
        Pathgrid tmp;
        tmp.coord=_pathvec[i];
        if(i<_pathvec.size()-1){
            //compare coordinate to get direction
            if(_pathvec[i+1].first<_pathvec[i].first)
                tmp.d=LEFT;
            else if(_pathvec[i+1].first>_pathvec[i].first)
                tmp.d=RIGHT;
            else if(_pathvec[i+1].second<_pathvec[i].second)
                tmp.d=UP;
            else if(_pathvec[i+1].second>_pathvec[i].second)
                tmp.d=DOWN;
        }
        else tmp.d=END;
        path_vec.push_back(tmp);
    }

}

void Monsteritem::addpathbarrier(std::pair<int, int> _barrierpos)
{
    for(int i=0;i<path_vec.size();i++){
        if(path_vec[i].coord==_barrierpos){
            path_vec[i].barrier=true;
            break;
        }
    }
}

void Monsteritem::delete_barrier(std::pair<int, int> _barrier)
{
    //清除障碍
    for(int i=0;i<path_vec.size();i++){
        if(path_vec[i].coord==_barrier){
            path_vec[i].barrier=false;
            break;
        }
    }
}
