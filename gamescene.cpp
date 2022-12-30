#include "gamescene.h"
#include "ui_gamescene.h"
#include <QTimer>
GameScene::GameScene(QWidget *parent,int _w,int _h) :
    QMainWindow(parent),
    ui(new Ui::GameScene),
    mapw(_w),maph(_h)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    //this->setFixedSize(800,700);
    this->setWindowIcon(QPixmap(":/image/mwicon"));
    this->setWindowTitle("猪头大作战");
    QMenu* startmenu=ui->menubar->addMenu("开始");
    QAction* back2mw=startmenu->addAction("返回开始界面");
    QAction* outputmap=startmenu->addAction("导出地图");
    connect(back2mw,&QAction::triggered,this,&GameScene::back2mw_clicked);
    int startx=ui->cltBtn->width();
    this->setFixedSize(startx+mapw*WDOT+19,maph*HDOT+43);
    scene=new mygamescene(mapw,maph,this);
    scene->setSceneRect(QRect(0,0,mapw*WDOT,maph*HDOT));
    gview=new MyGraphicsView(this,scene);

    gview->setGeometry(startx,21,mapw*WDOT+2,maph*HDOT+2);
    gview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gview->show();
    connect(ui->cltBtn,&QPushButton::clicked,gview,&MyGraphicsView::setCLT);
    connect(ui->fartBtn,&QPushButton::clicked,gview,&MyGraphicsView::setFART);

    //启动计时器，100ms触发一次advance函数
    QTimer* timer=new QTimer(gview);
    connect(timer,&QTimer::timeout,scene,&mygamescene::myadvance);
    timer->start(1000);
#ifdef DEBUG
    scene->creat_a_monster();
#endif
#ifndef DEBUG
    QTimer* timer_creatmonster=new QTimer(gview);
    connect(timer_creatmonster,&QTimer::timeout,scene,&mygamescene::creat_a_monster);
    timer_creatmonster->start(3000);
#endif
}

GameScene::~GameScene()
{
    delete ui;
}


void GameScene::back2mw_clicked()
{
    emit sendsignal();
    this->close();
}


