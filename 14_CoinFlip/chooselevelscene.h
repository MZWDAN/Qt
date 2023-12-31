﻿#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //画背景
    void paintEvent(QPaintEvent *event);

    //游戏场景对象指针
    PlayScene *play = NULL;

signals:
    //写一个自定义的信号，告诉主场景，点击了返回  自定义的信号，只要声明，不需要实现
    void chooseSenceBack();

};

#endif // CHOOSELEVELSCENE_H
