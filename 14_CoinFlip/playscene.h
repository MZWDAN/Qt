#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    int levelIndex;//内部成员属性，记录所选的关卡

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

signals:
    void chooseSenceBack();

};

#endif // PLAYSCENE_H
