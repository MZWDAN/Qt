#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //重写定时器事件
    void timerEvent(QTimerEvent *e);

    int id1; //定时器1的唯一标识
    int id2; //定时器2的唯一标识

    //重写事件过滤器的事件
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
