#ifndef SELECTBUTTON2_H
#define SELECTBUTTON2_H

#include <QPainter>
#include <QPoint>
#include <QSize>

#include "mainwindow.h"
#include "tower.h"

class MainWindow;
class tower;

class selectbutton2
{
public:
    selectbutton2(QPoint pos,MainWindow* game);
    ~selectbutton2();

    void draw(QPainter* painter) const;
    void getremoved();
    tower* gettower();//得到该处的防御塔
    void settower(tower* Tower);
    bool containpos(QPoint pos);//判断点击的该点是否在button2内部
    QPoint getpos();
private:
    MainWindow* m_game;
    tower* m_tower;
    QPoint m_pos;
    QString m_selectboximagepath[3];
    static const QSize m_fixedsize;
};

#endif // SELECTBUTTON2_H
