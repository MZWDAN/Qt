#include "mywidget.h"
#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>
#include <QString>

MyWidget::MyWidget(QWidget *parent)
    : QMainWindow(parent)
{
    //创建一个按钮对象
    QPushButton *btn = new QPushButton;

    //创建一个自己的按钮的对象
    MyPushButton *myBtn = new MyPushButton(this);
    myBtn->setText(QString::fromLocal8Bit("我自己的按钮"));
//    myBtn->move(200, 0);

    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
}

MyWidget::~MyWidget()
{
}

