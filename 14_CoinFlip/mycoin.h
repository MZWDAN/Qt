#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);

    //参数代表  传入的金币路径，还是银币路径
    MyCoin(QString btnImg);

    //金币的属性
    int posX;  //x坐标位置
    int posY;  //y坐标位置
    bool flag;  //正反标识

    //改变标志得方法
    void changeFlag();
    QTimer *timer1;//正面翻反面 定时器
    QTimer *timer2;//反面翻正面 定时器
    int min = 1;//最小图片
    int max = 8;//最大图片

signals:

};

#endif // MYCOIN_H
