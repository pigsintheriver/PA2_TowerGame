#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("猪头大作战");
    this->setFixedSize(800,700);
    this->setWindowIcon(QPixmap(":/image/mwicon"));
    ui->startBtn->move(this->width()*0.5-ui->startBtn->width()*0.5, this->height()*0.5);
    ui->settingsBtn->move(this->width()*0.5-ui->startBtn->width()*0.5, this->height()*0.6);
    QPalette label_pe;
    QFont ft;
    ft.setPointSize(20);
    ui->mwtitle->setPalette(label_pe);
    ui->mwtitle->setFont(ft);
    ui->mwtitle->move(this->width()*0.5-ui->mwtitle->width()*0.5, this->height()*0.2);

    settingsdialog=new SettingsDialog(w,h,this);

    //每点击一次start就生成一个新的游戏场景，同时将新游戏的返回按钮与父场景的show连接
    connect(ui->startBtn,&QPushButton::clicked,[=](){
        gamescene= new GameScene(NULL,w,h);
        connect(gamescene,&GameScene::sendsignal,[=](){
//            qDebug()<<"emit sendsignal";
            this->show();
        });
        QTimer::singleShot(500,this,[=](){
            this->hide();
            gamescene->show();
        });
    });

    connect(ui->settingsBtn,&QPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            //this->hide();

            settingsdialog->exec();
        });
    });
    connect(settingsdialog,&QDialog::accepted,[=](){
        w=settingsdialog->ui->wSPB->value();
        h=settingsdialog->ui->hSPB->value();
    });
    connect(settingsdialog,&QDialog::rejected,[=](){
        settingsdialog->ui->wSPB->setValue(w);
        settingsdialog->ui->hSPB->setValue(h);
    });
//    qDebug()<<"test";
}

MainWindow::~MainWindow()
{
//    qDebug()<<"recall destructor";
    delete ui;
}

