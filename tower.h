#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include<QPoint>
#include<QSize>
#include<QString>
#include<QTimer>
#include"enemy.h"
#include"mainwindow.h"

class MainWindow;
class QPainter;
class enemy;
class QTimer;
class tower;
class tower:public QObject
{
    Q_OBJECT
public:
    tower(QPoint pos,MainWindow* game,QString path=":/images/image/tower1.jpg");
    ~tower();
    tower();
    void draw(QPainter* painter) const;//画出防御塔
    void attackenemy();//攻击敌人
    void targetkilled();//当目标被击杀之后
    void chooseenemyfromattack(enemy* Enemy);//从可以被攻击的敌人中选择敌人

    void removebullet();//移除防御塔产生的子弹
    void lostsightofenemy();//丢失攻击目标的视野
    void checkenemyinrange();//检查敌人是否在攻击范围内
    enemy* getattackedenemy();//得到正在被攻击的敌人
    void change(int damage,int attackrange,int firerate);//改变防御塔的属性
    QPoint getpos();//得到防御塔中心点
    enemy* getchooseenemy();//得到正在攻击的敌人
    int getdamaged();//得到攻击力
    MainWindow* getgame();//得到游戏
    QTimer* getfireratetime();//
    void changefire(QTimer* p);//
    enemy* getnextenemy();//得到下一个被攻击的敌人
    int getattackrange();
    void changepath(QString path);
    void levelchange();
    int getlevel();
    void getremoved();
    int getfirerate();
private slots:
    virtual void shootwarpon();//私有信号槽，实现和子弹类的连接,在这里声明为虚函数是十分重要的，这样实现了多态，我们父类的指针就可以去调用子类的此函数了
private:
    QPoint m_pos;//防御塔的中心点
    QString m_path;//防御塔图片的路径

    int m_attackrange;//防御塔的攻击范围
    static const QSize m_fixedsize;//防御塔图片的固定大小
    MainWindow* m_game;//指向mainwindows的指针
    bool m_attacking;//是否在攻击
    int m_damage;//防御塔的攻击力
    int m_firerate;//防御塔的射速
    enemy* m_chooseenemy;//正在攻击的敌人
    QTimer* m_fireratetime;
    enemy* next_enemy=NULL;//下一个被攻击的敌人
    int m_level=1;
};

#endif // TOWER_H
