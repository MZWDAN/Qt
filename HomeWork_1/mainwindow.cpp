#include "mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QObject>
#include <iostream>
using namespace std;

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //新建一个按钮
    qp_Btn = new QPushButton(this);
    qp_Btn->setText("open");

    //新建一个Widget
    my_widget = new QWidget;

    connect(qp_Btn, &QPushButton::clicked, this, &CMainWindow::ToggleWidgetState);

}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::ToggleWidgetState()
{
    if(!m_is_open)
    {
        my_widget->show();
        qp_Btn->setText("open");
    }
    else
    {
        my_widget->close();
        qp_Btn->setText("close");
    }

    m_is_open = !m_is_open;
}
