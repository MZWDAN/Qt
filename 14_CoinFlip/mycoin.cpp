#include "mycoin.h"
#include <QDebug>
#include <QTimer>

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

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    //监听正面翻反面的信号，并且翻转金币
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //判断如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    //监听反面翻正面的信号，并且翻转金币
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //判断如果翻完了，将min重置为1
        if(this->max < this->min)
        {
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });
}


void MyCoin::changeFlag()
{
    if(this->flag)//如果是正面，执行下列代码
    {
        timer1->start(30);
        isAnimation = true;//开始做动画
        this->flag = false;
    }
    else//反面执行下列代码
    {
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
