#ifndef TOWER2_H
#define TOWER2_H
#include "tower.h"
#include<QString>
#include<QTimer>
#include"enemy.h"
#include"mainwindow.h"

class MainWindow;
class QPainter;
class enemy;
class QTimer;
class tower;

class tower2:public tower
{
public:
    tower2(QPoint pos,MainWindow* game,QString path=":/images/image/tower2.jpg");
    tower2();
private slots:
    void shootwarpon();
};

#endif // TOWER2_H
