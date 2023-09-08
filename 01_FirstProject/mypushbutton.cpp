#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << QString::fromLocal8Bit("我的按钮类的构造函数");
}

MyPushButton::~MyPushButton()
{
    qDebug() << QString::fromLocal8Bit("我的按钮类的析构函数");
}
