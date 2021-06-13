#include "startui.h"
#include "mainwindow.h"

startui::startui()
{
    //构造函数中的添加
        ui->setupUi(this);
        this->setFixedSize(750,375);
            setWindowTitle("start from");
            //打开第一关
            connect(ui->pushButton,&QPushButton::clicked,[=]()
            {
                MainWindow * mainwindow=new MainWindow(parent);
                mainwindow->setPath(":/images/background1.jpg");
                mainwindow->loadTowerPosition1();
                mainwindow->addWayPoint1();
                mainwindow->show();
            });
            //打开游戏规则
            connect(ui->pushButton_2,&QPushButton::clicked,[=]()
            {
                MainWindow * mainwindow=new MainWindow(parent);

                mainwindow->show();
            });

    //其他函数
    void startui::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        QString path(":/images/background.jpg");
        painter.drawPixmap(0,0,750,375,path);
    }
}
