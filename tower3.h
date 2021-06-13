#ifndef TOWER3_H
#define TOWER3_H

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
class tower3:public tower
{
public:
    tower3(QPoint pos,MainWindow* game,QString path=":/images/image/tower3.jpg");
    tower3();
private slots:
    void shootwarpon();
};

#endif // TOWER3_H
