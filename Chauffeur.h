#include <iostream>
#include <string.h>
#include <vector>
#include "Personne.h"
#pragma once
using namespace std;

class chauffeur : public personne
{
protected:
    string num_permis;
    string Agence;

public:
    static vector<chauffeur *> chauffeurs;
    chauffeur();
    chauffeur(string, string);
    void sauvegarder();
    void load_chauffeurs();
    void afficher_chauffeurs();
    int chercher_chauffeur(string);
    string saisiepermis();
    ~chauffeur();
    friend ostream &operator<<(ostream &os, chauffeur &c);
    friend ostream &operator<<(ostream &os, chauffeur *c);
    friend istream &operator>>(istream &is, chauffeur *c);
};
vector<chauffeur *> chauffeur::chauffeurs;