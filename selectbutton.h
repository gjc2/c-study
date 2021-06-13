#ifndef SELECTBUTTON_H
#define SELECTBUTTON_H

#include<QPainter>
#include<QString>
#include<QPoint>
#include<QSize>

#include"mainwindow.h"

class MainWindow;

class selectbutton
{
public:
    selectbutton(QPoint pos,MainWindow* game);
    ~selectbutton();

    void  draw(QPainter* painter) const;//绘画选择框
    void getremoved();//选择框被点击后要移除
    bool containpos(QPoint pos);//判断鼠标的点击点是否在选择框的内部
    QPoint getpos();//得到选择框的左上点
private:
    MainWindow* m_game;
    QPoint m_pos;
    QString m_selectboximagepath[4];//用来存储选择框内防御塔的图片,包括返回键
    static const QSize m_fixedsize;
};

#endif // SELECTBUTTON_H
