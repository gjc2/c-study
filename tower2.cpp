#include "tower2.h"
#include "tower.h"
#include "mainwindow.h"
#include "utility.h"
#include<QPoint>
#include<QPainter>
#include<QString>
#include"bullet2.h"
class bullet2;

tower2::tower2():
    tower()
{}

tower2::tower2(QPoint pos,MainWindow* game,QString path):
    tower(pos,game,path)
{
    this->change(100,150,4000);//改变防御塔的属性
    changefire(new QTimer(this));
    connect(getfireratetime(),SIGNAL(timeout()),this,SLOT(shootwarpon()));
}
void tower2::shootwarpon()
{
    bullet2* Bullet=new bullet2(getpos(),getchooseenemy()->getpos(),getdamaged(),getchooseenemy(),getgame());//构造一个子弹开始攻击敌人
    Bullet->move();
    getgame()->addbullet(Bullet);//将子弹添加到mainwindows中
//    QString s = "Jack";
//    qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
//
}


