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

const QSize bullet::m_fixedsize(8,8);
bullet::bullet()
{

}
bullet::bullet(QPoint startpos,QPoint targetpos,int damage,enemy* targetenemy,MainWindow* game,QString path):
    m_startpos(startpos),
    m_targetpos(targetpos),
    m_currentpos(startpos),
    m_damage(damage),
    m_path(path),
    m_targetenemy(targetenemy),
    m_game(game)
{

}
QPoint bullet::getcurrentpos()
{
    return m_currentpos;
}
void bullet::setcurrentpos(QPoint pos)
{
    m_currentpos=pos;
}
void bullet::move()
{
    int duration=100;//子弹的飞行时间
    QPropertyAnimation* animation=new QPropertyAnimation(this,"m_currentpos");
    animation->setDuration(duration);//设置持续时间
    animation->setStartValue(m_startpos);//设置起始位置
    animation->setEndValue(m_targetpos);//设置目标位置
    connect(animation,SIGNAL(finished()),this,SLOT(hittarget()));//链接信号槽，击中敌人后，子弹动态运动结束
    animation->start();
}
void bullet::hittarget()
{
//    QString s = "Jack";
//    qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
    if(m_game->getenemylist().indexOf(m_targetenemy)!=-1)//如果mainwindows的敌人列表中有子弹击中的这个敌人，该敌人受到相应的伤害
    {
        m_targetenemy->getdamaged(m_damage);
        QString s = "Jack";
        qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
    }
    m_game->removebullet(this);//子弹击中敌人后移除
}
void bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(m_currentpos,m_path);
}
QPoint bullet::getstartpos()
{
    return m_startpos;
}
QPoint bullet::gettargetpos()
{
    return m_targetpos;
}
MainWindow* bullet::getgame()
{
    return m_game;
}
enemy* bullet::gettargetenemy()
{
    return m_targetenemy;
}
int bullet::getdamage()
{
    return m_damage;
}
void bullet::change(QString path)
{
    m_path=path;
}
