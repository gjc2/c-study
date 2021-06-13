#include "tower3.h"
#include "tower2.h"
#include "tower.h"
#include "mainwindow.h"
#include "utility.h"
#include<QPoint>
#include<QPainter>
#include<QString>
#include"bullet2.h"
#include"bullet3.h"
class bullet3;
class bullet;
tower3::tower3():
    tower()
{

}
tower3::tower3(QPoint pos,MainWindow* game,QString path):
    tower(pos,game,path)
{
    this->change(20,200,500);//改变防御塔的属性
    changefire(new QTimer(this));
    connect(getfireratetime(),SIGNAL(timeout()),this,SLOT(shootwarpon()));
//    connect(getfireratetime(),SIGNAL(timeout()),this,SLOT(shootwarpon()));
}
void tower3::shootwarpon()
{
    //将子弹添加到mainwindows中
    QList<enemy* >enemylist=getgame()->getenemylist();
    bullet3* Bullet[1000];
    int i=0;
    foreach(enemy* Enemy,enemylist)
        if(collisionwithcircle(getpos(),getattackrange(),Enemy->getpos(),1))
        {
                Bullet[i]=new bullet3(getpos(),Enemy->getpos(),getdamaged(),Enemy,getgame());//构造一个子弹开始攻击敌人
                Bullet[i]->move();
                getgame()->addbullet(Bullet[i]);
                i++;
        }
//现在改成打全部了
//这里是实现了防御塔可以同时攻击两个敌人的功能，其实这里写的麻烦了，我为了实现这个功能，又创建了一个敌人对象和获取第二个敌人的函数
//其实我们可以在这里直接遍历敌人的链表，这样我们想同时攻击多少个敌人都是可以的

//    QString s = "Jack";
//    qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
//
}
