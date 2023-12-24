#ifndef RONDA_H
#define RONDA_H

#include <QMainWindow>

class RONDA : public QMainWindow
{
    Q_OBJECT

public:
    RONDA(QWidget *parent = nullptr);//constructeur
    ~RONDA();//destructeur
    void  Button_cliked();
    void Play_Music();

};
#endif // RONDA_H
