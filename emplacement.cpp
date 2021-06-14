#include <iostream>
#include "emplacement.h"
#include <fstream>
#pragma once
using namespace std;

Emplacement::Emplacement()
{
    char c;
    cout << "Saisissez l'identifiant de l'emplacement :" << endl;
    cin >> id;
    while (chercher_emplacement(id) != -1)
    {
        cout << "Cet identifient Existe deja. Reesseyez!" << endl;
        cin >> id;
    }
    cout << "Saisissez la capacite de l'emplacement :" << endl;
    cin >> capacite;
    cout << "Saisissez le prix par jour :" << endl;
    cin >> prix_par_jour;

    cout << "Est ce que l'emplacement a un douche indiv? O/N :" << endl;
    cin >> c;
    while (true)
    {
        if (c == 'O')
        {
            Douche_indiv = true;
            break;
        }
        else if (c == 'N')
        {
            Douche_indiv = false;
            break;
        }
        else
        {
            cout << "Choix invalide Reessayez" << endl;
        }
    }
}
Emplacement::Emplacement(string id, int capacite, float ppj, bool douche = false)
{
    this->id = id;
    this->capacite = capacite;
    this->Douche_indiv = douche;
    this->prix_par_jour = ppj;
}
void Emplacement::sauvegarder()
{
    fstream f("emplacements.txt", ios::out | ios::app);
    f << this;
    this->load_emplacements();
}
void Emplacement::load_emplacements()
{
    Emplacements.clear();
    fstream f("emplacements.txt", ios::in);
    f.seekg(0);
    while (1)
    {
        Emplacement *E = new Emplacement("", 0, 0);
        if (f.eof())
        {
            break;
        }
        f >> E;
        Emplacements.push_back(E);
    }
    Emplacements.pop_back();
}
void Emplacement::afficher_emplacements()
{
    this->load_emplacements();
    for (int i = 0; i < Emplacements.size(); i++)
    {
        cout << *(Emplacements[i]);
    }
}
int Emplacement::chercher_emplacement(string id_rech)
{
    this->load_emplacements();
    for (int i = 0; i < Emplacements.size(); i++)
    {
        if (id_rech == Emplacements[i]->get_id())
        {
            return i;
        }
    }
    return -1;
}
bool est_disponible(Date dd, Date df)
{
    return true;
}
ostream &operator<<(ostream &os, Emplacement &E)
{
    string douche = "Non";
    if (E.Douche_indiv == true)
    {
        douche = "Oui";
    }
    os << "ID : " << E.id << "\t"
       << "Capacite : " << E.capacite << endl
       << "Prix par jour : " << E.prix_par_jour << "\t"
       << "Douche indiv: " << douche << endl;
    return os;
}
ostream &operator<<(ostream &os, Emplacement *E)
{
    os << E->id << "\t" << E->capacite << "\t" << E->prix_par_jour << "\t" << E->Douche_indiv << endl;
    return os;
}
istream &operator>>(istream &is, Emplacement *E)
{
    is >> E->id >> E->capacite >> E->prix_par_jour >> E->Douche_indiv;
    return is;
}