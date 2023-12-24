// regle.cpp
#include "regle.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGuiApplication>
#include <QFrame>


Regle::Regle(QWidget *parent)
    : QDialog{parent}
{
    QVBoxLayout *box = new QVBoxLayout(this);
    this->setStyleSheet("background-color:#676dde");
    QLabel *regle = new QLabel("Regle du Jeu");
    regle->setStyleSheet("color:white;font-family:bold;font-size:20px");
    box->addWidget(regle, 0, Qt::AlignCenter);
    box->addSpacing(20);
    box->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    QLabel *suite_regle = new QLabel;
    box->addWidget(suite_regle, 0, Qt::AlignCenter);


    suite_regle->setStyleSheet("color:white;font-size:18px");
    QString rondaText = "RONDA est un jeu de cartes marocain qui utilise une liste de 40 cartes. "
                        "Au début de la partie, 3 cartes sont distribuées à l'utilisateur et à l'IA, "
                        "tandis que 4 cartes sont déposées au milieu de la table. L'objectif du jeu est "
                        "de collecter toutes les cartes ayant le même numéro ou des numéros consécutifs à "
                        "l'une de nos cartes.\n\n"
                        "Pour ce faire, il suffit de cliquer sur la carte qui a un numéro appartenant à la "
                        "liste des numéros des cartes sur la table de jeu. Cette carte et toutes les cartes de "
                        "numéros consécutifs seront sélectionnées et comptabilisées en points (chaque carte vaut "
                        "1 point).\n\n"
                        "Le gagnant du jeu est celui des joueurs qui a le plus de points à la fin de la partie.";
    suite_regle->setText(rondaText);

    suite_regle->setText(rondaText);
    suite_regle->setWordWrap(true);
    setLayout(box);
}
