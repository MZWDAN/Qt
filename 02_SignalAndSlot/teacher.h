﻿#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>

class Teacher : public QWidget
{
    Q_OBJECT
public:
    explicit Teacher(QWidget *parent = nullptr);

signals:
    void hungry();

};

#endif // TEACHER_H
