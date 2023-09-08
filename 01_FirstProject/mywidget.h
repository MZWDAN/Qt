#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include "mypushbutton.h"

class MyWidget : public QMainWindow
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
};
#endif // MYWIDGET_H
