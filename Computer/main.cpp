#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow *w = new CMainWindow;
    w->show();
    return a.exec();
}
