#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

class Student : public QWidget
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = nullptr);

signals:

public slots:
    void treat();
    void treat(QString foodName);

};

#endif // STUDENT_H
