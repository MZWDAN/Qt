#include "playscene.h"
#include "mypushbutton.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;

    //配置选择关卡场景
    //设置固定大小
    this->setFixedSize(320, 588);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle(QString::fromLocal8Bit("翻金币场景"));

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

    connect(backBtn, &QPushButton::clicked, [=](){
        qDebug() << QString::fromLocal8Bit("翻金币场景中，点击了返回按钮");
        //延时返回
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSenceBack();
        });

    });

    //显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily(QString::fromLocal8Bit("华文新魏"));
    font.setPointSize(20);

    QString str = QString::fromLocal8Bit("Level:%1").arg(this->levelIndex);
    label->setText(str);
    //设置大小并且移动
//    label->setFixedSize();
//    label->move(100, 500);
    //另一种设置大小并且移动的方法
    label->setGeometry(QRect(30, this->height() - 50, 120, 50));
    label->setFont(font);
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    //创建背景
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    //画背景上的图标
    pixmap.load(":/res/Title.png");
    pixmap = pixmap.scaled(QSize(pixmap.width() * 0.5, pixmap.height() * 0.5));
    painter.drawPixmap(10, 30, pixmap);
}
