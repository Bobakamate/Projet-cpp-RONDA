#include "gamewindow.h"
#include "LevelWindow.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include<QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include<QScreen>
#include<QRect>
#include<QGuiApplication>
#include<QCoreApplication>
#include<vector>
#include "Carte.h"
#include "User.h"
#include <algorithm>
#include <random>
#include "winnerwindow.h"
#include <cstdlib>
#include <ctime>


GameWindow::GameWindow(int difficulte,QString IA_image, QWidget *parent)
    : QMainWindow(parent)
{
     ma_fenetre = new QWidget(this);


    QLabel *mon_text = new QLabel("");


    QVBoxLayout *container = new QVBoxLayout(ma_fenetre);
    QHBoxLayout *top_container = new QHBoxLayout(ma_fenetre);
    QHBoxLayout *medium_container = new QHBoxLayout(ma_fenetre);
    QHBoxLayout *bottom_container = new QHBoxLayout(ma_fenetre);
    QHBoxLayout *top_container_section_2 = new QHBoxLayout;
    QHBoxLayout *top_container_section_3 = new QHBoxLayout;
    QHBoxLayout *bottom_container_section_2 = new QHBoxLayout;
    QHBoxLayout *bottom_container_section_3 = new QHBoxLayout;
    QWidget *medium_bg = new QWidget(ma_fenetre);
   medium_bg ->setStyleSheet("background-color:gray;border-radius: 15px;");

    QVBoxLayout *medium_bg_container = new  QVBoxLayout(medium_bg);
    QHBoxLayout *medium_card_section_1 = new QHBoxLayout;
    QHBoxLayout *medium_card_section_2 = new QHBoxLayout;
    medium_card_section_1->setAlignment(Qt::AlignCenter);
    medium_card_section_2->setAlignment(Qt::AlignCenter);
    medium_bg_container->addLayout(medium_card_section_1);
    medium_bg_container->addLayout(medium_card_section_2);
     QWidget *boite_medium = new QWidget(ma_fenetre);
    for(int i = 0 ; i<8;i++){
         medium_carte_controlleur.push_back(false);
     }

    QVBoxLayout *medium_score_container = new QVBoxLayout(boite_medium);
     //definition des differents widget

    QScreen *ecran = QGuiApplication::primaryScreen();
    QRect cadre = ecran->geometry();
    ma_fenetre->setFixedSize(cadre.width() ,cadre.height() -100);
    ImagePathBack = QCoreApplication::applicationDirPath() +"/assets/images/cards/back.png";
    //definition de la liste de carte


 // declaratioon des different element de liste de carte
    make_carte(liste_40_cartes);




       // Assurez-vous d'appeler show() après avoir défini les flags.



     card_img_1_ia_widget = new QFrame ;
     card_img_2_ia_widget = new QFrame ;
    card_img_3_ia_widget = new QFrame ;
     card_img_1_user_widget = new QFrame ;
     card_img_2_user_widget = new QFrame ;
     card_img_3_user_widget = new QFrame ;

     medium_card_1_widget  = new QFrame ;
     medium_card_2_widget  = new QFrame ;
     medium_card_3_widget   = new QFrame ;
     medium_card_4_widget  = new QFrame ;
     medium_card_5_widget  = new QFrame ;
     medium_card_6_widget  = new QFrame ;
     medium_card_7_widget  = new QFrame ;
     medium_card_8_widget  = new QFrame ;


    //modification de la taille des widget pour correspondre a la taille des different element
    card_img_1_ia_widget->setFixedSize(90,135);
    card_img_2_ia_widget->setFixedSize(90,135);
    card_img_3_ia_widget->setFixedSize(90,135);
    card_img_1_user_widget->setFixedSize(90,135);
    card_img_2_user_widget->setFixedSize(90,135);
    card_img_3_user_widget->setFixedSize(90,135);





    //les widget carte  medium definition



      //definition de la taille des diferent widget
      medium_card_1_widget->setFixedSize(90,135);
      medium_card_2_widget->setFixedSize(90,135);
      medium_card_3_widget->setFixedSize(90,135);
      medium_card_4_widget->setFixedSize(90,135);
      medium_card_5_widget->setFixedSize(90,135);
      medium_card_6_widget->setFixedSize(90,135);
      medium_card_7_widget->setFixedSize(90,135);
      medium_card_8_widget->setFixedSize(90,135);

      //definition de la green arriere plan



       medium_bank = new QFrame(ma_fenetre);
      carte_restant = new QLabel("30");

      carte_restant->setStyleSheet("color:white;font-size:20px;font-weight:bold");
           medium_score_container->addWidget(carte_restant,0,Qt::AlignCenter);
         medium_score_container->addSpacing(15);
         medium_score_container->addWidget(medium_bank,0,Qt::AlignTop);;



      medium_bank->setStyleSheet("background-image: url("+ImagePathBack+"); outline:none ;border:none"); // Applique l'image en arrière-plan du QFrame

     //definition des different element de widget





    //definition des carte


    //ajout des widget dans les deux section
    medium_card_section_1->addWidget(medium_card_1_widget,0,Qt::AlignCenter);
    medium_card_section_1->addWidget(medium_card_2_widget,0,Qt::AlignCenter);
    medium_card_section_1->addWidget(medium_card_3_widget,0,Qt::AlignCenter);
    medium_card_section_1->addWidget(medium_card_4_widget,0,Qt::AlignCenter);
    //deuxiemme section
    medium_card_section_2->addWidget(medium_card_5_widget,0,Qt::AlignCenter);
    medium_card_section_2->addWidget(medium_card_6_widget,0,Qt::AlignCenter);
    medium_card_section_2->addWidget(medium_card_7_widget,0,Qt::AlignCenter);
    medium_card_section_2->addWidget(medium_card_8_widget,0,Qt::AlignCenter);



    //deffinition des image de user et de  l ia
    QFrame *user_image = new QFrame(ma_fenetre);
    QFrame *ia_image = new QFrame;
    QLabel * user_name = new QLabel("User");
    QLabel *ia_name = new QLabel ("IA");
    user_name-> setStyleSheet("color:white;font-size:20px;font-weight:bold");
    ia_name->setStyleSheet("color:white;font-size:20px;font-weight:bold");
    user_image->setFixedSize(40,40);
    ia_image->setFixedSize(40,40);
    user_image->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/programmer_40.png);");
   ia_image ->setStyleSheet("background-image:url("+IA_image+");");
   //deffinion de la partie timer
   timer_tour = new QLabel("Tour de :\nUser");
   QFrame *timer_image = new QFrame;
    timer_tour-> setStyleSheet("color:white;font-size:20px;font-weight:bold");
    timer_image->setStyleSheet("background-image:url("+QGuiApplication::applicationDirPath()+"/assets/images/chronometre_40.png);");
    timer_image->setFixedSize(40,40);



    QHBoxLayout *medium_container_section_3 = new QHBoxLayout;
    //deffinitionn des score ia et utilisateur
     ia_score = new QLabel("Score : 0");
      user_score = new QLabel("Score : 0");
    ia_score->setStyleSheet("color:white;font-size:20px;font-weight:bold");
    user_score->setStyleSheet("color:white;font-size:20px;font-weight:bold");
    // definition des logo


    medium_bank->setFixedSize(90,135);;




    //connecteur de click pour effectuer les animatio

    //ajout des different section top
    top_container->addWidget(ia_score, 1, Qt::AlignCenter);
    top_container->addLayout(top_container_section_2, 2);
    top_container->addLayout(top_container_section_3, 1);
    top_container_section_2->setAlignment(Qt::AlignCenter);
    top_container_section_3->setAlignment(Qt::AlignCenter);
     // on injecte les carte
     top_container_section_2->addWidget(card_img_1_ia_widget, 0, Qt::AlignCenter);
     top_container_section_2->addWidget(card_img_2_ia_widget, 0, Qt::AlignCenter);
     top_container_section_2->addWidget(card_img_3_ia_widget, 0, Qt::AlignCenter);
     //on ajoute les image a la top et bottom section
     top_container_section_3->addWidget(ia_image,0,Qt::AlignCenter);
     top_container_section_3->addWidget(ia_name,0,Qt::AlignCenter);
     //bottom
     bottom_container_section_3->addWidget(user_image,0,Qt::AlignCenter);
     bottom_container_section_3->addWidget(user_name,0,Qt::AlignCenter);
     //ajout a la section medium
     medium_container_section_3->addWidget(timer_tour,0,Qt::AlignCenter);
     medium_container_section_3->addWidget(timer_image,0,Qt::AlignCenter);

     //ajout dans la medium section

     medium_container->addWidget(boite_medium, 1, Qt::AlignCenter);
     medium_container->addWidget(medium_bg, 2);
     medium_container->addLayout(medium_container_section_3, 1);
     medium_container_section_3->setAlignment(Qt::AlignCenter);

     //ajout des different elment de l asection bottom
     bottom_container->addWidget(user_score, 1, Qt::AlignCenter);
     bottom_container->addLayout(bottom_container_section_2, 2);
     bottom_container->addLayout(bottom_container_section_3, 1);
     bottom_container_section_2->setAlignment(Qt::AlignCenter);
     bottom_container_section_3->setAlignment(Qt::AlignCenter);


    // add image user to conatian bottom

    bottom_container_section_2->addWidget(card_img_1_user_widget, 0, Qt::AlignCenter);
    bottom_container_section_2->addWidget(card_img_2_user_widget, 0, Qt::AlignCenter);
    bottom_container_section_2->addWidget(card_img_3_user_widget, 0, Qt::AlignCenter);


    container->addLayout(top_container, 1);
    container->addLayout(medium_container, 2);
    container->addLayout(bottom_container, 1);
    container->setAlignment(Qt::AlignCenter);


    //cacher les carte
    //connection des boutton



    this->difficulte = difficulte;


    //definitni=tion des different liste

     mon_text->setStyleSheet("color:white; font-size:30px; font-weight:bold");


    //animation permetant de calculerl aposition de tout les widget


    QWidget *fictive_widget = new QWidget ;
    fictive_widget->setFixedSize(1,1);
    QPropertyAnimation *animation = new  QPropertyAnimation(fictive_widget,"pos");
    animation->setEndValue(QPoint(0,0));
    animation->setDuration(1);
    animation->start();

    connect(animation,&QPropertyAnimation::finished, this, [this]{
            get_point_values();
            distrube_user_card_animation(true, utilisateur);
            distrube_user_card_animation(false, IA);


        QWidget *fictive_widget = new QWidget ;
        fictive_widget->setFixedSize(1,1);
        QPropertyAnimation *animation = new  QPropertyAnimation(fictive_widget,"pos");
        animation->setEndValue(QPoint(0,0));
        animation->setDuration(1000);
        animation->start();
         connect(animation,&QPropertyAnimation::finished, this, [this]{
        cards_distribution_start();
        });
        qDebug()<<"passege reussie load data page";
            qDebug()<<"numero de carte  1"<< utilisateur.carte_1->image_carte;




    });


     /*set_green();*/



    setCentralWidget(ma_fenetre);
}
void GameWindow::set_green(){
    //couleur temporaire verte
    card_img_1_user_widget->setStyleSheet("background-color:green");
    card_img_3_user_widget->setStyleSheet("background-color:green");
    card_img_2_user_widget->setStyleSheet("background-color:green");


    card_img_1_ia_widget->setStyleSheet("background-color:green");
    card_img_3_ia_widget->setStyleSheet("background-color:green");
    card_img_2_ia_widget->setStyleSheet("background-color:green");

    medium_card_1_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_2_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_3_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_4_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_5_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_6_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_7_widget->setStyleSheet("background-color:green;border-radius: 0;");
    medium_card_8_widget->setStyleSheet("background-color:green;border-radius: 0;");
}
void GameWindow:: get_point_values( ){
    /*
   Fonction void get_point_values() : cette fonction sert à récupérer la liste des positions des widgets vides placés à l'écran pour faire les animations.
   Cette fonction initialise aussi la variable user_turn à true.
*/
    card_img_1_ia_position = card_img_1_ia_widget->pos();
    card_img_2_ia_position  = card_img_2_ia_widget->pos();
    card_img_3_ia_position = card_img_3_ia_widget->pos();
    card_img_1_user_position = card_img_1_user_widget->pos();
    card_img_2_user_position = card_img_2_user_widget->pos();
    card_img_3_user_position = card_img_3_user_widget->pos();
    medium_card_1_position = medium_card_1_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);
     medium_card_2_position = medium_card_2_widget->mapToGlobal(QPoint(0, 0))  + QPoint(0,-20);;
      medium_card_3_position =medium_card_3_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);;
      medium_card_4_position = medium_card_4_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);;
      medium_card_5_position = medium_card_5_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);;
      medium_card_6_position =  medium_card_6_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);
      medium_card_7_position= medium_card_7_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);;
      medium_card_8_position=medium_card_8_widget->mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);;
    medium_bank_position  = medium_bank-> mapToGlobal(QPoint(0, 0)) + QPoint(0,-20);
      is_user_turn= false;
    carte_ia_facile= 0;
      compteur_de_tour = 0;
    user_score_number = 0;
      ia_score_number = 0 ;


}

