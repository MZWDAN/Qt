#include "student.h"
#include <QDebug>

Student::Student(QWidget *parent) : QWidget(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}
