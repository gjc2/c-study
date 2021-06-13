#ifndef BULLET_H
#define BULLET_H

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
class bullet:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint m_currentpos READ getcurrentpos WRITE setcurrentpos)//子弹动态移动
public:
    bullet();
    bullet(QPoint startpos,QPoint targetpos,int damage,enemy* targetenemy,MainWindow* game,QString path=":/images/image/bullet1.jpg");
    QPoint getcurrentpos();//得到子弹的当前位置
    void setcurrentpos(QPoint pos);//设置子弹的当前位置
    virtual void move();//子弹的移动
    void draw(QPainter* painter) const;//绘画子弹
    QPoint getstartpos();//
    QPoint gettargetpos();//
    MainWindow* getgame();
    enemy* gettargetenemy();//
    int getdamage();//
    void change(QString path);
private slots:
    virtual void hittarget();//私有信号槽，击中敌人的时候触发
private:
    QPoint m_startpos;
    QPoint m_targetpos;
    QPoint m_currentpos;
    int m_damage;
    QString m_path;
    enemy* m_targetenemy;
    MainWindow* m_game;
    static const QSize m_fixedsize;
};

#endif // BULLET_H
