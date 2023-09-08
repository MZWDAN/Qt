#include "student.h"
#include <QDebug>

Student::Student(QWidget *parent) : QWidget(parent)
{

}

void Student::treat()
{
    qDebug() << QString::fromLocal8Bit("请老师吃饭");
}

void Student::treat(QString foodName)
{
    qDebug() << QString::fromLocal8Bit("请老师吃") << foodName.toUtf8().data();
}
