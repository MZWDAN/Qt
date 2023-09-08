#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyPushButton(QWidget *parent = 0);
    ~MyPushButton();

signals:



};

#endif // MYPUSHBUTTON_H
