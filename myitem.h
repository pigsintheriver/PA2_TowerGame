#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsPixmapItem>
#include <utility>
#include <QObject>
#define ICON -1 //各类图标

using std::pair;
class Myitem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
//    Myitem();
    Myitem(const QPixmap &pixmap);
    int getgentype();
protected:
    int type;//item的类型
    QPointF posinscene;//物种此时的坐标,左上角坐标
    pair<int,int> gridpos;//物种在地图上哪一格位置
};

#endif // MYITEM_H
