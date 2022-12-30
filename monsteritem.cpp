#include "monsteritem.h"
#include <QPainter>

vector<Pathgrid> Monsteritem::path_vec(0);//初始化类中的静态数据成员
Monsteritem::Monsteritem(QPointF originalpos):Creatureitem(QPixmap(":/image/monster1"),originalpos,MONSTER_HP,MONSTER_ATK)
{
    type=3;
}

Monsteritem::Monsteritem(std::pair<int, int> _gridpos):Creatureitem(QPixmap(":/image/monster1"),_gridpos,MONSTER_HP,MONSTER_ATK)
{
    type=3;
    walk=true;
    pathidx=0;
    this->setPos(_gridpos.first*WDOT,_gridpos.second*HDOT);
//    this->setTransformOriginPoint(mapToScene(50,50));
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
    timecnt++;
    if(timecnt==2) {
        timecnt=0;
    }
    if(path_vec[pathidx].d==RIGHT) this->setPos(mapToParent(WDOT,0));
    else if(path_vec[pathidx].d==LEFT) this->setPos(mapToParent(-WDOT,0));
    else if(path_vec[pathidx].d==UP) this->setPos(mapToParent(0,-HDOT));
    else if(path_vec[pathidx].d==DOWN) this->setPos(mapToParent(0,HDOT));
    else if(path_vec[pathidx].d==END) emit gameend();
    pathidx++;
    if(timecnt%2) this->setPixmap(QPixmap(":/image/monster1_2"));
    else this->setPixmap(QPixmap(":/image/monster1"));

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

#ifdef DEBUG
    for(auto item:path_vec)
        qDebug()<<item.coord<<item.d<<item.barrier;
#endif
}

void Monsteritem::addpathbarrier(std::pair<int, int> _barrierpos)
{
    //设置相应位置的障碍
    for(auto pathgrid:path_vec){
        if(pathgrid.coord==_barrierpos){
            pathgrid.barrier=true;
            break;
        }
    }
}

void Monsteritem::delete_barrier(std::pair<int, int> _barrier)
{
    //清除障碍
    for(auto pathgrid:path_vec){
        if(pathgrid.coord==_barrier){
            pathgrid.barrier=false;
            break;
        }
    }
}
