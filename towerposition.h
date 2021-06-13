#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QSize>
#include<QString>
#include<QPainter>
#include "selectbutton.h"
#include "selectbutton2.h"
#include "tower.h"
class tower;
class selectbutton2;
class selectbutton;

class towerposition
{
public:
    towerposition(QPoint pos,QString path=(":/images/image/position.png"));
    QPoint getcenterpos();//得到防御塔坑的中心点
    QPoint getpos();//得到防御塔坑的左上点
    bool containpos(QPoint pos);//判断pos点是否在防御塔坑范围内
    void draw(QPainter* painter) const;
    bool hastower();//判断防御塔坑内是否有防御塔
    void sethastower(bool hastower=true);//设置是否有防御塔
    bool hasbutton();//判断该位置有没有button
    void sethasbutton(bool hasbutton=true);//设置是否有button
    void setbutton(selectbutton* button);//设置button
    selectbutton* getbutton();//得到该位置的button

    bool hastower1();//判断是否有塔1
    void sethastower1(bool hastower1=true);

    bool hastower2();//判断是否有塔2
    void sethastower2(bool hastower2=true);

    bool hastower3();//判断是否有塔3
    void sethastower3(bool hastower3=true);

    bool hasbutton2();//判断是否有button2
    void sethasbutton2(bool hasbutton2=true);
    void setbutton2(selectbutton2* button);
    selectbutton2* getbutton2();

    void sethasupdate1(bool hasupdate1);
    bool hasupdate1();

    void sethasupdate2(bool hasupdate2);
    bool hasupdate2();

    void settower(tower* Tower);
    tower* gettower();
    void removetower();

private:
    QPoint m_pos;
    QString m_path;
    bool m_hastower;
    static const QSize m_fixedsize;
    bool m_hasbutton;
    bool m_hastower1;
    bool m_hastower2;
    bool m_hastower3;
    selectbutton* m_button;

    bool m_hasbutton2;
    bool m_hasupdate1;
    bool m_hasupdate2;
    selectbutton2* m_button2;
    tower* m_tower;
};

#endif // TOWERPOSITION_H
