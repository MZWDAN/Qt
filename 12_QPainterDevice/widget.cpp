﻿#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备
//    QPixmap pix(300, 300);

//    //填充颜色
//    pix.fill(QColor(Qt::white));

//    //声明画家
//    QPainter painter(&pix);
//    //设置颜色
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    //保存
//    pix.save("save.png");

    //QImage作为绘图设备  可以对像素点进行访问
    QImage img(300, 300, QImage::Format_RGB32);
    img.fill(Qt::black);

    QPainter painter(&img);
    painter.setPen(QPen(Qt::yellow));
    painter.drawEllipse(QPoint(200, 200), 100, 100);
    img.save("img.png");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //利用QImage，对像素进行修改
    QImage img;
    img.load(":/images/pic.jpeg");

    //修改像素点
    for(int i = 50; i < 100; i++)
    {
        for(int j = 50; j < 100; j++)
        {
            QRgb value = qRgb(255, 255, 0);
            img.setPixel(i, j, value);
        }
    }

    painter.drawImage(0, 0, img);
}
