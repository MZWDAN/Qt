#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    //对栈容器进行修改
    connect(ui->btn_scrollarea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //toolBar按钮
    connect(ui->btn_toolbox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //tabWidget
    connect(ui->btn_tabwidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //下拉框
    ui->comboBox->addItem(QString::fromLocal8Bit("奔驰"));
    ui->comboBox->addItem(QString::fromLocal8Bit("宝马"));
    ui->comboBox->addItem(QString::fromLocal8Bit("拖拉机"));

    //点击按钮，选中拖拉机
    connect(ui->btn_select, &QPushButton::clicked, [=](){
//        ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText(QString::fromLocal8Bit("拖拉机"));
    });

    //利用QLabel显示图片
    ui->label->setPixmap(QPixmap(":/images/pic.jpeg"));

    //利用QLabel显示Gif动图
    QMovie *movie = new QMovie(":/images/pic.jpeg");  //这里替换成gif动图就可以了
    ui->label_movie->setMovie(movie);

    //播放动图
    movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

