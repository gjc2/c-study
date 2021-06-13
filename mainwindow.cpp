#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "towerposition.h"
#include "enemy.h"
#include "selectbutton.h"
#include "tower2.h"
#include <QDebug>
#include "tower3.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_playerhp(5)
    ,m_playergold(1000)
    ,m_waves(0)
    ,m_gamewin(false)
    ,m_gamelose(false)
{
    ui->setupUi(this);
    addwaypoint1();//增加航点函数的调用
    loadtowerposition1();//增加防御塔坑建立的函数
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatemap()));
    timer->start(30);
    QTimer::singleShot(300,this,SLOT(gamestart()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    if(m_gamewin||m_gamelose)
    {
        QString text=m_gamelose?"YOU LOST":"YOU WIN";
        QPainter painter(this);
        painter.setPen(Qt::red);
        painter.drawText(rect(),Qt::AlignCenter,text);
        return;
    }
    QPainter painter(this);
    QString path=getpath();/*":/images/image/map1.jpg");*/
    painter.drawPixmap(0,0,750,375,path);
    foreach(const waypoint * waypoint,m_waypointlist)
            waypoint->draw(&painter);//航点绘画
    foreach(const towerposition towerposition ,m_towerpositionlist)
        towerposition.draw(&painter);
    foreach(const tower* Tower,m_towerlist)
        Tower->draw(&painter);
    foreach(const enemy* Enemy,m_enemylist)
        Enemy->draw(&painter);
    foreach(const bullet* Bullet,m_bulletlist)
        Bullet->draw(&painter);
    foreach(const selectbutton* button ,m_selectbuttonlist)
        button->draw(&painter);
    foreach(const selectbutton2 * button2,m_selectbutton2list)
            button2->draw(&painter);
    drawhp(&painter);
    drawgold(&painter);
    drawwaves(&painter);
}
void MainWindow::addwaypoint1()
{
    //第一个航点
    waypoint* waypoint1=new waypoint(QPoint(95,340));
    m_waypointlist.push_back(waypoint1);
    //第二个航点
    waypoint* waypoint2=new waypoint(QPoint(95,210));
    waypoint1->setnextwaypoint(waypoint2);
    m_waypointlist.push_back(waypoint2);
    //第三个航点
    waypoint* waypoint3=new waypoint(QPoint(280,210));
    waypoint2->setnextwaypoint(waypoint3);
    m_waypointlist.push_back(waypoint3);
    //第四个航点
    waypoint* waypoint4=new waypoint(QPoint(280,115));
    waypoint3->setnextwaypoint(waypoint4);
    m_waypointlist.push_back(waypoint4);
    //第五个航点
    waypoint* waypoint5=new waypoint(QPoint(590,115));
    waypoint4->setnextwaypoint(waypoint5);
    m_waypointlist.push_back(waypoint5);
    //第六个航点
    waypoint* waypoint6=new waypoint(QPoint(590,250));
    waypoint5->setnextwaypoint(waypoint6);
    m_waypointlist.push_back(waypoint6);
    //第七个航点
    waypoint* waypoint7=new waypoint(QPoint(345,250));
    waypoint6->setnextwaypoint(waypoint7);
    m_waypointlist.push_back(waypoint7);
    //第八个航点
    waypoint* waypoint8=new waypoint(QPoint(345,345));
    waypoint7->setnextwaypoint(waypoint8);
    m_waypointlist.push_back(waypoint8);
    //第九个航点
    waypoint* waypoint9=new waypoint(QPoint(660,345));
    waypoint8->setnextwaypoint(waypoint9);
    m_waypointlist.push_back(waypoint9);
}
void MainWindow::loadtowerposition1()
{
    QPoint pos[]=
    {
        QPoint(80,150),
        QPoint(260,240),
        QPoint(330,190),
        QPoint(325,50),
        QPoint(510,50),
        QPoint(390,285),
        QPoint(580,285),
    };
    int len=sizeof(pos)/sizeof(pos[0]);
    for(int i=0;i<len;i++)
    {
        m_towerpositionlist.push_back(pos[i]);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)//暂时有bug
{
    QPoint presspos=event->pos();//得到鼠标单击的位置
    auto it=m_towerpositionlist.begin();
//    qDebug("1\n");
    while(it!=m_towerpositionlist.end())//便利所有防御塔底座
    {
        if(Qt::LeftButton==event->button())//鼠标左键点击
        {
//            qDebug("3\n");
            if(!it->hasbutton()&&it->containpos(presspos) && !it->hastower())
            {
                QPoint tmp(it->getpos().x()-35,it->getpos().y()-35);//得到防御塔坑的位置
                selectbutton* button=new selectbutton(tmp,this);
                it->sethasbutton(true);
                it->setbutton(button);
                m_selectbuttonlist.push_back(button);//把这个button加入到mainwindows中
                update();//更新地图
                break;
            }
            else if(it->hasbutton2() && it->getbutton2()->containpos(presspos) && !it->hasbutton() && it->hastower())
            {

                if((presspos.x())<(it->getbutton2()->getpos().x()+35))
                {

                    if(canupdate1()  &&!it->hasupdate1() && it->hastower())
                    {

                        it->sethasupdate1(true);
                        m_playergold-=300;
                        int damage=it->gettower()->getdamaged()+20;

                        int range=it->gettower()->getattackrange()+50;
                        int rate=it->gettower()->getfirerate()+100;

                        it->gettower()->change(damage,range,rate);

                        it->gettower()->levelchange();

                    }
                    else if(canupdate2() && it->hasupdate1() && !it->hasupdate2())
                    {
                        it->sethasupdate2(true);
                        m_playergold-=400;
                        it->gettower()->change(it->gettower()->getdamaged()+30,it->gettower()->getattackrange()+50,it->gettower()->getfirerate()+200);
                        it->gettower()->levelchange();
                    }
                }
                else if(presspos.x()<(it->getbutton2()->getpos().x()+70) && presspos.x()>(it->getbutton2()->getpos().x()+35))
                {
                    m_playergold+=200;
                    it->gettower()->getremoved();
                    it->removetower();
                }
                else if(presspos.x()<(it->getbutton2()->getpos().x()+105) &&presspos.x()>(it->getbutton2()->getpos().x()+70))
                {
                    it->getbutton2()->getremoved();
                    it->setbutton2(NULL);
                    it->sethasbutton2(false);
                    update();
                    break;
                }
                it->getbutton2()->getremoved();
                it->setbutton2(NULL);
                it->sethasbutton2(false);
                update();
                break;

            }
            else if(it->hasbutton() && it->getbutton()->containpos(presspos) && !it->hastower())
            {
                qDebug("33\n");
                if((presspos.x())< (it->getbutton()->getpos().x()+35 )&& canbuytower())
                {
    //                qDebug("2\n");
                    it->sethastower1(true);
                    m_playergold-=300;
                    QString path=":/images/image/tower1.jpg";
                    tower* Tower=new tower(it->getcenterpos(),this,path);
                    it->settower(Tower);
                    m_towerlist.push_back(Tower);
                }
                else if(presspos.x()>it->getbutton()->getpos().x()+35&&presspos.x()<it->getbutton()->getpos().x()+70&&canbuytower2())
                {
                    it->sethastower2(true);
                    m_playergold-=400;
                    QString path=":/images/image/tower2.jpg";
                    tower2* Tower=new tower2(it->getcenterpos(),this,path);
                    it->settower(Tower);
                    m_towerlist.push_back(Tower);
                }
                else if(presspos.x()>it->getbutton()->getpos().x()+70&&presspos.x()<it->getbutton()->getpos().x()+105&&canbuytower3())
                {
                    it->sethastower3(true);
                    m_playergold-=500;
                    QString path=":/images/image/tower3.jpg";
                    tower3* Tower=new tower3(it->getcenterpos(),this,path);
                    it->settower(Tower);
                    m_towerlist.push_back(Tower);
                }
                else if(presspos.x()>it->getbutton()->getpos().x()+105&&presspos.x()<it->getbutton()->getpos().x()+140)
                {
                    it->getbutton()->getremoved();
                    it->setbutton(NULL);
                    it->sethasbutton(false);
                    update();
                    break;
                }
                it->getbutton()->getremoved();
                it->setbutton(NULL);
                it->sethasbutton(false);
                update();
                break;

            }
        }
        else if(Qt::RightButton==event->button())//如果是鼠标右键点击
                {//在有防御塔的情况下，右键会出现选择框，升级还有移除
                    if(it->containpos(presspos) && (!it->hasbutton2()) && it->hastower())
                    {
                        it->sethasbutton2(true);
                        QPoint tmp(it->getpos().x()-35,it->getpos().y()-35);
                        selectbutton2 * button2=new selectbutton2(tmp,this);
                        button2->settower(it->gettower());
                        m_selectbutton2list.push_back(button2);
                        it->setbutton2(button2);
                        update();
                        break;
                    }
                }
         ++it;
    }

}
void MainWindow::gethpdamaged()
{
    m_playerhp--;
}
void MainWindow::awardgold()
{
    m_playergold+=200;
}
void MainWindow::removeenemy(enemy *Enemy)
{
    Q_ASSERT(Enemy);//断言enemy对象存在
    m_enemylist.removeOne(Enemy);//死亡的敌人从enemylist中移除
    delete Enemy;
    if(m_enemylist.empty())
    {
        ++m_waves;
        if(!loadwaves())
        {
            m_gamewin=true;
        }
    }

}
QList<enemy* >MainWindow::getenemylist()
{
    return m_enemylist;
}
bool MainWindow::loadwaves()
{
    if(m_waves>=6)
    {
        return false;
    }
    int enemystartinterval[]={100,500,600,1000,3000,6000};
    for(int i=0;i<6;i++)
    {
        waypoint* startwaypoint;
        startwaypoint=m_waypointlist.first();
        enemy* Enemy=new enemy(startwaypoint,this);
        m_enemylist.push_back(Enemy);
        QTimer::singleShot(enemystartinterval[i],Enemy,SLOT(doactive()));
    }
    return true;
}
void MainWindow::gamestart()
{
    loadwaves();
}
void MainWindow::updatemap()
{
//    foreach(tower* Tower ,m_towerlist)
//        Tower->checkenemyinrange();
    foreach(enemy* Enemy,m_enemylist)
        Enemy->move();
    foreach(tower* Tower ,m_towerlist)
        Tower->checkenemyinrange();

    update();


}
void MainWindow::dogameover()
{
    if(!m_gamelose)
    {
        m_gamelose=true;
    }
}
bool MainWindow::canbuytower()
{
    if(m_playergold>=300)
    {
        return true;
    }
    return false;
}
void MainWindow::drawwaves(QPainter *painter) const
{
    painter->save();
    painter->setPen((Qt::red));
    painter->drawText(QRect(500,5,100,25),QString("WAVES: %1").arg(m_waves+1));
    painter->restore();
}
void MainWindow::drawhp(QPainter *painter) const
{
    painter->save();
    painter->setPen((Qt::red));
    painter->drawText(QRect(30,5,100,25),QString("HP: %1").arg(m_playerhp));
    painter->restore();
}
void MainWindow::drawgold(QPainter *painter) const
{
    painter->save();
    painter->setPen((Qt::red));
    painter->drawText(QRect(300,5,100,25),QString("COLD: %1").arg(m_playergold));
    painter->restore();
}

void MainWindow::removebullet(bullet *Bullet)
{
    Q_ASSERT(Bullet);
    m_bulletlist.removeOne(Bullet);
    delete Bullet;
}
void MainWindow::addbullet(bullet *Bullet)
{
    Q_ASSERT(Bullet);
    m_bulletlist.push_back(Bullet);
}
bool MainWindow::canbuytower2()
{
    if(m_playergold>=400)
    {
        return true;
    }
    return false;
}
bool MainWindow::canbuytower3()
{
    if(m_playergold>=500)
    {
        return true;
    }
    return false;
}
void MainWindow::removebutton(selectbutton *button)
{
    m_selectbuttonlist.removeOne(button);
}
void MainWindow::removetower(tower *Tower)
{
    m_towerlist.removeOne(Tower);
}
void MainWindow::removebutton2(selectbutton2 *button)
{
    m_selectbutton2list.removeOne(button);
}
bool MainWindow::canupdate1()
{
    if(m_playergold>=300)
    {
        return true;
    }
    return false;
}
bool MainWindow::canupdate2()
{
    if(m_playergold>=400)
    {
        return true;
    }
    return false;
}
void MainWindow::setpath(QString path)
{
    m_path=path;
}
QString MainWindow::getpath()
{
    return m_path;
}
