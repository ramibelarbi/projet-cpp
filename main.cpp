#include<iostream>
#include<string.h>
#include<fstream>
#include "projet.cpp"
using namespace std;
int main()
{
    personne p;
    fstream f;
    chauffeur c;
    responsable r;
    /*r.ajouter_client(f);*/
    r.afficher_les_clients(f);
    /*r.ajouter_chauffeur(f);*/
   /* r.afficher_les_chauffeurs(f);*/
    /*c.saisirchauffeur();*/
   /* p.saisirpersonne();
    p.choix();*/
    return 0;
}