#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);

    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QString::fromLocal8Bit("姓名")<<
                                               QString::fromLocal8Bit("性别")<<
                                               QString::fromLocal8Bit("年龄"));
    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("亚瑟")));

    //for循环设置表格中的内容
    QStringList nameList;
    nameList<<QString::fromLocal8Bit("亚瑟")
            <<QString::fromLocal8Bit("妲己")
            <<QString::fromLocal8Bit("安琪拉")
            <<QString::fromLocal8Bit("赵云")
            <<QString::fromLocal8Bit("孙悟空");

    QStringList sexList;
    sexList <<QString::fromLocal8Bit("男")
            <<QString::fromLocal8Bit("女")
            <<QString::fromLocal8Bit("女")
            <<QString::fromLocal8Bit("男")
            <<QString::fromLocal8Bit("中立");

//    QStringList ageList;
//    ageList <<QString::fromLocal8Bit("20")
//            <<QString::fromLocal8Bit("21")
//            <<QString::fromLocal8Bit("22")
//            <<QString::fromLocal8Bit("23")
//            <<QString::fromLocal8Bit("24");

    for(int i=0; i<5; i++)
    {
        int column = 0;
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(QString::number(i+18)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

