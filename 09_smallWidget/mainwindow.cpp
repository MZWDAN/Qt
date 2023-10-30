#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击获取当前值，返回当前值
//    QWidget *widget = new CSmallWidget();

    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getNum();
    });

    //点击设置到一半，就设置到一半
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget->setNum(50);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

