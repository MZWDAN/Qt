#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //实例化画家对象  this指定的是绘图的设备
    QPainter painter(this);

    //设置画笔
    QPen pen(QColor(255, 100, 200));
    pen.setWidth(5);
    pen.setStyle(Qt::DashLine);

    //让画家使用这个笔
    painter.setPen(pen);

    //设置画刷
    QBrush brush(QColor(100, 100, 200));
    brush.setStyle(Qt::Dense1Pattern);
    painter.setBrush(brush);

    //画线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    //画圆
    painter.drawEllipse(QPoint(100, 100), 100, 50);

    //画矩形
    painter.drawRect(QRect(100, 100, 300, 300));

    //画文字
    painter.drawText(QRect(500, 500, 500, 500), QString::fromLocal8Bit("蛋蛋喜欢呆呆"));
}
