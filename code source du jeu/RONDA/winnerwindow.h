#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QMainWindow>

class WinnerWindow : public QMainWindow
{
    Q_OBJECT
public:
     WinnerWindow(bool winner  ,QWidget *parent = nullptr);



};

#endif // WINNERWINDOW_H
