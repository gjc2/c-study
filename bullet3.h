#ifndef BULLET3_H
#define BULLET3_H

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
class bullet3:public bullet
{
public:
    bullet3(QPoint startpos,QPoint targetpos,int damage,enemy* targetenemy,MainWindow* game,QString path=":/images/image/bullet3.jpg");
    bullet3();
    void move();
private slots:
    void hittarget();
};

#endif // BULLET3_H
