#include <iostream>
#include <string.h>
#include <fstream>
#include "Chauffeur.h"
#pragma once
using namespace std;

chauffeur::chauffeur()
{
    while (chercher_chauffeur(this->CIN) != -1)
    {
        cout << "Ce numero de CIN existe deja. Saisissez un nouveau numero de CIN : ";
        cin >> CIN;
    }
    num_permis = saisiepermis();
    cout << "quelle est l'agence qu'il travail avec?" << endl;
    cin >> this->Agence;
}
chauffeur::chauffeur(string permis, string Agence) : personne("", "", "", Date(1, 1, 2000))
{
    num_permis = permis;
    this->Agence = Agence;
}
string chauffeur::saisiepermis()
{

    string s;
    cout << "Donnez le numero de permis : ";
    while (true)
    {
        cin >> s;
        if ((s.size() != 9) && (s[2] != '/'))
        {
            cout << "svp donnez un numero permis valide. Reesayez" << endl;
        }
        else
        {
            return s;
        }
    }
}
void chauffeur::sauvegarder()
{
    fstream f("chauffeurs.txt", ios::out | ios::app);
    f << this;
    this->load_chauffeurs();
}
void chauffeur::load_chauffeurs()
{
    chauffeurs.clear();
    fstream f("chauffeurs.txt", ios::in);
    f.seekg(0);
    while (1)
    {
        chauffeur *ch = new chauffeur("", "");
        if (f.eof())
            break;
        f >> ch;
        chauffeurs.push_back(ch);
    }
    chauffeurs.pop_back();
}
void chauffeur::afficher_chauffeurs()
{
    this->load_chauffeurs();
    for (int i = 0; i < chauffeurs.size(); i++)
    {
        cout << *(chauffeurs[i]);
    }
}
int chauffeur::chercher_chauffeur(string nCIN)
{
    this->load_chauffeurs();
    for (int i = 0; i < chauffeurs.size(); i++)
    {
        if (nCIN == chauffeurs[i]->getcin())
        {
            return i;
        }
    }
    return -1;
}
chauffeur::~chauffeur()
{
}
ostream &operator<<(ostream &os, chauffeur &c)
{

    os << "nom : " << c.nom << "\t"
       << "prenom : " << c.prenom << endl
       << "num cin : " << c.CIN << "\t"
       << "Date de Naissance : " << c.date_de_naissance << endl
       << "permis : " << c.num_permis << "\tAgence: " << c.Agence << endl;
    return os;
}
ostream &operator<<(ostream &os, chauffeur *c)
{
    os << c->nom << "\t"
       << c->prenom << "\t"
       << c->CIN << "\t" << &(c->date_de_naissance) << "\t"
       << c->num_permis << "\t" << c->Agence << endl;
    return os;
}
istream &operator>>(istream &is, chauffeur *c)
{
    is >> c->nom >> c->prenom >> c->CIN >> &(c->date_de_naissance) >> c->num_permis >> c->Agence;
    return is;
}