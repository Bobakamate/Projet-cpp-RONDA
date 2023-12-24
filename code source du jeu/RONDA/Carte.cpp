#include "Carte.h"

Carte::Carte(QWidget *parent )  : QPushButton(parent)

{
    this->numero_carte = -1;

    this->image_carte = QString("");

    this->numero_case_position = -1;
    this->used = false;

}



