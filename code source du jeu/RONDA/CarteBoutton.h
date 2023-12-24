#ifndef CARTEBOUTTON_H
#define CARTEBOUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QString>

class CarteBoutton : public QPushButton
{
    Q_OBJECT

public:
    CarteBoutton(QWidget *parent = nullptr );
    int numero =0;
   QString  image = "";
   bool est_jouer = false;


};

#endif // CARTEBOUTTON_H
