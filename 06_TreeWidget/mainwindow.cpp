#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QTreeWidgetItem>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //treewidget树控件使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<QString::fromLocal8Bit("英雄")
                                    <<QString::fromLocal8Bit("英雄介绍"));

    QTreeWidgetItem *powerItem = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("力量"));
    QTreeWidgetItem *sensItem = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("敏捷"));
    QTreeWidgetItem *clevItem = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("智力"));

    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(powerItem);
    ui->treeWidget->addTopLevelItem(sensItem);
    ui->treeWidget->addTopLevelItem(clevItem);

    //追加子节点
    QStringList heroLL;
    heroLL<<QString::fromLocal8Bit("刚被猪")<<QString::fromLocal8Bit("前排坦克，能在吸收伤害的同时造成可观的范围输出");
    QTreeWidgetItem *ll = new QTreeWidgetItem(heroLL);
    powerItem->addChild(ll);

//    ui->treeWidget->addTopLevelItem(powerItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

