#include "mainwindow.h"
#include <QDialog>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏创建
    //菜单栏只能最多有一个
    QMenuBar *menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    //创建菜单成员
    QMenu *fileMenu = menuBar->addMenu("file");
    QMenu *openMenu = menuBar->addMenu("open");
    QMenu *editMenu = menuBar->addMenu("edit");

    QAction *actionNew = fileMenu->addAction("New");
    actionNew->setText(QString::fromLocal8Bit("新建"));

    QToolBar *toolBar = new QToolBar();
    this->addToolBar(toolBar);

    toolBar->addAction(actionNew);

    //点击新建按钮，弹出一个对话框
    connect(actionNew, &QAction::triggered, [=](){
        //对话框分类
        //模态对话框（不可以对其他窗口进行操作）  和  非模态对话框（创建以后，可以对其他窗口进行操作）
        //模态创建 阻塞
//        QDialog m_qpDig(this);
//        m_qpDig.resize(50, 100);
//        m_qpDig.exec();

//        qDebug() << "模态对话框弹出了";

        //非模态对话框弹出
        QDialog *m_qpDig = new QDialog(this);
        m_qpDig->resize(200, 100);
        m_qpDig->show();
        m_qpDig->setAttribute(Qt::WA_DeleteOnClose); //55号属性
    });

}

MainWindow::~MainWindow()
{
}

