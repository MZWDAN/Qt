#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QPushButton>
#include <QAction>
#include <QPainter>
#include <QPixmap>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320, 588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("小蛋蛋带你翻金币"));

    //退出按钮实现
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    //开始按钮实现
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move((this->width()/2 - startBtn->width()/2), this->height() * 0.7);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画背景上的图标
    pix.load(":/res/Title.png");

    //图像缩放
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);

    painter.drawPixmap(10, 30, pix);
}
