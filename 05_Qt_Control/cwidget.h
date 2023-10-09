#ifndef CWIDGET_H
#define CWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CWidget; }
QT_END_NAMESPACE

class CWidget : public QWidget
{
    Q_OBJECT

public:
    CWidget(QWidget *parent = nullptr);
    ~CWidget();

private:
    Ui::CWidget *ui;
};
#endif // CWIDGET_H
