#include<QMainWindow>
#include"LevelWindow.h"
#include "mainwindow.h"
#include"gamewindow.h"
#include<QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QAction>
#include<QToolBar>
#include<QFrame>
#include <QPushButton>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include "regle.h"

LevelWindow::LevelWindow(QWidget *parent) :QMainWindow(parent)
{
    QWidget *ma_fenetre = new QWidget(this);
    QHBoxLayout *container = new QHBoxLayout(ma_fenetre);//boute
    QLabel *mon_text = new QLabel("WELCOME");


    QVBoxLayout *container_verticale_1 = new QVBoxLayout(ma_fenetre);//facile
    QVBoxLayout *container_verticale_2 = new QVBoxLayout(ma_fenetre);//moyen
    QVBoxLayout *container_verticale_3 = new QVBoxLayout(ma_fenetre);// difficile
    QLabel *text_1 = new QLabel("Facile") ;
    QLabel *text_2 = new QLabel("Moyen") ;
    QLabel *text_3 = new QLabel("Difficile") ;
    QFrame *img_1 = new QFrame;
    QFrame *img_2 = new QFrame;
    QFrame *img_3 = new QFrame;
    img_2->setFixedSize(100,100);
    img_3->setFixedSize(100,100);
    img_1->setFixedSize(100,100);
    QPushButton *boutton_1  = new QPushButton("joueur");
    boutton_1->setFixedSize(200,50);
    QPushButton *boutton_2  = new QPushButton("joueur");
    boutton_2->setFixedSize(200,50);
    QPushButton *boutton_3  = new QPushButton("joueur");
    boutton_3->setFixedSize(200,50);
    boutton_1->setStyleSheet("QPushButton {"
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
    boutton_3->setStyleSheet("QPushButton {"
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
    boutton_2->setStyleSheet("QPushButton {"
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

     container_verticale_1->addWidget(img_1,0,Qt::AlignCenter);
     container_verticale_1->addWidget(text_1,0,Qt::AlignCenter);
     container_verticale_1->addSpacing(30);
     container_verticale_1->addWidget(boutton_1,0,Qt::AlignCenter);
     //deuxiemme contenur injectionn des donne
     container_verticale_2->addWidget(img_2,0,Qt::AlignCenter);
     container_verticale_2->addWidget(text_2,0,Qt::AlignCenter);
     container_verticale_2->addSpacing(30);
     container_verticale_2->addWidget(boutton_2,0,Qt::AlignCenter);
     //troisieme contenair injection des donne
     container_verticale_3->addWidget(img_3,0,Qt::AlignCenter);
     container_verticale_3->addWidget(text_3,0,Qt::AlignCenter);
     container_verticale_3->addSpacing(30);
     container_verticale_3->addWidget(boutton_3,0,Qt::AlignCenter);


     //effectuer un alignement des contenaur vertical
     container_verticale_2->setAlignment( Qt:: AlignCenter);
     container_verticale_1->setAlignment(Qt::AlignCenter);
     container_verticale_3->setAlignment(Qt::AlignCenter);

     QString IA_image1 = QGuiApplication::applicationDirPath() + "/assets/images/easy_level_image.png";

     QString IA_image2 = QGuiApplication::applicationDirPath() + "/assets/images/medium_level_image.png";

     QString IA_image3 = QGuiApplication::applicationDirPath() + "/assets/images/hard_level_image.png";
//chargement des image en utilisant le css
     img_1->setStyleSheet("background-image: url("+IA_image1+"); background-size: cover;");
      img_2->setStyleSheet("background-image: url("+IA_image2+");background-size: 50%;");
       img_3->setStyleSheet("background-image: url("+IA_image3+");background-size: 50%;");


    mon_text->setStyleSheet("QLabel{"
                             "font-weight: bold;"
                            "color: white;"
                            "font-size:30px"
                            "}"
                            );
    container->addLayout(container_verticale_1);
    container->addSpacing(40);
     container->addLayout(container_verticale_2);
    container->addSpacing(40);
     container->addLayout(container_verticale_3);

    container->setAlignment(Qt::AlignCenter);
    QPushButton *mon_boutton = new QPushButton("boutton retour ");
    mon_boutton->setFixedSize(200,50);
    mon_boutton->setStyleSheet("QPushButton {"
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

    //modification de la couleur des text
    text_1->setStyleSheet("color:white;font-size:20px;font-weight:bold");
     text_2->setStyleSheet("color:white;font-size:20px;font-weight:bold");
     text_3->setStyleSheet("color:white;font-size:20px;font-weight:bold");
    connect(mon_boutton,&QPushButton::clicked,this, &LevelWindow::onBackClicked);
    //ajout des espacement entre les widget du layout parent


    connect(boutton_1,&QPushButton::clicked,this, &LevelWindow::opengame_1);
    connect(boutton_2,&QPushButton::clicked,this, &LevelWindow::opengame_2);
    connect(boutton_3,&QPushButton::clicked,this, &LevelWindow::opengame_3);

    QPushButton *rule_icon = new QPushButton(ma_fenetre);
    rule_icon->setFixedSize(32,32);
    rule_icon->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/book.png"+");border:none;outline:none");
    QLabel*regle = new QLabel(ma_fenetre);
    regle->setText("Regles");
    regle->setStyleSheet("color:white;font-size:20px;font-family:bold");
    QScreen *ecran = QGuiApplication::primaryScreen();
    QRect cadre = ecran->geometry();
    int position = cadre.width() -100;
  regle  ->move(QPoint(position,40));
    rule_icon->move(QPoint(-40+regle->x(),40));
    connect(rule_icon,&QPushButton::clicked,this,[this]{
        Regle *page = new Regle;
        page->show();

    }
            );

    QPushButton *back_icon = new QPushButton(ma_fenetre);
    back_icon->setFixedSize(32,32);
    back_icon->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/annuler.png"+");border:none;outline:none");

    back_icon->move(QPoint(40,40));

    connect(back_icon,&QPushButton::clicked,this,[this]{
        RONDA *page = new RONDA;
        setCentralWidget(page);
        this->update();
    }
            );

    setCentralWidget(ma_fenetre);

}
void LevelWindow::onBackClicked(){
    QString IA_image = QGuiApplication::applicationDirPath() + "/assets/images/easy_level_image_40.png";

     GameWindow *game_page = new GameWindow(0,IA_image);

    setCentralWidget(game_page);
    this->update();

}
void LevelWindow::opengame_1( ){

    QString IA_image = QGuiApplication::applicationDirPath() + "/assets/images/easy_level_image_40.png";
    GameWindow *game_page = new GameWindow(0,IA_image);

    setCentralWidget(game_page);
    this->update();

}
void LevelWindow::opengame_2( ){
    QString IA_image = QGuiApplication::applicationDirPath() + "/assets/images/medium_level_image_40.png";
    GameWindow *game_page = new GameWindow(1,IA_image);

    setCentralWidget(game_page);
    this->update();

}
void LevelWindow::opengame_3( ){


    QString IA_image = QGuiApplication::applicationDirPath() + "/assets/images/hard_level_image_40.png";
    GameWindow *game_page = new GameWindow(2,IA_image);

    setCentralWidget(game_page);
    this->update();

}
LevelWindow :: ~LevelWindow(){

}
