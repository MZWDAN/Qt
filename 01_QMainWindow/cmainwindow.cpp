#include "cmainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QPushButton>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    this->resize(600, 400);

    //菜单栏创建
    QMenuBar *bar = menuBar();

    //菜单栏只能最多有一个

    //创建菜单成员
    QMenu *fileMenu = bar->addMenu("File");
//    QMenu *editMenu = bar->addMenu("Edit");

    //将菜单栏放入到窗口中
    this->setMenuBar(bar);

    //创建菜单项
    fileMenu->addAction("new");
    QAction *newAction = fileMenu->addAction("new");
    //添加分隔线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("open");
    fileMenu->addAction("open");

    //工具栏  可以有多个
    //设置浮动，左右停靠
    QToolBar *toolBar = new QToolBar(this);
    toolBar->setFloatable(false);
    toolBar->setAllowedAreas(Qt::TopToolBarArea);
    //设置移动
//    toolBar->setMovable(false);
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    this->addToolBar(Qt::TopToolBarArea, toolBar);

    //工具栏中添加一些控件
    QPushButton *btn = new QPushButton("aa", this);
    toolBar->addWidget(btn);


}

CMainWindow::~CMainWindow()
{
}
