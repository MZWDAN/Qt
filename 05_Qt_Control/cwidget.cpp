#include "cwidget.h"
#include "ui_cwidget.h"
#include <QDebug>
#include <QCheckBox>

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
}

CWidget::~CWidget()
{
    delete ui;
}

