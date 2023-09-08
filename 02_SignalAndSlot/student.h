#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

class Student : public QWidget
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = nullptr);

signals:

private slots:
    void treat();

};

#endif // STUDENT_H
