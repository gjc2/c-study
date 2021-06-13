#include "selectbutton.h"

const QSize selectbutton::m_fixedsize(140,35);

selectbutton::selectbutton(QPoint pos,MainWindow* game):
    m_game(game),
    m_pos(pos)
{
    m_selectboximagepath[0]=":/images/image/tower1.jpg";
    m_selectboximagepath[1]=":/images/image/tower2.jpg";
    m_selectboximagepath[2]=":/images/image/tower3.jpg";
    m_selectboximagepath[3]=":/images/image/back.jpg";
}
selectbutton::~selectbutton()
{
    m_game=NULL;
}
void selectbutton::draw(QPainter *painter) const
{
    painter->save();
    painter->drawPixmap(m_pos.x(),m_pos.y(),m_selectboximagepath[0]);
    painter->drawPixmap(m_pos.x()+35,m_pos.y(),m_selectboximagepath[1]);
    painter->drawPixmap(m_pos.x()+70,m_pos.y(),m_selectboximagepath[2]);
    painter->drawPixmap(m_pos.x()+105,m_pos.y(),m_selectboximagepath[3]);
    painter->restore();
}
void selectbutton::getremoved()
{
    m_game->removebutton(this);
}
bool selectbutton::containpos(QPoint pos)
{
    bool xinhere=pos.x()>m_pos.x()&&pos.x()<m_pos.x()+m_fixedsize.width();
    bool yinhere=pos.y()>m_pos.y()&&pos.y()<m_pos.y()+m_fixedsize.height();
    return xinhere&&yinhere;
}
QPoint selectbutton::getpos()
{
    return this->m_pos;
}
