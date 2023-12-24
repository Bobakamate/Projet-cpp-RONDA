#include "mainwindow.h"
#include"LevelWindow.h"
#include<QWidget>
#include<QVBoxLayout>
//#include "SDL/include/SDL2/SDL.h"
#include<QLabel>
#include<QFrame>
#include<QPushButton>
#include <QCoreApplication>

RONDA::RONDA(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *ma_fenetre = new QWidget(this);
    QVBoxLayout *container = new QVBoxLayout(ma_fenetre);
    QLabel *game_title= new QLabel("RONDA");
    QFrame *game_banner = new QFrame;
    QPushButton *play_button  = new QPushButton("Joueur");



    game_banner->setFixedSize(720,400);
    play_button->setFixedSize(200,50);
    QString ImagePath = QCoreApplication::applicationDirPath() +"/assets/images/ronda_bg_1.png";
    game_banner->setStyleSheet("QFrame {background-image: url("+ImagePath+");}");
    game_title->setStyleSheet("QLabel {"
                              "    font-weight: bold;"     // Texte en gras
                              "    font-size: 30px;"       // Taille de police de 25 pixels
                              "    color: white;"          // Couleur du texte blanche
                              "}");
    play_button->setStyleSheet("QPushButton {"
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

    container->addWidget(game_title,0,Qt::AlignCenter);
    container->addSpacing(20);
    container->addWidget(game_banner,0,Qt::AlignCenter);
    container->addWidget(play_button,0,Qt::AlignCenter);
    container->setAlignment(Qt::AlignCenter);
    setCentralWidget(ma_fenetre);
    connect(play_button,&QPushButton::clicked,this ,&RONDA::Button_cliked);






}
void RONDA:: Button_cliked()
{
    LevelWindow *page_suivante =  new  LevelWindow();
    setCentralWidget(page_suivante);
  this->update();
}
/*void RONDA::Play_Music()
{
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    if (SDL_LoadWAV("c:/bg_song.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        qDebug() << "Erreur lors du chargement du fichier WAV : " << SDL_GetError();
        // Gérez l'erreur comme nécessaire
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        qDebug() << "Erreur lors de l'ouverture du périphérique audio : " << SDL_GetError();
        // Gérez l'erreur comme nécessaire
    }

    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0); // Démarre la lecture audio

    // Ajoutez éventuellement un mécanisme pour gérer le bouton de manière asynchrone
}*/


RONDA::~RONDA()
{

}

