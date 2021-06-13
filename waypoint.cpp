#include "waypoint.h"
#include<QPainter>
#include<QPoint>
waypoint::waypoint(QPoint pos):
    m_pos(pos),
    m_nextwaypoint(NULL)
{

}
void waypoint::setnextwaypoint(waypoint *nextpoint)
{
    m_nextwaypoint=nextpoint;
}
waypoint* waypoint::getnextpoint()
{
    return m_nextwaypoint;
}
const QPoint waypoint::getpos()
{
    return m_pos;
}
void waypoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::green);
    painter->drawEllipse(m_pos,1,1);
    painter->drawEllipse(m_pos,4,4);
    if(m_nextwaypoint)
    {
        painter->drawLine(m_pos,m_nextwaypoint->getpos());
    }
    painter->restore();
}
