#ifndef CSMALLWIDGET_H
#define CSMALLWIDGET_H

#include <QWidget>

namespace Ui {
class CSmallWidget;
}

class CSmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CSmallWidget(QWidget *parent = nullptr);
    ~CSmallWidget();

    //设置数字
    void setNum(int num);

    //获取数字
    int getNum();

private:
    Ui::CSmallWidget *ui;
};

#endif // CSMALLWIDGET_H
