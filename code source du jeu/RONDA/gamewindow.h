#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include<QObject>
#include<QPoint>
#include<QFrame>
#include<vector>
#include<QString>
#include "Carte.h"
#include "User.h"
#include <QLabel>




class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(int difficulter ,QString IA_image ,QWidget *parent = nullptr);
    void get_point_values();
    void cards_distribution_start();
    void make_carte (std::vector<Carte*> &liste_cartes);
    void melanger_carte(std::vector<Carte*>& cartes);
    void get_carte (User &utilisateur  );
    void connection_click_utilisateur ();
    void controlleur_medium ( int numero_medium, bool is_suppression);
    bool appartient_a_medium(Carte *cliked_card);
    void hide_carte(Carte* carte);
    void make_user_card_animation (Carte *cliked_carte , std::vector<QPoint> liste_point,std::vector<Carte* > liste_selectionner, int position);
    void get_position(std ::vector<QPoint> &position_for_card, std::vector<Carte*> &carte_selectionner ,Carte *cliked_card,int compteur,bool is_user);
    void move_animation(Carte *cliked_carte,QPoint position);
    void make_empty_animation(Carte *cliked_carte);
    void distrube_user_card_animation(bool is_user, User &utilisateur);
    void update_user_click(bool activation);
    void IA_player_moyen ();
    void IA_player_facile ();
    void desactive_medium_click();
    void clean_medium(std::vector<Carte*> element);
    void update_screen_info();
    void set_green();
    void  IA_player_difficile ();
    int  meilleur_coup(std::vector<Carte*> carte_restant);
    ~GameWindow();


private:
    //definition des position des Carte pour les animation dans le jeux
    QPoint card_img_1_ia_position ;
    QPoint card_img_2_ia_position ;
    QPoint card_img_3_ia_position;
    QPoint card_img_1_user_position ;
    QPoint card_img_2_user_position;
    QPoint card_img_3_user_position;
    QPoint medium_card_1_position  ;
    QPoint medium_card_2_position ;
    QPoint medium_card_3_position  ;
    QPoint medium_card_4_position  ;
    QPoint medium_card_5_position  ;
    QPoint medium_card_6_position ;
    QPoint medium_card_7_position  ;
    QPoint medium_card_8_position  ;
    QPoint medium_bank_position   ;

    //definition   des widget qui vont sertvir a calculer la position des carte
    QFrame *card_img_1_ia_widget  ;
    QFrame *card_img_2_ia_widget  ;
    QFrame *card_img_3_ia_widget  ;
    QFrame *card_img_1_user_widget ;
    QFrame *card_img_2_user_widget  ;
    QFrame *card_img_3_user_widget ;
    QFrame *medium_bank_widget   ;
    QFrame *medium_card_1_widget  ;
    QFrame *medium_card_2_widget ;
    QFrame *medium_card_3_widget  ;
    QFrame *medium_card_4_widget  ;
    QFrame *medium_card_5_widget  ;
    QFrame *medium_card_6_widget  ;
    QFrame *medium_card_7_widget  ;
    QFrame *medium_card_8_widget  ;
    QFrame *medium_bank ;
    //attribut

    std::vector<Carte*> liste_40_cartes;
    std::vector<Carte*> liste_8_cartes_medium;
    std::vector<bool> medium_carte_controlleur;
    QWidget *ma_fenetre;
    User IA ;//objet utilisateur IA avec 3 carte de jeu
    User utilisateur ;//objet utilisateur utilisateur avec 3 carte de jeu
    bool is_user_turn ;//compteur pour savoir qui doit jouer
    int compteur_de_tour;//compteur de tour de jeu
    int carte_ia_facile;
    int ia_score_number;
    int user_score_number ;
    int carte_restant_number;
    //objet text de l'ecran mit a jour par leur variable int
    QLabel *timer_tour;
    QLabel *ia_score ;
    QLabel *user_score ;
    QLabel *carte_restant;
    QString ImagePathBack ;
    std::vector<Carte*> played_cards;
    std::vector<Carte*> played_liste;//adresse des 40 carte pour libere la memoire
    int difficulte;//difficulter du jeu
    std::vector<Carte*> carte_list;








};

#endif // GAMEWINDOW_H
