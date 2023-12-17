#include "mycoin.h"
#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pixmap;
    bool ret = pixmap.load(btnImg);
    if(!ret)
    {
        QString str = QString("img %1 load error").arg(btnImg);
        qDebug() << str;
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
