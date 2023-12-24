#ifndef CARTE_H
#define CARTE_H

#include "CarteBoutton.h"
#include <QPushButton>
#include <QFrame>
#include<QString>
class Carte : public QPushButton
{

public:
    Carte(QWidget *parent = nullptr);
    int numero_carte ;
     QString image_carte;
     int numero_case_position ;
     bool used;






};

#endif // CARTE_H
