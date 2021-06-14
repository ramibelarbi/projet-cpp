#include <iostream>
#include <string.h>
#include "Personne.h"
#pragma once

class admin : public personne
{
protected:
    string Agence;

public:
    admin();
    admin(string);
    void ajouter_responsable();
    void afficher_responsables();
    void supprimer_responsable();
    bool supprimer_responsable(string);
    void modifier_responsable();
    void ajouter_emplacement();
    void modifier_admin();
    void sauvegarder();
    void load_admin();
    void afficher_emplacements();
    friend ostream &operator<<(ostream &os, admin &a);
    friend ostream &operator<<(ostream &os, admin *a);
    friend istream &operator>>(istream &is, admin *a);
};