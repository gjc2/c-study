#include "myrule.h"
#include "ui_myrule.h"

myrule::myrule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myrule)
{
    ui->setupUi(this);
}

myrule::~myrule()
{
    delete ui;
}
void myrule::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path(":/images/image/rules.jpg");
    painter.drawPixmap(0,0,750,375,path);
}
