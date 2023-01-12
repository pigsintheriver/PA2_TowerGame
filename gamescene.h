#ifndef GAMESCENE_H
#define GAMESCENE_H
#define WDOT 100
#define HDOT 100

#define DEBUG
#include <QMainWindow>
#include "mygamescene.h"
#include "mygraphicsview.h"
#include <QGraphicsRectItem>
namespace Ui {
class GameScene;
}

class GameScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr,int _w=5,int _h=5);
    ~GameScene();
    void test();
private slots:
    void back2mw_clicked();
    void gameEND();
//    void setCLT();
//    void setFART();
signals:
    void sendsignal();
private:
    Ui::GameScene *ui;
    mygamescene* scene=NULL;
    MyGraphicsView* gview=NULL;
    int mapw;
    int maph;
    //QMenu* startmenu=NULL;
};

#endif // GAMESCENE_H
