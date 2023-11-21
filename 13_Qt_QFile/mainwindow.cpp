#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击选取文件的按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"), "C:\Users\OUXUE\Desktop");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类 QTextCodeC
        QTextCodec *codec = QTextCodec::codecForName("gbk");

        //读取内容，放入到textEdit中
        //QFile默认支持的格式是 utf-8
        QFile file(path);
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll();

        //按行读
        QByteArray array;
        while (!file.atEnd()) {
            array += file.readLine();
        }


        //将读到的数据放入textEdit中
        ui->textEdit->setText(array);

        //对文件对象进行关闭
        file.close();

//        //进行写文件
//        file.open(QIODevice::Append);  //用追加的方式进行写
//        file.write("all 1000 RMB");
//        file.close();

        // QFileInfo 文件信息类
        QFileInfo info(path);
        qDebug() << "daxiao:" << info.size();
        qDebug() << "houzhuiming:" << info.suffix();
        qDebug() << "wenjianmingcheng:" << info.fileName();
        qDebug() << "wenjianlujing:" << info.filePath();
        qDebug() << "chuangjianriqi:" << info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "zuihouxiugairiqi:" << info.lastModified();



    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

