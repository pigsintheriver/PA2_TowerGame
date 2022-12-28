#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>
#include "closetoweritem.h"
#include "mygamescene.h"
enum Status{//mouse click to create some type of tower
    none,
    closetower,
    fartower
};

class MyGraphicsView:public QGraphicsView
{
public:
    MyGraphicsView(QWidget* parent=NULL,mygamescene* myscene=NULL);
    void setCLT();
    void setFART();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    Status mouseeventstatus=none;
    mygamescene* myscene=NULL;
};

#endif // MYGRAPHICSVIEW_H
