#include "cwidget.h"
#include "ui_cwidget.h"
#include <QDebug>
#include <QCheckBox>
#include <QListWidget>
#include <QListWidgetItem>

CWidget::CWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CWidget)
{
    ui->setupUi(this);

    //设置单选按钮 男默认选中
    ui->rBtnMan->setChecked(true);

    //选中女后，打印信息
    connect(ui->rBtnWoman, &QRadioButton::clicked, [=](){
        qDebug() << QString::fromLocal8Bit("选中女了");
    });

    //多选按钮  2是选中，0是未选中，1是半选
    connect(ui->checkBox, &QCheckBox::stateChanged, [](int state){
                qDebug() << state;
            });
    //利用ListWidget写诗
    QListWidgetItem *item = new QListWidgetItem(QString::fromLocal8Bit("锄禾日当午"));
    item->setTextAlignment(Qt::AlignHCenter);
    ui->listWidget->addItem(item);

    //QStringList QList<QString>
    QStringList list;
    list <<QString::fromLocal8Bit("锄禾日当午")
         <<QString::fromLocal8Bit("汗滴禾下土")
         <<QString::fromLocal8Bit("谁知盘中餐")
         <<QString::fromLocal8Bit("粒粒皆辛苦");
    ui->listWidget->addItems(list);


}

CWidget::~CWidget()
{
    delete ui;
}

