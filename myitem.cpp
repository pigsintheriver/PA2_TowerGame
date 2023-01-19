#include "myitem.h"

Myitem::Myitem(const QPixmap &pixmap):QGraphicsPixmapItem(pixmap)
{

}

int Myitem::getgentype()
{
    return type;
}
