#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "gamescene.h"
#include "settingsdialog.h"
#include "ui_settingsdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameScene* gamescene=NULL;//游戏场景
    SettingsDialog* settingsdialog=NULL;//设置窗口
    int w=5,h=5;//宽与高的比例
};
#endif // MAINWINDOW_H