void  GameWindow::make_carte (std::vector<Carte*> &liste_cartes){
    /*
   Fonction make_carte(std::vector<Carte*> &liste_cartes) : cette fonction crée la liste des 40 cartes du jeu
   et met à jour les données dans la variable liste_40_cartes.
*/

    // Création d'une liste de cartes


    // Numéros de cartes spécifiques
    std::vector<int> numeros_specifiques = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};

    for (int i = 1, j = 0; i <= 40; ++i,j++) {
        Carte *carte = new Carte(ma_fenetre);
        carte->numero_carte = numeros_specifiques[j];
        if(j == 9){
            j = -1;
        }
        std::string numero_string = ((i-1) < 10) ? "0" : "";
        carte->image_carte = QCoreApplication::applicationDirPath() + "/assets/images/cards/" + QString::fromStdString(numero_string + std::to_string(i-1)) + ".png";

        carte->setStyleSheet("background-image:url(" +carte->image_carte+ ");outline :none ;border:0px;");

        carte->setFixedSize(90,135);
        carte->move(QPoint(-200,0));


        liste_cartes.push_back(carte);
        played_liste.push_back(carte);
    }

    for(int i = 0 ; i<liste_cartes.size();i++){
        qDebug()<<liste_cartes[i]->image_carte;
         qDebug()<<liste_cartes[i]->numero_carte;

    }
    melanger_carte(liste_cartes);




}
void GameWindow ::melanger_carte(std::vector<Carte*>& cartes) {
    /*
   Fonction void melanger_carte(std::vector<Carte*>& cartes) :
   cette fonction mélange la liste des 40 cartes.
*/

    std::random_device rd;
    std::default_random_engine engine(rd());

    std::shuffle(cartes.begin(), cartes.end(), engine);
}
void GameWindow:: distrube_user_card_animation(bool is_user, User &utilisateur_){
 get_carte(utilisateur_);
    /*
   Fonction void distribute_user_card_animation(bool is_user, User &utilisateur);
   cette fonction distribue 3 cartes à l'utilisateur en sélectionnant IA (false) ou player (true).
*/


 if(is_user){

         utilisateur.carte_1 ->raise();
         utilisateur.carte_2 ->raise();
         utilisateur.carte_3 ->raise();
        QPropertyAnimation *card_img_1_user_animation =new QPropertyAnimation(utilisateur.carte_1,"pos");

        card_img_1_user_animation->setDuration(1500);
        card_img_1_user_animation->setStartValue(medium_bank_position);
         card_img_1_user_animation->setEndValue(card_img_1_user_position);
        card_img_1_user_animation->start();

        QPropertyAnimation *card_img_2_user_animation =new QPropertyAnimation(utilisateur.carte_2,"pos");
         card_img_2_user_animation->setDuration(1100);

        card_img_2_user_animation->setStartValue(medium_bank_position);
         card_img_2_user_animation->setEndValue(card_img_2_user_position);
        card_img_2_user_animation->start();

        QPropertyAnimation *card_img_3_user_animation =new QPropertyAnimation(utilisateur.carte_3,"pos");
         card_img_3_user_animation->setDuration(1000);
        card_img_3_user_animation->setStartValue(medium_bank_position);
         card_img_3_user_animation->setEndValue(card_img_3_user_position);
        card_img_3_user_animation->start();
        connection_click_utilisateur ();


    }else{
         carte_list = {IA.carte_1, IA.carte_2, IA.carte_3};
        IA.carte_1 ->setStyleSheet("background-image:url("+ImagePathBack+");outline:none;border:0px");
        IA.carte_2 ->setStyleSheet("background-image:url("+ImagePathBack+");outline:none;border:0px");
        IA.carte_3 ->setStyleSheet("background-image:url("+ImagePathBack+");outline:none;border:0px");
        IA.carte_2 ->raise();
        IA.carte_3 ->raise();

        QPropertyAnimation *card_img_1_ia_animation = new QPropertyAnimation(IA.carte_1,"pos");
        IA.carte_1 ->raise();
        IA.carte_2 ->raise();
        IA.carte_3 ->raise();


        card_img_1_ia_animation->setDuration(1500);
        card_img_1_ia_animation->setStartValue(medium_bank_position);
         card_img_1_ia_animation->setEndValue(card_img_1_ia_position);
        card_img_1_ia_animation->start();

        QPropertyAnimation *card_img_2_ia_animation = new QPropertyAnimation(IA.carte_2,"pos");

        card_img_2_ia_animation->setDuration(1100);
        card_img_2_ia_animation->setStartValue(medium_bank_position);
         card_img_2_ia_animation->setEndValue(card_img_2_ia_position);
        card_img_2_ia_animation->start();

        QPropertyAnimation *card_img_3_ia_animation = new QPropertyAnimation(IA.carte_3,"pos");

        card_img_3_ia_animation->setDuration(1000);
        card_img_3_ia_animation->setStartValue(medium_bank_position);
         card_img_3_ia_animation->setEndValue(card_img_3_ia_position);
        card_img_3_ia_animation->start();
    }

}

