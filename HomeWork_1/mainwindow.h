#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

    QPushButton *qp_Btn;
    QWidget *my_widget;

    int m_is_open = 0;

    void ToggleWidgetState();
};
#endif // MAINWINDOW_H
