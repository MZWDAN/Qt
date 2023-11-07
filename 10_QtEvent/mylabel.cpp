#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    setMouseTracking(true); //默认是false
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
    qDebug() << QString::fromLocal8Bit("鼠标进入了");
}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *)
{
    qDebug() << QString::fromLocal8Bit("鼠标离开了");
}


//鼠标的移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)
//    {
        //这种写法有点链式编程的意思  %1 %2只是顺序
        QString str = QString(QString::fromLocal8Bit("鼠标移动了,x=%1  y=%2 global_x=%3 global_y=%4"))
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
//    }
}

//鼠标的按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键按下，提示信息
    if(ev->button() == Qt::LeftButton) //这个不会区分出来移动的状态，比如左右键都按下了，还是会响应
    {
        //这种写法有点链式编程的意思  %1 %2只是顺序
        QString str = QString(QString::fromLocal8Bit("鼠标按下了,x=%1  y=%2 global_x=%3 global_y=%4"))
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

//鼠标的释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //这种写法有点链式编程的意思  %1 %2只是顺序
    QString str = QString(QString::fromLocal8Bit("鼠标释放了,x=%1  y=%2 global_x=%3 global_y=%4"))
            .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

bool myLabel::event(QEvent *e)
{

}