void GameWindow:: cards_distribution_start(){
    /*
   Fonction void cards_distribution_start() : cette fonction sert à effectuer la première distribution de cartes lors du jeu.
   Cette fonction distribue 10 cartes : 3 cartes à l'utilisateur, 3 cartes à l'IA et 4 cartes au milieu du jeu.
*/

    int taille = liste_40_cartes.size();
     liste_8_cartes_medium.push_back(liste_40_cartes[taille-1]);
    liste_8_cartes_medium.push_back(liste_40_cartes[taille-2]);
    liste_8_cartes_medium.push_back(liste_40_cartes[taille-3]);
    liste_8_cartes_medium.push_back(liste_40_cartes[taille-4]);

    int i = 0 ;
    while ( i< 4){
        liste_40_cartes.pop_back();
        i++;
    }

    QPropertyAnimation *medium_card_1_animation = new QPropertyAnimation(liste_8_cartes_medium[0],"pos");
    liste_8_cartes_medium[0]->numero_case_position = 1;
    controlleur_medium(1,true);
     medium_card_1_animation->setDuration(1500);
    medium_card_1_animation->setStartValue(medium_bank_position);
    medium_card_1_animation->setEndValue(medium_card_2_position);
    medium_card_1_animation->start();


    QPropertyAnimation *medium_card_2_animation = new QPropertyAnimation(liste_8_cartes_medium[1],"pos");
     medium_card_2_animation->setDuration(1300);
    liste_8_cartes_medium[1]->numero_case_position = 2;
    controlleur_medium(2,true);


    medium_card_2_animation->setStartValue(medium_bank_position);
    medium_card_2_animation->setEndValue(medium_card_3_position);
    medium_card_2_animation->start();

    QPropertyAnimation *medium_card_3_animation = new QPropertyAnimation(liste_8_cartes_medium[2],"pos");
     medium_card_3_animation->setDuration(1200);
    liste_8_cartes_medium[2]->numero_case_position = 5;
    controlleur_medium(5,true);

    medium_card_3_animation->setStartValue(medium_bank_position);
    medium_card_3_animation->setEndValue(medium_card_6_position);
    medium_card_3_animation->start();

    QPropertyAnimation *medium_card_4_animation = new QPropertyAnimation(liste_8_cartes_medium[3],"pos");
    medium_card_4_animation->setDuration(1100);
    medium_card_4_animation->setStartValue(medium_bank_position);
    liste_8_cartes_medium[3]->numero_case_position = 6;
    controlleur_medium(6,true);

    medium_card_4_animation->setEndValue(medium_card_7_position);
    medium_card_4_animation->start();
    desactive_medium_click();


}
void GameWindow ::connection_click_utilisateur (){
    /*
   Fonction void connection_click_utilisateur() : cette fonction connecte les
   clics de l'utilisateur.
   Elle permet de déclencher les fonctions à appeler lors du clic sur une
   carte.
*/


    connect(utilisateur.carte_1,&QPushButton::clicked ,this, [this]{
        compteur_de_tour++;
        utilisateur.carte_1 ->setEnabled(false);


        bool appartient = appartient_a_medium(utilisateur.carte_1);
        if(appartient){

          std ::vector<QPoint> position_for_card;
            std::vector<Carte*> carte_selectionner;
            get_position(position_for_card,carte_selectionner ,utilisateur.carte_1,0,true);
        }else{
            make_empty_animation(utilisateur.carte_1);
        }



    });
    connect(utilisateur.carte_2,&QPushButton::clicked ,this, [this]{
        compteur_de_tour++;
        utilisateur.carte_2 ->setEnabled(false);
        bool appartient = appartient_a_medium(utilisateur.carte_2);

        if(appartient){

            std ::vector<QPoint> position_for_card;
            std::vector<Carte*> carte_selectionner;
            get_position(position_for_card,carte_selectionner ,utilisateur.carte_2,0,true);
        }else{
            make_empty_animation(utilisateur.carte_2);
        }

    });
    connect(utilisateur.carte_3,&QPushButton::clicked ,this, [this]{
        compteur_de_tour++;
        utilisateur.carte_3 ->setEnabled(false);
        bool appartient = appartient_a_medium(utilisateur.carte_3);

        if(appartient){
             std ::vector<QPoint> position_for_card;
            std::vector<Carte*> carte_selectionner;
            get_position(position_for_card,carte_selectionner ,utilisateur.carte_3,0,true);
        }else{
            make_empty_animation(utilisateur.carte_3);
        }

    });
}



