﻿#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include "mypushbutton.h"

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
        qDebug() << "click backBtn";
    });
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