#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H
#include <QMainWindow>

class LevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    LevelWindow(QWidget *parent = nullptr);
    ~LevelWindow();
    void  onBackClicked();
    void  opengame_3();
    void  opengame_2();
    void opengame_1() ;




};
#endif // LEVELWINDOW_H