//connection  pour ia
//
//
//
void GameWindow::IA_player_moyen() {
    /*
   Fonction void IA_player_moyen(); fonction de l'IA moyen.
cette ia joue c est carte au hazard
*/

    // Seed the random number generator

    qDebug()<<"appel fonction IA moyen ";
    srand(static_cast<unsigned int>(time(nullptr)));



    std::vector<Carte*> available_cards;
    for (Carte* card : carte_list) {
        if (std::find(played_cards.begin(), played_cards.end(), card) == played_cards.end()) {
            available_cards.push_back(card);
        }
    }

    if (available_cards.empty()) {
        // All cards have been played, handle this case as needed
        return;
    }

    // Randomly select a card to play from the available cards
    int random_index = rand() % available_cards.size();
    qDebug()<<"random_index"<<random_index;
    Carte* selected_card = available_cards[random_index];

    bool card_on_table = appartient_a_medium(selected_card);
    compteur_de_tour++;

    if (card_on_table) {
        std::vector<QPoint> position_for_card;
        std::vector<Carte*> carte_selectionner;
        get_position(position_for_card, carte_selectionner, selected_card, 0, false);

        // Add the selected card to the list of played cards

    } else {
        make_empty_animation(selected_card);
    }
    played_cards.push_back(selected_card);
}
void GameWindow::IA_player_difficile (){
    /*
   Fonction void IA_player_difficile(); fonction de l'IA difficile.
cette ia choisi a chaque fois la meilleur combinaison de carte quelle peut jouer sinon elle joue une carte au hazard
*/

    // Seed the random number generator

    qDebug()<<"appel fonction IA moyen ";
    srand(static_cast<unsigned int>(time(nullptr)));



    std::vector<Carte*> available_cards;
    for (Carte* card : carte_list) {
        if (std::find(played_cards.begin(), played_cards.end(), card) == played_cards.end()) {
            available_cards.push_back(card);
        }
    }

    if (available_cards.empty()) {
        // All cards have been played, handle this case as needed
        return;
    }


    int  index = meilleur_coup(available_cards);
    qDebug()<<"random_index"<<index;
    Carte* selected_card = available_cards[index];

    bool card_on_table = appartient_a_medium(selected_card);
    compteur_de_tour++;

    if (card_on_table) {
        std::vector<QPoint> position_for_card;
        std::vector<Carte*> carte_selectionner;
        get_position(position_for_card, carte_selectionner, selected_card, 0, false);


    } else {
        make_empty_animation(selected_card);
    }
    played_cards.push_back(selected_card);
}


