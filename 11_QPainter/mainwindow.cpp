#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //点击移动按钮，移动图片
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        //如果要手动调用绘图事件，用update更新
        posX += 20;
        update();
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        //如果要手动调用绘图事件，用update更新
        posX -= 20;
        update();
    });

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, &QTimer::timeout, [=](){
        posX += 10;
        update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
//    //实例化画家对象  this指定的是绘图的设备
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255, 100, 200));
//    pen.setWidth(5);
//    pen.setStyle(Qt::DashLine);

//    //让画家使用这个笔
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(QColor(100, 100, 200));
//    brush.setStyle(Qt::Dense1Pattern);
//    painter.setBrush(brush);

//    //画线
//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

//    //画圆
//    painter.drawEllipse(QPoint(100, 100), 100, 50);

//    //画矩形
//    painter.drawRect(QRect(100, 100, 300, 300));

//    //画文字
//    painter.drawText(QRect(500, 500, 500, 500), QString::fromLocal8Bit("蛋蛋喜欢呆呆"));


    ///////////////////////////////高级设置////////////////////////////////
//    QPainter painter(this);
////    painter.drawEllipse(QPoint(100, 100), 100, 100);
////    //设置 抗锯齿能力
////    //QPainter::Antialiasing: 效率较低
////    painter.setRenderHint(QPainter::Antialiasing);
////    painter.drawEllipse(QPoint(400, 100), 100, 100);
//    painter.drawRect(QRect(20, 20, 50, 50));

//    //移动画家
//    painter.translate(100, 100);//相当于让画家移了一个位置

//    //保存画家状态
//    painter.save();

//    painter.drawRect(QRect(20, 20, 50, 50));

//    painter.translate(100, 100);

//    //还原画家保存状态
//    painter.restore();

//    painter.drawRect(QRect(20, 20, 50, 50));

    /////////////////////////// 利用画家画资源图片 //////////////////////////////
    QPainter painter(this);

    //如果超出了屏幕，就从0开始
    if (posX > this->width() || posX < -(this->width()))
    {
        posX = 0;
    }
    painter.drawPixmap(posX, 0, QPixmap(":/images/pic.jpeg"));


}
