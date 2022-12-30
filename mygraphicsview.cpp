#include "mygraphicsview.h"
#include <QPointF>
#include <QMouseEvent>
MyGraphicsView::MyGraphicsView(QWidget* parent,mygamescene* _myscene):QGraphicsView(parent)
{
    myscene=_myscene;
    this->setScene(myscene);
}

void MyGraphicsView::setCLT()
{
    mouseeventstatus=closetower;
}

void MyGraphicsView::setFART()
{
    mouseeventstatus=fartower;
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event)
{
    if(mouseeventstatus==closetower){
        QPointF scenepos=mapToScene(event->pos().x(),event->pos().y());
        myscene->addcltitem(scenepos);
    }
    else if(mouseeventstatus==fartower){

    }

}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    mouseeventstatus=none;
}
