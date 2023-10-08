#include "mainwindow.h"
#include <QDialog>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>

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
//        QDialog *m_qpDig = new QDialog(this);
//        m_qpDig->resize(200, 100);
//        m_qpDig->show();
//        m_qpDig->setAttribute(Qt::WA_DeleteOnClose); //55号属性

        //消息对话框
        //错误对话框
//        QMessageBox::critical(this, "critical", QString::fromLocal8Bit("错误"));

        //信息对话框
//        QMessageBox::information(this, "information", "信息");

        //问题对话框
        //参数1：父亲，参数2：标题，参数3：提示内容，参数4：案件类型，参数5：默认关联回车的按键
//        QMessageBox::question(this, "question", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);

//        if(QMessageBox::Save == QMessageBox::question(this, "question", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "选择的是save";
//        }
//        else
//        {
//            qDebug() << "选择的是cancel";
//        }

        //警告对话框
//        QMessageBox::warning(this, "warning", "警告");

        //其他标准对话框
        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << "r=" << color.red() << " g=" << color.green() << " b=" << color.blue();

        //文件对话框 参数1：父亲，参数2：标题，参数3：默认打开路径，参数4：过滤文件格式，返回值是选取的路径
        QString str = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\OUXUE\\Desktop", "(*.txt)");
        qDebug() << str;
    });

}

MainWindow::~MainWindow()
{
}

