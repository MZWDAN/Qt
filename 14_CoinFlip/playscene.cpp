#include "playscene.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>

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
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    //画背景上的图标
    pixmap.load(":/res/Title.png");
//    pixmap = pixmap.scaled(QSize(pixmap.width() * 0.5, pixmap.height() * 0.5));
    painter.drawPixmap(this->width()/2 - pixmap.width()/2, 30, pixmap);
}
