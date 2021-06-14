#include <iostream>
#include <string.h>
#include "Admin.h"
#include "Responsable.h"
#include <fstream>
#include "emplacement.h"
#pragma once
using namespace std;
admin::admin()
{
    cout << "donner le nom de l'agence de voyage de cet admin : " << endl;
    cin >> this->Agence;
}
admin::admin(string agence) : personne("", "", "", Date(1, 1, 2000))
{
    this->Agence = agence;
}
void admin::ajouter_responsable()
{
    Responsable r;
    r.sauvegarder();
}
void admin::afficher_responsables()
{
    Responsable r("", "");
    r.afficher_responsables();
}
void admin::supprimer_responsable()
{
    string nCIN;
    Responsable c("", "");
    cout << "Donner le cin du responsable a supprimer : ";
    cin >> nCIN;
    int i = c.chercher_responsable(nCIN);
    if (i == -1)
    {
        cout << "Ce responsable n'existe pas" << endl;
    }
    else
    {
        c.responsables.erase(c.responsables.begin() + i);
        fstream f("responsables.txt", ios::out | ios::trunc);
        for (int i = 0; i < c.responsables.size(); i++)
        {
            f << c.responsables[i];
        }
    }
}
bool admin::supprimer_responsable(string nCIN)
{
    Responsable c("", "");
    int i = c.chercher_responsable(nCIN);
    if (i == -1)
    {
        cout << "Ce responsable n'existe pas" << endl;
        return false;
    }
    else
    {
        c.responsables.erase(c.responsables.begin() + i);
        fstream f("responsables.txt", ios::out | ios::trunc);
        for (int i = 0; i < c.responsables.size(); i++)
        {
            f << c.responsables[i];
        }
    }
    return true;
}
void admin::modifier_responsable()
{
    string nCIN;
    cout << "Saisissez le cin du responsable a modifier: " << endl;
    cin >> nCIN;
    if (this->supprimer_responsable(nCIN))
    {
        ajouter_responsable();
        cout << "Responsable Modifie avec succes" << endl;
    }
}
void admin::ajouter_emplacement()
{
    Emplacement E;
    E.sauvegarder();
}
void admin::sauvegarder()
{
    fstream f("admin.txt", ios::out | ios::trunc);
    f << this;
}
void admin::modifier_admin()
{
    cout << "saisir le nom et le prenom de l'admin' :" << endl;
    cin >> nom >> prenom;
    cout << "saisir la carte d'identite nationale " << endl;
    CIN = setcin();
    cout << "saisir la date de naissance :" << endl;
    cin >> date_de_naissance;
    cout << "donner le nom de l'agence de voyage de cet admin : " << endl;
    cin >> this->Agence;
    this->sauvegarder();
}
void admin::load_admin()
{
    fstream f("admin.txt", ios::in);
    f >> this;
}
void admin::afficher_emplacements()
{
    Emplacement E("", 0, 0, false);
    E.afficher_emplacements();
}
ostream &operator<<(ostream &os, admin &a)
{
    os << "nom : " << a.nom << "\t"
       << "prenom : " << a.prenom << endl
       << "num cin : " << a.CIN << "\t"
       << "Date de Naissance : " << a.date_de_naissance << endl
       << "Agence: " << a.Agence << endl;
    return os;
}
ostream &operator<<(ostream &os, admin *a)
{
    os << a->nom << "\t"
       << a->prenom << "\t"
       << a->CIN << "\t" << &(a->date_de_naissance) << "\t"
       << a->Agence;
    return os;
}
istream &operator>>(istream &is, admin *a)
{
    is >> a->nom >> a->prenom >> a->CIN >> &(a->date_de_naissance) >> a->Agence;
    return is;
}