int  GameWindow::meilleur_coup(std::vector<Carte*> carte_restant){
    /*fontion pour calculer le meilleur coup possible pour l'ia elle renvoie l'index de la meilleur carte*/

    int i = 0, taille = carte_restant.size(),taille8carte =liste_8_cartes_medium.size() ;


    while (i<taille8carte) {
        for(int k =0 ;k<taille;k++){
            if(carte_restant[k]->numero_carte == liste_8_cartes_medium[i]->numero_carte){
                for(int j = 0; j<taille8carte;j++){
                    if(carte_restant[k]->numero_carte +1 == liste_8_cartes_medium[j]->numero_carte){
                    return k;
                    }

                }
                return k;

            }
        }
        i++;

    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index = rand() % carte_restant.size();
    qDebug()<<"random_index"<<random_index;
    return  random_index;
}

void GameWindow::IA_player_facile (){
    /*
   Fonction IA_player_facile(); fonction de l'IA de difficulté facile.
cette ia joue c est carte de maniere simple et consecutif ( c est a dire elle joue la carte 1 puis 2 puis 3 )
*/


             bool play1 = appartient_a_medium(IA.carte_1);
             bool play2 = appartient_a_medium(IA.carte_2);
             bool play3 = appartient_a_medium(IA.carte_3);
             compteur_de_tour++;

             if(carte_ia_facile == 0 ){

                     if(play1){
                       std ::vector<QPoint> position_for_card;
                       std::vector<Carte*> carte_selectionner;
                        get_position(position_for_card,carte_selectionner ,IA.carte_1,0,false);
                    }else{
                       make_empty_animation(IA.carte_1);
                    }
             }else if(carte_ia_facile == 1){

                    if(play2){
                       std ::vector<QPoint> position_for_card;
                       std::vector<Carte*> carte_selectionner;
                        get_position(position_for_card,carte_selectionner ,IA.carte_2,0,false);
                    }else{
                       make_empty_animation(IA.carte_2);
                    }
             }else {

                    if(play3){
                       std ::vector<QPoint> position_for_card;
                       std::vector<Carte*> carte_selectionner;
                        get_position(position_for_card,carte_selectionner ,IA.carte_3,0,false);
                    }else{
                       make_empty_animation(IA.carte_3);
                    }
             }
}

void GameWindow :: get_carte (User &utilisateur  ){
    /*
     Fonction void get_carte(User &utilisateur) :
     cette fonction distribue 3 cartes à l'utilisateur donné en
     paramètre (IA ou player).
*/

    int taille = liste_40_cartes.size();
    if(taille ==0){
                    if(user_score_number> ia_score_number){
                       WinnerWindow *page_suivante = new WinnerWindow(true);
                       setCentralWidget(page_suivante);
                       this->update();
                    }else{
                       WinnerWindow *page_suivante = new WinnerWindow(false);
                       setCentralWidget(page_suivante);
                       this->update();
                    }
    }else{
                    qDebug()<<"taille de la lisete "<<taille;
                    utilisateur.carte_1 = liste_40_cartes[taille-1];
                    utilisateur.carte_2 = liste_40_cartes[taille-2];
                    utilisateur.carte_3 = liste_40_cartes[taille-3];

                    int i = 0 ;
                    while ( i< 3){
                       liste_40_cartes.pop_back();
                       i++;
                    }
    }



}

//fonction pour obtenir la position des different carte du medium lors du jeu du user

void GameWindow ::get_position(std ::vector<QPoint> &position_for_card, std::vector<Carte*> &carte_selectionner ,Carte *cliked_card,int compteur,bool is_user){
    /*
   Fonction void get_position(std::vector<QPoint> &position_for_card, std::vector<Carte*> &carte_selectionner, Carte *clicked_card, int compteur, bool is_user);
   Cette fonction calcule la position de toutes les cartes qui sont consécutives à la carte cliquée.
*/


    int  taille = liste_8_cartes_medium.size() ;
    bool consecutif = false;


     if(compteur>= 8){

        int score = carte_selectionner.size();

        if(is_user){
            user_score_number += score;
        }else{
            ia_score_number += score;
        }
        make_user_card_animation (cliked_card ,position_for_card,carte_selectionner, 0);
        return;
    }
    for  (int i = 0 ;i<taille; i++) {
        if(cliked_card->numero_carte == liste_8_cartes_medium[i]->numero_carte){

            controlleur_medium(liste_8_cartes_medium[i]->numero_case_position,false);
            carte_selectionner.push_back(liste_8_cartes_medium[i]);
            position_for_card.push_back(liste_8_cartes_medium[i]->mapToGlobal(QPoint(0,0))+QPoint(0,-20));


            consecutif = true;
        }

    }


    if(consecutif){
        compteur++;

        cliked_card->numero_carte += 1;

        get_position(position_for_card,carte_selectionner,cliked_card,compteur,is_user);
    }else{

        int score = carte_selectionner.size();

        if(is_user){
            user_score_number += score;
        }else{
            ia_score_number += score;
        }
        make_user_card_animation (cliked_card ,position_for_card,carte_selectionner, 0);

        return;
    }


}


bool GameWindow ::appartient_a_medium(Carte *cliked_card){
    /*
   Fonction bool appartient_a_medium(Carte *clicked_card) :
   cette fonction sert à déterminer si une carte cliquée par l'utilisateur
   appartient à l'IA
   ou appartient à la liste de cartes au milieu de la table de jeux.
*/


    int i = 0, taille = liste_8_cartes_medium.size() ;

    while (i<taille) {
        if(cliked_card->numero_carte == liste_8_cartes_medium[i]->numero_carte){
            return true;
        }
        i++;

    }
    return false;
}
void GameWindow::controlleur_medium ( int numero_medium, bool is_suppression){
    /*
    Fonction void controlleur_medium(int numero_medium, bool is_suppression) :
    cette fonction contrôle les cartes qui se déplacent dans le milieu de la
    table pour supprimer
    et ajouter de nouvelles cartes sur la table.
*/

        int i = 0 ;
        while(i<8){
        if(i == numero_medium){
            if(is_suppression){
                medium_carte_controlleur[i] = true;

            }else{
                medium_carte_controlleur[i] = false;

            }

        }
        i++;
        }
    }

void GameWindow :: make_user_card_animation (Carte *cliked_carte , std::vector<QPoint> liste_point,std::vector<Carte* > liste_selectionner, int position){

    /*
   Fonction void make_user_card_animation(Carte *clicked_carte, std::vector<QPoint> liste_point, std::vector<Carte*> liste_selectionner, int position);
   Cette fonction effectue les animations des cartes qui sont consécutives ou égales à la carte sélectionnée.
*/


    if(liste_point.empty()){



         qDebug()<<"LA VALEUR DU COMPTEUR DE TOUR avant "<<this->compteur_de_tour;

          clean_medium(liste_selectionner);

         update_screen_info();
          if(this->compteur_de_tour>= 6){


            compteur_de_tour = 0 ;
            carte_ia_facile = 0;
            qDebug()<<"DISTRIBUTION DES CARTE  ";
                distrube_user_card_animation(true,utilisateur);
            distrube_user_card_animation(false,IA);
                is_user_turn = false;
            update_screen_info();
                desactive_medium_click();

         }else{
            if(is_user_turn){

                update_user_click(true);
                is_user_turn = !is_user_turn;


            }else{

                update_user_click(false);

                if (difficulte == 0)
                {
                    IA_player_facile();
                }
                else if (difficulte == 1)
                {
                    IA_player_moyen();
                }
                else
                {
                    IA_player_difficile();
                }
                qDebug()<<"Carte Ia "<<carte_ia_facile;
                carte_ia_facile++;
                is_user_turn = !is_user_turn;


            }
          }
          qDebug()<<"LA VALEUR DU COMPTEUR DE TOUR apres "<<this->compteur_de_tour;

        desactive_medium_click();

        hide_carte(cliked_carte);
        return;
        }

        QPropertyAnimation *animation = new QPropertyAnimation(cliked_carte,"pos");
        cliked_carte->raise();
        cliked_carte->setStyleSheet("background-image:url("+cliked_carte->image_carte+"); outline:none;border:0px");

        animation->setDuration(1000);
        animation->setEndValue(liste_point[0]);
        qDebug()<<"verification de la position "<<liste_point[0];
        animation->start();
        liste_point.erase(liste_point.begin());
        connect(animation ,&QPropertyAnimation::finished , this , [this,liste_point,position,cliked_carte,liste_selectionner]{
        hide_carte(liste_selectionner[position]);

            qDebug()<<"cache carte "<<position;

            make_user_card_animation(cliked_carte,liste_point,liste_selectionner,position +1);

        });


}
void GameWindow::make_empty_animation(Carte *cliked_carte){
    /*
   Fonction void make_empty_animation(Carte *clicked_carte);
   cette fonction est appelée lorsque la
   carte sélectionnée n'est pas consécutive à la liste de cartes sur la table.
    La fonction attribue une position sur la table et effectue l'animation.
*/

        for(int i = 0 ; i<8 ; i++){
        if(!medium_carte_controlleur[i]){
            switch (i) {
            case 0:
                 cliked_carte->numero_case_position = 0;
                move_animation(cliked_carte,medium_card_1_position);
                controlleur_medium ( i, true);

                return;
                break;
            case 1:
                 cliked_carte->numero_case_position = 1;
                move_animation(cliked_carte,medium_card_2_position);
                controlleur_medium ( i, true);
                return;
                break;
            case 2:
                cliked_carte->numero_case_position = 2;
                move_animation(cliked_carte,medium_card_3_position);
                controlleur_medium ( i, true);

                 return;
                break;
            case 3:
                move_animation(cliked_carte,medium_card_4_position);
                cliked_carte->numero_case_position = 3;
                controlleur_medium ( i, true);
                 return;
                break;
            case 4:
                cliked_carte->numero_case_position = 4;
                move_animation(cliked_carte,medium_card_5_position);
                controlleur_medium ( i, true);


                 return;
                break;
            case 5:
                 cliked_carte->numero_case_position = 5;
                move_animation(cliked_carte,medium_card_6_position);
                controlleur_medium ( i, true);

                liste_8_cartes_medium.push_back(cliked_carte);
                 return;
                break;
            case 6:
                cliked_carte->numero_case_position = 6;
                move_animation(cliked_carte,medium_card_7_position);
                controlleur_medium ( i, true);


                 return;
                break;
            default:
                cliked_carte->numero_case_position = 7;
                move_animation(cliked_carte,medium_card_8_position);
                controlleur_medium ( i, true);


                 return;
                break;
            }
        }
        }

}
void GameWindow:: move_animation(Carte *cliked_carte,QPoint position){
        QPropertyAnimation *animation = new QPropertyAnimation(cliked_carte,"pos");
        cliked_carte->raise();
        cliked_carte->setStyleSheet("background-image:url("+cliked_carte->image_carte+"); outline:none;border:0px");

        animation->setDuration(1200);
        animation->setEndValue(position);
        animation->start();
        connect(animation,&QPropertyAnimation::finished,this,[this,cliked_carte]{

 qDebug()<<"LA VALEUR DU COMPTEUR DE TOUR avant empty a  "<<this->compteur_de_tour;

            liste_8_cartes_medium.push_back(cliked_carte);
            update_screen_info();
            desactive_medium_click();
            update_screen_info();
            if(this->compteur_de_tour>= 6){

                compteur_de_tour = 0 ;
                carte_ia_facile = 0;
                qDebug()<<"DISTRIBUTION DES CARTE  ";
                distrube_user_card_animation(true,utilisateur);
                distrube_user_card_animation(false,IA);
                update_screen_info();
                is_user_turn = false;
                desactive_medium_click();

            }else{
                if(is_user_turn){

                    update_user_click(true);
                    is_user_turn = !is_user_turn;


                }else{

                    update_user_click(false);

                    if (difficulte == 0)
                    {
                        IA_player_facile();
                    }
                    else if (difficulte == 1)
                    {
                        IA_player_moyen();
                    }
                    else
                    {
                       IA_player_difficile();
                    }
                    qDebug()<<"Carte Ia "<<carte_ia_facile;
                    carte_ia_facile++;
                    is_user_turn = !is_user_turn;


                }
            }
             qDebug()<<"LA VALEUR DU COMPTEUR DE TOUR apres  empty "<<this->compteur_de_tour;


        });
}
void GameWindow::hide_carte(Carte* carte){
    /*
   Fonction void hide_carte(Carte* carte) : cette fonction
   cache la carte donnée en paramètre.
*/

        carte->setStyleSheet("background-color :transparent");
        carte->move(QPoint(-200,0));



}
void GameWindow::desactive_medium_click(){
    /*
   Fonction void desactive_medium_click();
 cette fonction désactive les clics des cartes sur le milieu de la table de jeu.
*/

        for(int i = 0 ; i<liste_8_cartes_medium.size();i++){
        liste_8_cartes_medium[i]->setEnabled(false);
        }
}
void GameWindow::update_user_click(bool activation){
 /*
   Fonction void update_user_click(bool activation);
   cette fonction sert à désactiver les clics de l'utilisateur
   lorsqu'il a déjà cliqué sur une carte pour jouer ou lorsque l'IA joue.
*/

        utilisateur.carte_1->setEnabled(activation);
        utilisateur.carte_2->setEnabled(activation);
        utilisateur.carte_3->setEnabled(activation);

}
void GameWindow::clean_medium(const std::vector<Carte*> element) {
    /*
   Fonction void clean_medium(std::vector<Carte*> elements);
   cette fonction supprime les cartes prises par les joueurs sur
   la table de jeux.
*/

        std::vector<int> liste_index;

        for (int i = 0; i < element.size(); ++i) {
        for (int j = 0; j < liste_8_cartes_medium.size();) {
            if (element[i]->numero_case_position == liste_8_cartes_medium[j]->numero_case_position) {
                liste_8_cartes_medium.erase(liste_8_cartes_medium.begin() + j);
                qDebug()<<"netoyage medium "<<liste_8_cartes_medium[j]->numero_case_position;
            } else {
                ++j;
            }
        }
        }
}

void GameWindow::update_screen_info() {
    /*
   Fonction void update_screen_info();
   cette fonction sert à mettre à jour les informations de score,
   tour utilisateur sur l'écran.
*/

        if (is_user_turn) {
        timer_tour->setText("Tour de :\nUser");
        } else {
        timer_tour->setText("Tour de :\nIA");
        }



        ia_score->setText("Score : "+ QString::number(ia_score_number));
        user_score->setText("Score : "+ QString::number(user_score_number));
        carte_restant->setText( QString::number(liste_40_cartes.size()));
}
GameWindow::~GameWindow(){
    //liberation del'espace memoire alouer par le programe
    delete card_img_1_ia_widget  ;
    delete card_img_2_ia_widget  ;
    delete card_img_3_ia_widget  ;
    delete card_img_1_user_widget ;
    delete card_img_2_user_widget  ;
    delete card_img_3_user_widget ;
    delete medium_bank_widget   ;
    delete medium_card_1_widget  ;
    delete medium_card_2_widget ;
    delete medium_card_3_widget  ;
    delete medium_card_4_widget  ;
    delete medium_card_5_widget  ;
    delete medium_card_6_widget  ;
    delete medium_card_7_widget  ;
    delete medium_card_8_widget  ;
    delete medium_bank ;
    delete timer_tour;
    delete ia_score ;
    delete user_score ;
    delete carte_restant;
    //liberation memoire des carte alouer dans le jeu
    while (played_liste.size() != 0) {
        int taille  = played_liste.size();
        Carte *temp = played_liste[taille-1];
        played_liste.pop_back();
        delete temp;

    }

}




