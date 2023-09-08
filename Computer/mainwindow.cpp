#include "mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QString>
#include <QGridLayout>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建显示区域
    QTextEdit *number_show_area = new QTextEdit;

    //创建水平布局，用来放置文本显示区域
    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->addWidget(number_show_area);

    //创建计算器上按钮组的显示文本
    QString buttonTexts[23] = {"7", "8", "9", "+", QString::fromLocal8Bit("清除"), QString::fromLocal8Bit("退格"),
                               "4", "5", "6", "-", QString::fromLocal8Bit("平方"), QString::fromLocal8Bit("根号"),
                               "1", "2", "3", "*", "(", ")",
                               "0", ".", "%", "/", "="};

    //创建栅格布局，用来存放按钮
    QGridLayout *gridLayout = new QGridLayout;

    int row = 0;
    int col = 0;

    //通过for循环创建按钮组
    for(int i = 0; i < 22; i++)
    {
        m_qpButton[i] = new QPushButton(buttonTexts[i], this);
        gridLayout->addWidget(m_qpButton[i], row, col);
        col++;

        if(6 == col)
        {
            col = 0;
            row++;
        }
    }

    m_qpButton[22] = new QPushButton("=", this);
    gridLayout->addWidget(m_qpButton[22], row, col, 1, 2);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(gridLayout);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);

    this->setCentralWidget(centralWidget);
    this->setWindowTitle(QString::fromLocal8Bit("计算器"));

//    connect(button, SIGNAL(clicled()), this, SLOT(digitClicked()));

}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::sltOperAdd()
{

}

void CMainWindow::sltDigitClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
                QString digit = button->text();
                // 在这里处理数字按钮的点击事件，你可以在显示屏上追加数字等等
                // 例如，你可以使用QLineEdit来显示计算结果
    }
}
