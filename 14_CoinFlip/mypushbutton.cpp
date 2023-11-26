#include "mypushbutton.h"
#include <QDebug>

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
