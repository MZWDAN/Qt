#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

class MainWindow : public QMainWindow  //继承的语法
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void sltOperAdd();
    void sltDigitClicked();

private:
    QPushButton *m_qpButton[23];

};
#endif // MAINWINDOW_H
