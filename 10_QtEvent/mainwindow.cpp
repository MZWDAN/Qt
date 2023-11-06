#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QDebug>
#include <QTimer> //定时器类

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //启动定时器
    //参数1：间隔 单位是毫秒
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    //定时器的第二种方式
    QTimer *timer = new QTimer(this);
    //启动定时器
    static int num3 = 1;
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        ui->label_4->setText(QString::number(num3++));
    });

    //点击暂停按钮，实现停止定时器
    connect(ui->pushButton, &QPushButton::clicked, timer, &QTimer::stop);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == id1)
    {
        //label_2每隔一秒加一
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    else if (ev->timerId() == id2) {
        //label_3每隔两秒加一
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}
