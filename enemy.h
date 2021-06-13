#ifndef ENEMY_H
#define ENEMY_H

#include<QObject>
#include<QPoint>
#include<QString>
#include<QPainter>
#include<QSize>

#include"waypoint.h"
#include"mainwindow.h"
#include"tower.h"
class MainWindow;
class tower;
class QPainter;
class waypoint;

class enemy:public QObject
{
    Q_OBJECT
public:
    enemy(waypoint* startpoint,MainWindow* game,QString path=":/images/image/monster1.jpg");
    ~enemy();
    void draw(QPainter* painter) const;
    void move();//敌人的移动
    QPoint getpos();//得到敌人的当前位置

    void getattacked(tower* Tower);//被tower攻击
    void getdamaged(int damage);//敌人受到伤害
    void getremoved();//敌人死亡，被移除
    void getlostsight(tower* Tower);//敌人脱离tower攻击范围
private slots:
    void doactive();
private:
    int m_maxnhp;//最大血量
    int m_currenthp;//当前血量
    int m_walkingspeed;//移动速度
    bool m_active;//是否可以移动

    waypoint* m_destinationwaypoint;//目标航点的指针
    MainWindow* m_game;//mainwindows的指针
    QPoint m_pos;//当前位置
    QString m_path;//图片路径
    QList<tower* >m_attackertowerlist;//正在攻击该敌人的防御塔list

    static const QSize m_fixedsize;

};

#endif // ENEMY_H
