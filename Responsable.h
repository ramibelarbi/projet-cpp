#include <iostream>
#include <string.h>
#include <vector>
#include "Personne.h"
#include "Client.h"
#pragma once
using namespace std;

class Responsable : public personne
{
protected:
    string agence;
    string reponsabilite;

public:
    static vector<Responsable *> responsables;
    Responsable();
    Responsable(string, string);
    void sauvegarder();
    void load_responsables();
    void afficher_responsables();
    int chercher_responsable(string);
    client ajouter_client();
    void supprimer_client();
    bool supprimer_client(string);
    void modifier_client();
    void afficher_clients();
    void ajouter_chauffeur();
    void supprimer_chauffeur();
    bool supprimer_chauffeur(string);
    void modifier_chauffeur();
    void afficher_chauffeurs();
    void effectuer_reservation();
    void afficher_reservations();
    void afficher_emplacements();
    friend ostream &operator<<(ostream &os, Responsable &r);
    friend ostream &operator<<(ostream &os, Responsable *r);
    friend istream &operator>>(istream &is, Responsable *r);
};
vector<Responsable *> Responsable::responsables;