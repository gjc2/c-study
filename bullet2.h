#ifndef BULLET2_H
#define BULLET2_H

#include<QObject>
#include<QPoint>
#include<QPainter>
#include<QString>
#include<QSize>

#include"enemy.h"
#include"tower.h"
#include"mainwindow.h"

class enemy;
class MainWindow;
class tower;
class bullet;
class bullet2:public bullet
{
public:
    bullet2(QPoint startpos,QPoint targetpos,int damage,enemy* targetenemy,MainWindow* game,QString path=":/images/image/bullet2.jpg");
    bullet2();
    void move();
private slots:
    void hittarget();
};

#endif // BULLET2_H
