#include "tower.h"
#include "mainwindow.h"
#include "utility.h"
#include<QPoint>
#include<QPainter>
#include<QString>

const QSize tower::m_fixedsize(35,35);
tower::tower()
{}

tower::tower(QPoint pos,MainWindow* game,QString path):
    m_attacking(false),
    m_damage(10),
    m_firerate(1000),
    m_chooseenemy(NULL),
    m_game(game),
    m_path(path),
    m_pos(pos),
    m_attackrange(75)


{
    m_fireratetime=new QTimer(this);
    connect(m_fireratetime,SIGNAL(timeout()),this,SLOT(shootwarpon()));
}
tower::~tower()
{
    delete m_fireratetime;
    m_fireratetime=NULL;
    m_chooseenemy=NULL;
    m_game=NULL;
    delete m_chooseenemy;
}

void tower::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::green);
    painter->drawEllipse(m_pos,m_attackrange,m_attackrange);
    painter->drawPixmap(m_pos.x()-m_fixedsize.width()/2,m_pos.y()-m_fixedsize.height()/2,m_path);
    painter->restore();
}
void tower::chooseenemyfromattack(enemy *Enemy)
{
    m_chooseenemy=Enemy;
    attackenemy();
    m_chooseenemy->getattacked(this);//该敌人收到防御塔的攻击
}
void tower::attackenemy()
{
    m_fireratetime->start(m_firerate);//开始攻击
}
void tower::shootwarpon()
{
    bullet* Bullet=new bullet(m_pos,m_chooseenemy->getpos(),m_damage,m_chooseenemy,m_game);//构造一个子弹开始攻击敌人
    Bullet->move();
    m_game->addbullet(Bullet);//将子弹添加到mainwindows中
//    QString s = "Jack";
//    qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
//
}
void tower::targetkilled()
{
    if(m_chooseenemy)
    {
        m_chooseenemy=NULL;
    }
    m_fireratetime->stop();//敌人死亡，停止开火
}
void tower::lostsightofenemy()
{
    m_chooseenemy->getlostsight(this);
    if(m_chooseenemy)
    {
        m_chooseenemy=NULL;
    }
    m_fireratetime->stop();
}
void tower::checkenemyinrange()
{
    if(m_chooseenemy)//如果有了攻击的敌人
    {
        QVector2D normalized(m_chooseenemy->getpos()-m_pos);
        normalized.normalize();
        if(!collisionwithcircle(m_pos,m_attackrange,m_chooseenemy->getpos(),1))
        {
            lostsightofenemy();
        }
    }
    else//如果没有攻击的敌人，就遍历enemylist，找到在攻击范围内的敌人
    {
        QList<enemy* >enemylist=m_game->getenemylist();
        foreach(enemy* Enemy,enemylist)
            if(collisionwithcircle(m_pos,m_attackrange,Enemy->getpos(),1))
            {
                chooseenemyfromattack(Enemy);
                break;
            }
    }
}
enemy* tower::getattackedenemy()
{
    return m_chooseenemy;
}
void tower::change(int damage, int attackrange, int firerate)
{
    m_damage=damage;
    m_attackrange=attackrange;
    m_firerate=firerate;
}
QPoint tower::getpos()
{
    return m_pos;
}
enemy* tower::getchooseenemy()
{
    return m_chooseenemy;
}
int tower::getdamaged()
{
    return m_damage;
}
MainWindow* tower::getgame()
{
    return m_game;
}
QTimer* tower::getfireratetime()
{
    return m_fireratetime;
}
void tower::changefire(QTimer *p)
{
    m_fireratetime=p;
}
enemy* tower::getnextenemy()//没有用的多余函数，要想攻击两个其实不用再开函数
{
    QList<enemy* >enemylist=m_game->getenemylist();
    foreach(enemy* Enemy,enemylist)
        if(collisionwithcircle(m_pos,m_attackrange,Enemy->getpos(),1)&& Enemy!=m_chooseenemy)
        {
            return Enemy;
        }
    return NULL;
}
int tower::getattackrange()
{
    return m_attackrange;
}
void tower::changepath(QString path)
{
    m_path=path;
}
void tower::levelchange()
{
    m_level++;
}
int tower::getlevel()
{
    return m_level;
}
void tower::getremoved()
{
    if(getattackedenemy())
    {
        lostsightofenemy();
    }
    m_game->removetower(this);
}
int tower::getfirerate()
{
    return m_firerate;
}
