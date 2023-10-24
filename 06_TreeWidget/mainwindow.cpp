#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList()<<QString::fromLocal8Bit("英雄")
                                    <<QString::fromLocal8Bit("英雄介绍"));

    QTreeWidgetItem *item = new QTreeWidgetItem();
    ui->treeWidget->addTopLevelItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

