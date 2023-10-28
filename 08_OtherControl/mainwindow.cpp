#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //对栈容器进行修改
//    connect(ui-)
}

MainWindow::~MainWindow()
{
    delete ui;
}

