#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "Responsable.h"
#include <fstream>
#include "Client.h"
#include "Chauffeur.h"
#include "reservation.h"
#pragma once
using namespace std;
Responsable::Responsable()
{
    while (chercher_responsable(this->CIN) != -1)
    {
        cout << "Ce numero de CIN existe deja. Saisissez un nouveau numero de CIN : ";
        cin >> CIN;
    }
    cout << "Quelle est la responsabilite?" << endl;
    cin >> this->reponsabilite;
    cout << "Quel est le nom de l'agence?" << endl;
    cin >> this->agence;
}
Responsable::Responsable(string a, string r) : personne("", "", "", Date(1, 1, 2000))
{
    this->agence = a;
    this->reponsabilite = r;
}
void Responsable::sauvegarder()
{
    fstream f("responsables.txt", ios::out | ios::app);
    f << this;
    this->load_responsables();
}
void Responsable::load_responsables()
{
    responsables.clear();
    fstream f("responsables.txt", ios::in);
    f.seekg(0);
    while (1)
    {
        Responsable *r = new Responsable("", "");
        if (f.eof())
            break;
        f >> r;
        responsables.push_back(r);
    }
    responsables.pop_back();
}
void Responsable::afficher_responsables()
{
    this->load_responsables();
    for (int i = 0; i < responsables.size(); i++)
    {
        cout << *(responsables[i]);
    }
}
int Responsable::chercher_responsable(string nCIN)
{
    this->load_responsables();
    for (int i = 0; i < responsables.size(); i++)
    {
        if (nCIN == responsables[i]->getcin())
        {
            return i;
        }
    }
    return -1;
}
client Responsable::ajouter_client()
{
    client c;
    c.sauvegarder();
    return c;
}

void Responsable::supprimer_client()
{
    string nCIN;
    client c(false, "");
    cout << "Donner le cin du client a supprimer : ";
    cin >> nCIN;
    int i = c.chercher_client(nCIN);
    if (i == -1)
    {
        cout << "Ce Client n'existe pas" << endl;
    }
    else
    {
        if (c.clients[i]->mes_reservations<Reservation>().size() > 0)
        {
            cout << "Ce client a des reservations vous ne pouvez pas le supprimer" << endl;
        }
        else
        {
            c.clients.erase(c.clients.begin() + i);
            fstream f("clients.txt", ios::out | ios::trunc);
            for (int i = 0; i < c.clients.size(); i++)
            {
                f << c.clients[i];
            }
        }
    }
}
bool Responsable::supprimer_client(string nCIN)
{
    client c(false, "");
    int i = c.chercher_client(nCIN);
    if (i == -1)
    {
        cout << "Ce Client n'existe pas!" << endl;
        return false;
    }
    else
    {
        if (c.clients[i]->mes_reservations<Reservation>().size() > 0)
        {
            cout << "Ce client a des reservations vous ne pouvez pas le modifier." << endl;
            return false;
        }
        else
        {
            c.clients.erase(c.clients.begin() + i);
            fstream f("clients.txt", ios::out | ios::trunc);
            for (int i = 0; i < c.clients.size(); i++)
            {
                f << c.clients[i];
            }
        }
    }
    return true;
}
void Responsable::modifier_client()
{
    string nCIN;
    cout << "Donner le cin du client a modifier : ";
    cin >> nCIN;
    if (supprimer_client(nCIN))
    {
        ajouter_client();
        cout << "Client Modifie avec succes" << endl;
    }
}
void Responsable::afficher_clients()
{
    client c(false, "");
    c.afficher_clients();
}
void Responsable::ajouter_chauffeur()
{
    chauffeur c;
    c.sauvegarder();
}
void Responsable::supprimer_chauffeur()
{
    string nCIN;
    chauffeur c("", "");
    cout << "Donner le cin du chauffeur a supprimer : ";
    cin >> nCIN;
    int i = c.chercher_chauffeur(nCIN);
    if (i == -1)
    {
        cout << "Ce Chauffeur n'existe pas" << endl;
    }
    else
    {
        c.chauffeurs.erase(c.chauffeurs.begin() + i);
        fstream f("chauffeurs.txt", ios::out | ios::trunc);
        for (int i = 0; i < c.chauffeurs.size(); i++)
        {
            f << c.chauffeurs[i];
        }
    }
}
bool Responsable::supprimer_chauffeur(string nCIN)
{
    chauffeur c("", "");
    int i = c.chercher_chauffeur(nCIN);
    if (i == -1)
    {
        cout << "Ce Chauffeur n'existe pas" << endl;
        return false;
    }
    else
    {
        c.chauffeurs.erase(c.chauffeurs.begin() + i);
        fstream f("chauffeurs.txt", ios::out | ios::trunc);
        for (int i = 0; i < c.chauffeurs.size(); i++)
        {
            f << c.chauffeurs[i];
        }
    }
    return true;
}
void Responsable::modifier_chauffeur()
{
    string nCIN;
    cout << "Donner le cin du chauffeur a modifier : ";
    cin >> nCIN;
    if (supprimer_chauffeur(nCIN))
    {
        chauffeur c;
        c.sauvegarder();
    }
}
void Responsable::afficher_chauffeurs()
{
    chauffeur c("", "");
    c.afficher_chauffeurs();
}
void Responsable::effectuer_reservation()
{
    Reservation res(this->agence);
    if (res.get_reserve())
    {
        res.suavegarder();
        cout << "Reservation effectuee avec succes";
    }
    else
    {
        cout << "La reservation n'a pas ete effectuee. Reessayez!";
    }
}
void Responsable::afficher_reservations()
{
    Reservation r;
    r.afficher_reservations();
}
void Responsable::afficher_emplacements()
{
    Emplacement E("", 0, 0, false);
    E.afficher_emplacements();
}
ostream &operator<<(ostream &os, Responsable &r)
{

    os << "nom : " << r.nom << "\t"
       << "prenom : " << r.prenom << endl
       << "num cin : " << r.CIN << "\t"
       << "Date de Naissance : " << r.date_de_naissance << endl
       << "responsabilite : " << r.reponsabilite << "\tAgence: " << r.agence << endl;
    return os;
}
ostream &operator<<(ostream &os, Responsable *r)
{
    os << r->nom << "\t"
       << r->prenom << "\t"
       << r->CIN << "\t" << &(r->date_de_naissance) << "\t"
       << r->reponsabilite << "\t" << r->agence << endl;
    return os;
}
istream &operator>>(istream &is, Responsable *r)
{
    is >> r->nom >> r->prenom >> r->CIN >> &(r->date_de_naissance) >> r->reponsabilite >> r->agence;
    return is;
}