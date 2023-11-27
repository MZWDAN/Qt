#include "chooselevelscene.h"
#include <QMenuBar>

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
}
