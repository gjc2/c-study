#ifndef STARTFROM_H
#define STARTFROM_H

#include <QWidget>

#include "mainwindow.h"//包含mainwindow文件


class startui;

class startui : public QWidget
{
    Q_OBJECT
public:
    explicit startui(QWidget *parent = nullptr);
    ~startui();
    void paintEvent(QPaintEvent *event);//只用添加这个绘画类函数就可以了
private:
    startui *ui;
};
#endif // STARTFROM_H
