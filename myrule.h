#ifndef MYRULE_H
#define MYRULE_H

#include <QWidget>

#include"mainwindow.h"

namespace Ui {
class myrule;
}

class myrule : public QWidget
{
    Q_OBJECT

public:
    explicit myrule(QWidget *parent = nullptr);
    ~myrule();
    void paintEvent(QPaintEvent *event);
private:
    Ui::myrule *ui;
};

#endif // MYRULE_H
