#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include "waypoint.h"
#include "towerposition.h"
#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "selectbutton.h"
#include "selectbutton2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class tower;
class waypoint;
class enemy;
class bullet;
class selectbutton;
class towerposition;
class selectbutton2;
class MainWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addwaypoint1();//添加航点的函数
    void loadtowerposition1();//添加防御塔座
    void gethpdamaged();//敌人进入基地扣血
    void awardgold();//敌人死亡奖励金币
    void removeenemy(enemy* Enemy);//敌人死亡，移除
    QList<enemy* > getenemylist();//得到enemy*的list
    bool loadwaves();//加载敌人的函数
    void removebullet(bullet* Bullet);
    void addbullet(bullet* Bullet);
    void drawhp(QPainter* painter) const;//画出当前基地的血量
    void drawgold(QPainter* painter) const;//画出金钱
    void drawwaves(QPainter* painter) const;//画出波数信息
    bool canbuytower();
    void dogameover();//执行游戏结束
    bool canbuytower2();//是否可以买第二种塔
    bool canbuytower3();//是否可以买第三种塔
    void removebutton(selectbutton* button);//对button进行移除
    void removebutton2(selectbutton2* button);

    void removetower(tower* Tower);
    bool canupdate1();
    bool canupdate2();
    void setpath(QString path);
    QString getpath();
protected:
    void mousePressEvent(QMouseEvent* );//重写鼠标点击类函数
    void paintEvent(QPaintEvent*);//重写paintEvent函数,paintEvent是Qweight的虚函数，而qMainWindows是Qweight的子类，MainWindows又是Qmainwindows的子类，所以直接重写就可以
private:
    Ui::MainWindow *ui;
    QList<waypoint* >m_waypointlist;//用来储存航点的list
    QList<towerposition>m_towerpositionlist;//用来储存防御塔座的list
    QList<tower* >m_towerlist;//用于存放防御塔的list
    QList<enemy* >m_enemylist;//用于存放敌人的list
    int m_playerhp;
    int m_playergold;
    int m_waves;//波数
    bool m_gamewin;
    bool m_gamelose;
    QList<bullet* >m_bulletlist;//用于存储子弹的list
    QList<selectbutton* >m_selectbuttonlist;//用来存储selectbutton的list
    QList<selectbutton2* >m_selectbutton2list;
    QString m_path;
private slots:
    void updatemap();
    void gamestart();
};
#endif // MAINWINDOW_H
