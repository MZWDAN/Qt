#include "widget.h"
#include <teacher.h>
#include <student.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);
}

Widget::~Widget()
{
}

