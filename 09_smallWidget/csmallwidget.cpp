#include "csmallwidget.h"
#include "ui_csmallwidget.h"
#include <QSlider>
#include <QSpinBox>

CSmallWidget::CSmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSmallWidget)
{
    ui->setupUi(this);
    //QSpinBox移动，QSlider跟着移动
    void(QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

    //QSlider滑动，QSpinBox跟着改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

//设置数字
void CSmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

//获取数字
int CSmallWidget::getNum()
{
    return ui->spinBox->value();
}

CSmallWidget::~CSmallWidget()
{
    delete ui;
}
