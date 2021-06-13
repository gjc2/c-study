#include "towerposition.h"

#include<QSize>
#include<QPainter>
#include<QPixmap>

const QSize towerposition::m_fixedsize(35,35);
towerposition::towerposition(QPoint pos,QString path):
    m_pos(pos),
    m_path(path),
    m_hastower(false),
    m_hastower1(false),
    m_hastower2(false),
    m_hastower3(false),
    m_hasbutton(false),
    m_hasbutton2(false),
    m_hasupdate1(false),
    m_hasupdate2(false)
{

}
bool towerposition::hastower()
{
    return m_hastower;
}
void towerposition::sethastower(bool hastower)
{
    m_hastower=hastower;
}
QPoint towerposition::getcenterpos()
{
    QPoint tmp;
    tmp.setX(m_pos.x()+m_fixedsize.width()/2);
    tmp.setY(m_pos.y()+m_fixedsize.height()/2);
    return tmp;
}
QPoint towerposition::getpos()
{
    return m_pos;
}
bool towerposition::containpos(QPoint pos)
{
    bool xinhere=(pos.x()>m_pos.x())&&(pos.x()<m_pos.x()+m_fixedsize.width());
    bool yinhere=(pos.y()>m_pos.y())&&(pos.y()<m_pos.y()+m_fixedsize.height());
    return xinhere&&yinhere;
}
void towerposition::draw(QPainter* painter) const
{
    painter->drawPixmap(m_pos.x(),m_pos.y(),m_path);
}
bool towerposition::hasbutton()
{
    return m_hasbutton;
}
void towerposition::sethasbutton(bool hasbutton)
{
    m_hasbutton=hasbutton;
}
void towerposition::setbutton(selectbutton *button)
{
    m_button=button;
}
selectbutton* towerposition::getbutton()
{
    return m_button;
}
void towerposition::sethastower1(bool hastower11)
{
    this->m_hastower1=hastower11;
    sethastower(hastower11);
}
bool towerposition::hastower1()
{
    return m_hastower1;
}
void towerposition::sethastower2(bool hastower22)
{
    this->m_hastower2=hastower22;
    sethastower(hastower22);
}
bool towerposition::hastower2()
{
    return m_hastower2;
}
void towerposition::sethastower3(bool hastower33)
{
    this->m_hastower3=hastower33;
    sethastower(hastower33);
}
bool towerposition::hastower3()
{
    return m_hastower3;
}
void towerposition::sethasbutton2(bool hasbutton2)
{
    m_hasbutton2=hasbutton2;
}
bool towerposition::hasbutton2()
{
    return m_hasbutton2;
}
void towerposition::sethasupdate1(bool hasupdate1)
{
    m_hasupdate1=hasupdate1;
}
bool towerposition::hasupdate1()
{
    return m_hasupdate1;
}

void towerposition::sethasupdate2(bool hasupdate2)
{
    m_hasupdate2=hasupdate2;
}
bool towerposition::hasupdate2()
{
    return m_hasupdate2;
}
void towerposition::setbutton2(selectbutton2 *button)
{
    m_button2=button;
}
void towerposition::settower(tower *Tower)
{
    m_tower=Tower;
}
tower* towerposition::gettower()
{
    return this->m_tower;
}
selectbutton2* towerposition::getbutton2()
{
    return m_button2;
}
void towerposition::removetower()
{
    settower(NULL);
    sethastower(false);
    sethastower1(false);
    sethastower2(false);
    sethastower3(false);
    sethasupdate1(false);
    sethasupdate2(false);
}
