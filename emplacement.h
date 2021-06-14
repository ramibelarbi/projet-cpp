#include <iostream>
#include <vector>
#include "Date.h"
#pragma once
using namespace std;

class Emplacement
{
    string id;
    int capacite;
    float prix_par_jour;
    bool Douche_indiv;

public:
    static vector<Emplacement *> Emplacements;
    Emplacement();
    Emplacement(string, int, float, bool);
    string get_id() { return id; }
    float getppj() { return prix_par_jour; };
    int get_cap() { return capacite; }
    void sauvegarder();
    void load_emplacements();
    void afficher_emplacements();
    int chercher_emplacement(string);
    bool est_disponible(Date, Date);
    friend ostream &operator<<(ostream &os, Emplacement &E);
    friend ostream &operator<<(ostream &os, Emplacement *E);
    friend istream &operator>>(istream &is, Emplacement *E);
    bool operator==(const Emplacement &E) const { return this->id == E.id; };
};
vector<Emplacement *> Emplacement::Emplacements;