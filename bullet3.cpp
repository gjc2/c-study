#include "bullet3.h"
#include "bullet2.h"
#include "bullet.h"
#include "tower.h"
#include "mainwindow.h"
#include "utility.h"
#include "enemy.h"
#include <QDebug>
#include <QPoint>
#include <QPainter>
#include <QString>
#include <QPropertyAnimation>//实现动画效果
bullet3::bullet3():
    bullet()
{
    change(":/images/image/bullet2.jpg");
}
bullet3::bullet3(QPoint startpos,QPoint targetpos,int damage,enemy* targetenemy,MainWindow* game,QString path):
    bullet(startpos,targetpos,damage,targetenemy,game,path)
{
     change(":/images/image/bullet3.jpg");
}
void bullet3::move()
{
    int duration=200;//子弹的飞行时间
    QPropertyAnimation* animation=new QPropertyAnimation(this,"m_currentpos");
    animation->setDuration(duration);//设置持续时间
    animation->setStartValue(getstartpos());//设置起始位置
    animation->setEndValue(gettargetpos());//设置目标位置
    connect(animation,SIGNAL(finished()),this,SLOT(hittarget()));//链接信号槽，击中敌人后，子弹动态运动结束
    animation->start();
}
void bullet3::hittarget()
{
    qDebug("666\n");
    if(this->getgame()->getenemylist().indexOf(gettargetenemy())!=-1)
    {
        this->gettargetenemy()->enemy::getdamaged(bullet::getdamage());

    }
    this->getgame()->removebullet(this);
}
