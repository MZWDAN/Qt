#include "widget.h"
#include <teacher.h>
#include <student.h>
#include <QPushButton>
#include <QDebug>
#include <iostream>
using namespace std;

CWidget::CWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);

    //老师饿了，学生请客的连接
//    connect(zt, &Teacher::hungry, st, &Student::treat);

    //调用下课函数
//    classIsOver();

    //连接带参数的信号和槽
    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(zt, teacherSignal, st, studentSlot);

//    classIsOver();

    //点击一个下课的按钮，再触发下课
    QPushButton *m_qpBtn = new QPushButton("class over", this);
    this->resize(600, 400);

    //点击按钮，触发下课
//    connect(m_qpBtn, &QPushButton::clicked, this, &CWidget::classIsOver);

    //无参信号和槽连接
    void(Teacher::*teacherSignal_2)(void) = &Teacher::hungry;
//    void(Student::*studentSlot_2)(void) = &Student::treat;
//    connect(zt, teacherSignal_2, st, studentSlot_2);

    //信号连接信号
//    connect(m_qpBtn, &QPushButton::clicked, zt, teacherSignal_2);
//    connect(m_qpBtn, &QPushButton::clicked, zt, &QWidget::close);

    //断开信号
//    disconnect(zt, teacherSignal_2, st, studentSlot_2);

    //拓展
    //1、信号可以连接信号
    //2、一个信号可以连接多个槽函数
    //3、多个信号可以连接同一个槽函数
    //4、信号和槽函数的参数，必须类型一一对应
    //5、信号和槽的参数个数，是不是要一致？ 信号的参数个数，可以多于槽函数的参数个数

    //Qt4版本以前的信号和槽连接方式
    connect(m_qpBtn, &QPushButton::clicked, zt, teacherSignal_2);
    connect(zt, SIGNAL(hungry()), st, SLOT(treat()));
    //Qt4版本优点：参数直观，缺点：类型不做检测

    //Qt5以上，支持Qt4的版本的写法，反之不支持

    //lambda表达式
//    [=]()
//    {
//        m_qpBtn->setText("aaaa");
//    }();

    QPushButton *m_qpBtn_2 = new QPushButton(this);
    QPushButton *m_qpBtn_3 = new QPushButton(this);
    m_qpBtn_2->move(300, 100);
    m_qpBtn_3->move(100, 100);
    int m = 10;

    //mutable关键字用于修饰值传递的变量，修改的是拷贝，而不是值本身
    connect(m_qpBtn_2, &QPushButton::clicked, this, [m] ()mutable {m = 100 + 10; qDebug() << m;});
    connect(m_qpBtn_3, &QPushButton::clicked, this, [=] () {qDebug() << m;});

    int ret = []()->int{return 1000;}();
    qDebug() << ret;

    //实现点击按钮，关闭窗口
    QPushButton *m_qpBtn_4 = new QPushButton(this);
    m_qpBtn_4->setText("close");
    m_qpBtn_4->move(400, 100);
    connect(m_qpBtn_4, &QPushButton::clicked, this, [=](){
//        this->close();
        emit zt->hungry("gongbaojiding");
        st->treat();
        m_qpBtn_4->setText("aaaa");
    });

    cout<<"20230911"<<endl;
}

CWidget::~CWidget()
{
}

void CWidget::classIsOver()
{
    //下课函数，调用后，触发teacher饿了的信号
//    emit zt->hungry();
    emit zt->hungry("Hamburgous");
}
