#include "joueur.h"
#include <fstream>

using namespace std;

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}
void Joueur::Sauvegarder(Joueur player)
{
    fstream save;
    save.open("Joueur.txt", fstream::in | fstream::out |fstream::app);
    save<<player.aliasJoueur;
    save<<player.jetons;
    save.close();
}
bool Joueur::Rejouer()
{
    return joueurJoue=true;
}
//void Joueur::Charger(Joueur player)
//{
//    fstream load;
//    load.open("Joueur.txt", fstream::in | fstream::out | fstream::trunc);
//
//
//}
bool Joueur::Quitter()
{
    return joueurJoue=false;
}
