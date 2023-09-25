#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏创建
    QMenuBar *bar = menuBar();

    //创建菜单成员
    QMenu *fileMenu = bar->addMenu("File");
    fileMenu->setIcon(QIcon("C:/Users/OUXUE/Desktop/ouxue.jpg"));
//    QMenu *editMenu = bar->addMenu("Edit");

    //使用添加Qt资源
    //使用Qt的资源 ": + 前缀名 + 文件名"
    fileMenu->setIcon(QIcon(":/images/ouxue.jpg"));

}

MainWindow::~MainWindow()
{
}

