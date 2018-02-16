#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>

#include <string>


using namespace std;

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();

        int jetons=100;
        int mise;
        bool joueurJoue=true;
        string aliasJoueur;

        void Sauvegarder(Joueur);
        bool Rejouer();
//        void Charger();
        bool Quitter();

    protected:

    private:
};

#endif // JOUEUR_H
