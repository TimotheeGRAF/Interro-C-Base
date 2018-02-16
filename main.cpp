#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "joueur.h"
#include "jeu.h"
#include <string>
#include "casino.h"
#include <time.h>

using namespace std;

int main()
{
    string nomJoueur;
    fstream saveJoueur;
    vector<Jeu> listJeux;  //Conteneur des jeux
    string caracJoueur;
    srand(time(NULL));

//On créé les types de jeu
    Jeu blackJack;
    Jeu roulette;
    Jeu craps;
//On les stocke dans un vecteur
    listJeux.push_back(blackJack);
    listJeux.push_back(roulette);
    listJeux.push_back(craps);

    saveJoueur.open("Joueur.txt", fstream::in | fstream::out);
//Si pas de sauvegarde, on créé un nouveau joueur
    cout<<"Bienvenue au Casinoob ! \n"<<endl;
    Casino Casinoob;    //Nouveau casino
    cout<<"Quel est votre nom ?"<<endl;
    cin>>nomJoueur;
//Nouveau joueur
    Joueur nouveauJoueur;
    nouveauJoueur.aliasJoueur=nomJoueur;
    saveJoueur.open("Joueur.txt", fstream::in | fstream::out);
    saveJoueur<<nomJoueur;
    saveJoueur.close();
//On joue tant qu'on a envie
    while(nouveauJoueur.joueurJoue!=false)
    {
//On demande et stocke le type de jeu
    cout<<"A quel jeu souhaitez vous jouer ?\n Roulette : 1 , Craps : 2 , Black Jack : 3 \n"<<endl;
    cin>>Casinoob.typeJeu;
//On envoie la méthode de jeu en fonction du type choisi

        switch(Casinoob.typeJeu)
        {

        case 1:
            cout<<"Veuillez placer une mise :"<<endl;
            cin>>nouveauJoueur.mise;
            nouveauJoueur.jetons=nouveauJoueur.jetons-nouveauJoueur.mise;

            roulette.resultat=rand()%10;
            if(roulette.resultat>3)
            {
                nouveauJoueur.jetons=nouveauJoueur.jetons+nouveauJoueur.mise*2;
                cout<<"Vous avez gagne a la Roulette ! Felicitations ! Vous avez "<<nouveauJoueur.jetons<<" jetons.\n "<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>roulette.finPartie;
                switch(roulette.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
            else
            {
                cout<<"Vous avez perdu votre mise, il vous reste "<<nouveauJoueur.jetons<<" jetons !"<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>roulette.finPartie;
                switch(roulette.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
        case 2:
            cout<<"Veuillez placer une mise :"<<endl;
            cin>>nouveauJoueur.mise;
            nouveauJoueur.jetons=nouveauJoueur.jetons-nouveauJoueur.mise;

            craps.resultat=rand()%4;

            if(craps.resultat==3)
            {
                nouveauJoueur.jetons=nouveauJoueur.jetons+nouveauJoueur.mise*2;
                cout<<"Vous avez gagne au Craps ! Felicitations ! Vous avez "<<nouveauJoueur.jetons<<" jetons.\n "<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>craps.finPartie;
                switch(craps.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
            else
            {
                cout<<"Vous avez perdu votre mise, il vous reste "<<nouveauJoueur.jetons<<" jetons !"<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>craps.finPartie;
                switch(craps.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
        case 3:
            cout<<"Veuillez placer une mise :"<<endl;
            cin>>nouveauJoueur.mise;
            nouveauJoueur.jetons=nouveauJoueur.jetons-nouveauJoueur.mise;

            blackJack.resultat=rand()%5;

            if(blackJack.resultat>3)
            {
                nouveauJoueur.jetons=nouveauJoueur.jetons+nouveauJoueur.mise*2;
                cout<<"Vous avez gagne au Black Jack ! Felicitations ! Vous avez "<<nouveauJoueur.jetons<<" jetons.\n "<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>blackJack.finPartie;
                switch(blackJack.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
            else
            {
                cout<<"Vous avez perdu votre mise, il vous reste "<<nouveauJoueur.jetons<<" jetons !"<<endl;
                cout<<"Voulez vous Rejouer = 1 \n Sauvegarder = 2 \n Charger = 3 \n Quitter = 4"<<endl;
                cin>>blackJack.finPartie;
                switch(blackJack.finPartie)
                {
                case 1:
                    nouveauJoueur.Rejouer();
                    break;
                case 2:
                    nouveauJoueur.Sauvegarder(nouveauJoueur);
                    break;
                case 3:
                    cout<<" WORK IN PROGRESS, COME BACK LATER "<<endl;
                    return nouveauJoueur.joueurJoue ;
                    break;
                case 4:
                    nouveauJoueur.Quitter();
                    break;
                }
                break;
            }
        }
    }

    return 0;
}
