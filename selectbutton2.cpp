#include "selectbutton2.h"

#include "mainwindow.h"
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QString>

static const int cost1=300;
static const int cost2=400;

const QSize selectbutton2::m_fixedsize(105,35);
selectbutton2::selectbutton2(QPoint pos,MainWindow* game):
    m_game(game),
    m_pos(pos)
{
    m_selectboximagepath[0]=":/images/image/up.jpg";
    m_selectboximagepath[1]=":/images/image/down.jpg";
    m_selectboximagepath[2]=":/images/image/back.jpg";
}
selectbutton2::~selectbutton2()
{
    m_game=NULL;
    m_tower=NULL;
}
void selectbutton2::draw(QPainter *painter) const
{
    painter->save();
    painter->drawPixmap(m_pos.x(),m_pos.y(),m_selectboximagepath[0]);
    painter->drawPixmap(m_pos.x()+35,m_pos.y(),m_selectboximagepath[1]);
    painter->drawPixmap(m_pos.x()+70,m_pos.y(),m_selectboximagepath[2]);
    painter->restore();
}
bool selectbutton2::containpos(QPoint pos)
{
    bool xinhere=pos.x()>m_pos.x()&&pos.x()<m_pos.x()+m_fixedsize.width();
    bool yinhere=pos.y()>m_pos.y()&&pos.y()<m_pos.y()+m_fixedsize.height();
    return xinhere&&yinhere;
}
QPoint selectbutton2::getpos()
{
    return this->m_pos;
}
void selectbutton2::getremoved()
{
    m_game->removebutton2(this);
}
void selectbutton2::settower(tower *Tower)
{
    m_tower=Tower;
}
