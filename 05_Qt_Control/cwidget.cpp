#include "cwidget.h"
#include "ui_cwidget.h"

CWidget::CWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CWidget)
{
    ui->setupUi(this);
}

CWidget::~CWidget()
{
    delete ui;
}

