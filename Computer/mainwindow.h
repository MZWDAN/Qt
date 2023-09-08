#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

class CMainWindow : public QMainWindow  //继承的语法
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

private slots:
    void sltOperAdd();
    void sltDigitClicked();

private:
    QPushButton *m_qpButton[23];

};
#endif // MAINWINDOW_H
