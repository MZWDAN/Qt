#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "mypushbutton.h"
#include "mainscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    //设置固定大小
    this->setFixedSize(320, 588);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle(QString::fromLocal8Bit("选择关卡场景"));

    //创建菜单栏
    QMenuBar *bar =  menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu *menu = bar->addMenu(QString::fromLocal8Bit("开始"));

    QAction *quit = new QAction(QString::fromLocal8Bit("退出"));
    menu->addAction(quit);

    //退出按钮实现
    connect(quit, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    //点击返回按钮
    connect(backBtn, &QPushButton::clicked, [=](){
//        qDebug() << "click backBtn";
        //告诉主场景，我返回了，主场景监听ChooseLevelScene的返回按钮
        //延时返回
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSenceBack();
        });

    });

    //创建选择关卡的场景
    for(int i=0;i<20;i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70, 130+i/4*70);

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            QString str = QString::fromLocal8Bit("您选择的是第%1关").arg(i+1);
            qDebug() << str;
            if(play == NULL)
            {
                //进入游戏场景
                this->hide();//将选关场景隐藏掉
                play = new PlayScene(i+1);//创建游戏场景
                play->show();//显示游戏场景
             }
            //监听游戏场景返回按钮的事件
            connect(play, &PlayScene::chooseSenceBack, [=](){
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
//        label->setAlignment(Qt::AlignCenter);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->move(25+i%4*70, 130+i/4*70);

        //设置让鼠标进行穿透 51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}


void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    //画背景上的图标
    pixmap.load(":/res/Title.png");
//    pixmap = pixmap.scaled(QSize(pixmap.width() * 0.5, pixmap.height() * 0.5));
    painter.drawPixmap(this->width()/2 - pixmap.width()/2, 30, pixmap);
}
