#include "form.h"
#include "ui_form.h"
#include "myrule.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setFixedSize(750,375);
    setWindowTitle("start from");
    //打开第一关
    connect(ui->pushButton,&QPushButton::clicked,[=]()
    {
        MainWindow* mainwindows=new MainWindow(parent);
        mainwindows->setpath(":/images/image/map1.jpg");
        mainwindows->loadtowerposition1();
        mainwindows->addwaypoint1();
        mainwindows->show();
    }
    );
    //打开游戏规则
    connect(ui->pushButton_2,&QPushButton::clicked,[=]()
    {
        myrule* a=new myrule;
        a->show();
    }
    );
}

Form::~Form()
{
    delete ui;
}
void Form::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString path(":/images/image/background.jpg");
    painter.drawPixmap(0,0,750,375,path);
}
