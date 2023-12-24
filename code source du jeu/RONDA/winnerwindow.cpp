#include "winnerwindow.h"
#include <Qlabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include<QGuiApplication>
#include "LevelWindow.h"
#include "mainwindow.h"
WinnerWindow::WinnerWindow(bool winner ,QWidget *parent)
    : QMainWindow{parent}
{
    QWidget *ma_fenetre =new QWidget(this);

    QVBoxLayout *container = new QVBoxLayout (ma_fenetre);
    QHBoxLayout *boxBoutton = new QHBoxLayout(ma_fenetre);
    QPushButton *rejouer = new QPushButton("Rejouer");
    QPushButton *home = new QPushButton("Home");
    rejouer->setFixedSize(200,50);
    home->setFixedSize(200,50);

    rejouer->setStyleSheet("QPushButton {"
                             "    background-color: white;"     // Couleur d'arrière-plan blanche
                             "    color: black;"                 // Couleur du texte grise
                             "    border-radius: 15px;"         // Coins arrondis
                             "    border: none;"      // Bordure grise
                             "}"

                             // Style lorsque le bouton est survolé
                             "QPushButton:hover {"
                             "    background-color: gray;"   // Couleur d'arrière-plan gris clair au survol
                             "    color: white;"                 // Couleur du texte blanche au survol
                             "}"
                             "QPushButton:pressed {"
                             "    background-color: white;"   // Nouvelle couleur de fond en appuyant (gris)
                             "    color: black;"                 // Couleur du texte blanc en appuyant
                             "}"
                             );
    home->setStyleSheet("QPushButton {"
                          "    background-color: white;"     // Couleur d'arrière-plan blanche
                          "    color: black;"                 // Couleur du texte grise
                          "    border-radius: 15px;"         // Coins arrondis
                          "    border: none;"      // Bordure grise
                          "}"

                          // Style lorsque le bouton est survolé
                          "QPushButton:hover {"
                          "    background-color: gray;"   // Couleur d'arrière-plan gris clair au survol
                          "    color: white;"                 // Couleur du texte blanche au survol
                          "}"
                          "QPushButton:pressed {"
                          "    background-color: white;"   // Nouvelle couleur de fond en appuyant (gris)
                          "    color: black;"                 // Couleur du texte blanc en appuyant
                          "}"
                          );

    QFrame *winnerImage = new QFrame;
    winnerImage->setFixedSize(128,128);
    QLabel *text = new QLabel(ma_fenetre);
    container->setAlignment(Qt::AlignCenter);
    container->addWidget(winnerImage,0,Qt::AlignCenter);
    container->addSpacing(20);
    container->addWidget(text,0,Qt::AlignCenter);

    if(winner){
         text->setText("JEU TERMINER , Vous Avez Gagnez !!!!!");
        winnerImage->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/winner.png);");;
    }else{
         text->setText("JEU TERMINER , Vous Avez Perdue !!!!!");
        winnerImage->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/loser.png);");;


    }
    container->addSpacing(20);
    container->addLayout(boxBoutton);
    boxBoutton->addWidget(rejouer);
    boxBoutton->addSpacing(60);
    boxBoutton->addWidget(home);

    text->setStyleSheet("color:white;font-size:30px;font-weight:bold;");
    connect(home,&QPushButton::clicked,this,[this]{
        RONDA *home_page = new RONDA;
        setCentralWidget(home_page);
        this->update();
    });
    connect(rejouer,&QPushButton::clicked,this,[this]{
        LevelWindow *level_page = new LevelWindow;
        setCentralWidget(level_page);
        this->update();
    });


    setCentralWidget(ma_fenetre);



}
