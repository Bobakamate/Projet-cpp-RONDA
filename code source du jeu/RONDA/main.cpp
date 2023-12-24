#include "mainwindow.h"
#include <QApplication>
#include "winnerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     RONDA application;
    //WinnerWindow application(true);

    application.setStyleSheet("background-color:#676dde");
    application.showMaximized();
    return a.exec();
}
