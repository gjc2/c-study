#ifndef WAYPOINT_H
#define WAYPOINT_H
#include<QPoint>
#include<QPainter>

class waypoint
{
public:
    waypoint(QPoint pos);//构造函数，构造一个航点
    void setnextwaypoint(waypoint* nextpoint);//设置下一个航点
    waypoint* getnextpoint();//得到下一个航点的指针
    const QPoint getpos();//得到本航点的中心点
    void draw(QPainter* painter) const;//绘画类函数，画出航点
private:
    QPoint m_pos;//航点的中心点
    waypoint* m_nextwaypoint;//指向下一个航点的指针
};

#endif // WAYPOINT_H
