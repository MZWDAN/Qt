#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;

    //配置选择关卡场景
    //设置固定大小
    this->setFixedSize(320, 588);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle(QString::fromLocal8Bit("翻金币场景"));

    //创建菜单栏
    QMenuBar *bar =  menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu *menu = bar->addMenu(QString::fromLocal8Bit("开始"));

    QAction *quit = new QAction(QString::fromLocal8Bit("退出"));
    menu->addAction(quit);

    //退出按钮实现
    connect(quit, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &QPushButton::clicked, [=](){
        qDebug() << QString::fromLocal8Bit("翻金币场景中，点击了返回按钮");
        //延时返回
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSenceBack();
        });

    });

    //显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily(QString::fromLocal8Bit("华文新魏"));
    font.setPointSize(20);

    QString str = QString::fromLocal8Bit("Level:%1").arg(this->levelIndex);
    label->setText(str);
    //设置大小并且移动
//    label->setFixedSize();
//    label->move(100, 500);
    //另一种设置大小并且移动的方法
    label->setGeometry(QRect(30, this->height() - 50, 120, 50));
    label->setFont(font);

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i = 0; i < 4;i++)
    {
        for(int j = 0; j<4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //显示金币背景图案
    for(int i = 0;i<4;i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //绘制背景图片
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel *label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i*50, 200+j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                //显示金币
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*50, 204+j*50);
//          //给金币的属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];  //1是正面，0是反面

            //将金币放入到金币的二维数组里，以便于后期的维护
            coinBtn[i][j] = coin;

            //点击金币进行翻转
            connect(coin, &MyCoin::clicked, [=](){
                coin->changeFlag();
                this->gameArray[i][j] == this->gameArray[i][j] == 0 ? 1: 0;// 三目运算符

                QTimer::singleShot(300, this, [=](){
                    //翻转周围的硬币
                    if(coin->posX+1 <= 3)//周围的右侧金币翻转的条件  延时翻转
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] == this->gameArray[coin->posX+1][coin->posY] == 0 ? 1: 0;// 三目运算符
                    }

                    //周围的左侧硬币翻转的条件
                    if(coin->posX-1 >= 0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] == this->gameArray[coin->posX-1][coin->posY] == 0 ? 1: 0;// 三目运算符
                    }

                    //周围的上方硬币翻转的条件
                    if(coin->posY-1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] == this->gameArray[coin->posX][coin->posY-1] == 0 ? 1: 0;// 三目运算符
                    }

                    //周围的下方硬币翻转的条件
                    if(coin->posY+1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] == this->gameArray[coin->posX][coin->posY+1] == 0 ? 1: 0;// 三目运算符
                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    //创建背景
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    //画背景上的图标
    pixmap.load(":/res/Title.png");
    pixmap = pixmap.scaled(QSize(pixmap.width() * 0.5, pixmap.height() * 0.5));
    painter.drawPixmap(10, 30, pixmap);
}
