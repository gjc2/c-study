#include "enemy.h"
#include "mainwindow.h"
#include "tower.h"
#include "utility.h"
#include "waypoint.h"

#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QString>
#include <QVector2D>

const QSize enemy::m_fixedsize(22,23);

enemy::enemy(waypoint* startwaypoint,MainWindow* game,QString path):
    QObject(0),
    m_game(game),
    m_pos(startwaypoint->getpos()),
    m_path(path)
{
    m_maxnhp=40;
    m_currenthp=m_maxnhp;
    m_walkingspeed=1;
    m_active=false;
    m_destinationwaypoint=startwaypoint->getnextpoint();
}
enemy::~enemy()
{
    m_attackertowerlist.clear();
    m_destinationwaypoint=NULL;
    m_game=NULL;
}

void enemy::draw(QPainter *painter) const
{
    if(!m_active)
    {
        return ;
    }
    painter->save();
    //画血条
    static const int healthbarwidth=m_fixedsize.width();//设置血条长度
    QPoint healthbarpoint=m_pos+QPoint(-m_fixedsize.width()/2,-m_fixedsize.height());
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthbarbackrect(healthbarpoint,QSize(healthbarwidth,2));//矩阵
    painter->drawRect(healthbarbackrect);//画出血条
    //画当前血条
    painter->setBrush(Qt::green);
    QRect healthbarrect(healthbarpoint,QSize((double)m_currenthp/m_maxnhp*healthbarwidth,2));
    painter->drawRect(healthbarrect);//画出当前血量血条
    //把敌人画出
    QPoint tmp(m_pos.x()-m_fixedsize.width()/2,m_pos.y()-m_fixedsize.height()/2);
    painter->drawPixmap(tmp.x(),tmp.y(),m_path);
    painter->restore();
}
void enemy::move()
{
    if(!m_active)
    {
        return ;
    }
    if(collisionwithcircle(m_pos,1,m_destinationwaypoint->getpos(),1))//如果到达了航点
    {
    if(m_destinationwaypoint->getnextpoint())//如果还存在下一个航点
    {//重新设置敌人的位置和目标航点
        m_pos=m_destinationwaypoint->getpos();
        m_destinationwaypoint=m_destinationwaypoint->getnextpoint();
    }
    else//如果没有下一个航点了，就说明敌人已经到达了基地
    {
        m_game->gethpdamaged();
        m_game->removeenemy(this);
        return ;
    }
    }
    else//如果在航点的路上
    {//采用QVector2d中的两点移动方法
        QPoint targetpoint=m_destinationwaypoint->getpos();
        double movementspeed=m_walkingspeed;
        QVector2D normalized(targetpoint-m_pos);
        normalized.normalize();
        m_pos=m_pos+normalized.toPoint()*movementspeed;
    }
}
void enemy::doactive()
{
    this->m_active=true;
}
QPoint enemy::getpos()
{
    return m_pos;
}
void enemy::getattacked(tower *Tower)
{
    m_attackertowerlist.push_back(Tower);
}
void enemy::getdamaged(int damage)
{
    m_currenthp-=damage;
    if(m_currenthp<=0)
    {
        m_game->awardgold();
        getremoved();
    }
}
void enemy::getremoved()
{
    if(m_attackertowerlist.empty())
    {
        return ;
    }
    else
    {
        foreach(tower* Tower,m_attackertowerlist)
            Tower->targetkilled();
        m_game->removeenemy(this);
    }
}
void enemy::getlostsight(tower *Tower)
{
    m_attackertowerlist.removeOne(Tower);
}
