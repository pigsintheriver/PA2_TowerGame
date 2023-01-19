#ifndef BLOODMINUSITEM_H
#define BLOODMINUSITEM_H
#include "myitem.h"
#include <QTimer>
//表示生物受到的伤害的图标
class Bloodminusitem:public Myitem
{
public:
    Bloodminusitem(int atk,QPointF itempos);
    ~Bloodminusitem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void endshow();

//signals:
//    void icondead(Bloodminusitem* deadicon);
//private:
};

#endif // BLOODMINUSITEM_H
