﻿#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString presssImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = presssImg;

    QPixmap pixmap;
    bool ret = pixmap.load(normalImg);
    if(!ret)
    {
        qDebug() << "img load error";
        return;
    }

    //设置按钮固定大小
    this->setFixedSize(pixmap.width(), pixmap.height());

    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pixmap);

    //设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::zoom2()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "") // 传入的按下图片不为空，说明需要有按下状态，需要切换图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(this->pressImgPath);
        if(!ret)
        {
            qDebug() << "img load error";
            return;
        }

        //设置按钮固定大小
        this->setFixedSize(pixmap.width(), pixmap.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pixmap);

        //设置图标大小
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "") // 传入的按下图片不为空，说明需要有按下状态，需要切换图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(this->normalImgPath);
        if(!ret)
        {
            qDebug() << "img load error";
            return;
        }

        //设置按钮固定大小
        this->setFixedSize(pixmap.width(), pixmap.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pixmap);

        //设置图标大小
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
