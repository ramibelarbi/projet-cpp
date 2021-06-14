#include <iostream>
#include "reservation.h"
#include "Client.h"
#include "Responsable.h"
#include "emplacement.h"
#include <fstream>
#pragma once
using namespace std;

Reservation::Reservation(string agence)
{
    client c("", "");
    Responsable r("", "");
    string nCIN;
    int indexe, k;
    string reponse;
    this->agence = agence;
    cout << "donnez le nombre de jours de la reservation : " << endl;
    cin >> nb_jours;
    while (nb_jours < 0)
    {
        cout << "Nombre invalide. Reessayez." << endl;
        cin >> nb_jours;
    }

    cout << "donnez la date de debut de la reservation" << endl;
    cin >> date_debut;
    date_fin = date_debut.additionDate(nb_jours);
    cout << "Donnez le nombre de campeurs : " << endl;
    cin >> nb_campeurs;
    while (nb_campeurs < 1)
    {
        cout << "Impossible! le nombre de campeurs doit etre superieur a zero.Donnez le nombre de campeurs : " << endl;
        cin >> nb_campeurs;
    }
    c.load_clients();
    for (int i = 0; i < nb_campeurs; i++)
    {
        cout << "Donnez le cin du campeur : ";
        cin >> nCIN;
        for (int j = 0; j < campeurs.size(); j++)
        {
            if (nCIN == campeurs[j].getcin())
            {
                cout << "Ce Client Existe deja dans cette reservation donnez un nouveau CIN : ";
                cin >> nCIN;
                j = 0;
            }
        }

        indexe = c.chercher_client(nCIN);
        if (indexe == -1)
        {
            cout << "Ce Client n'existe pas. Ajouter un nouveau client?O/N" << endl;
            cin >> reponse;
            while (reponse != "N" && reponse != "O")
            {
                cout << "Reponse Invalide! Reessayez." << endl;
                cin >> reponse;
            }
            if (reponse == "N")
            {
                i -= 1;
            }
            else if (reponse == "O")
            {
                campeurs.push_back(r.ajouter_client());
            }
        }
        else
        {
            cout << *(c.clients[indexe]);
            cout << "Voulez vous ajouter ce client?O/N" << endl;
            cin >> reponse;
            while (reponse != "N" && reponse != "O")
            {
                cout << "Reponse Invalide! Reessayez." << endl;
                cin >> reponse;
            }
            if (reponse == "N")
            {
                i -= 1;
            }
            else if (reponse == "O")
            {
                campeurs.push_back(*(c.clients[indexe]));
            }
        }
    }
    emplacements_dispo = dispo<Emplacement>(date_debut, date_fin, nb_campeurs);
    if (emplacements_dispo.size() == 0)
    {
        cout << "Desole il n'y a aucun emplacement pour la periode et la capacite demandes" << endl;
        reserve = false;
        goto finish;
    }
    else
    {
        for (int i = 0; i < emplacements_dispo.size(); i++)
        {
            cout << i + 1 << "- " << emplacements_dispo[i];
        }
        cout << "Donner le numero de l'emplacement a reserver : ";
        cin >> k;
        while (k > emplacements_dispo.size() + 1 || k < 1)
        {
            cout << "Entree invalide. Reessayez" << endl;
            cin >> k;
        }

        emplacement = emplacements_dispo[k - 1];
        reserve = true;
    }

    total = emplacement.getppj() * nb_jours;
    cout << "Voulez vous payer maintenant?O/N" << endl;
    cin >> reponse;
    while (reponse != "N" && reponse != "O")
    {
        cout << "Reponse Invalide! Reessayez." << endl;
        cin >> reponse;
    }
    if (reponse == "N")
    {
        paye = false;
    }
    else if (reponse == "O")
    {
        paye = true;
    }
finish:
    paye == false;
}
Reservation::Reservation()
{
    paye = true;
}
float Reservation::calculTotal()
{
    return total;
}
void Reservation::payer()
{
    if (paye == false)
    {
        paye = true;
        cout << "Payment effectue avec success!" << endl;
        for (int i = 0; i < Reservations.size(); i++)
        {
            if (*this == *Reservations[i])
            {
                Reservations.erase(Reservations.begin() + i);
            }
        }
        Reservations.push_back(this);
        fstream f("reservations.txt", ios::out | ios::trunc);
        f.seekg(0);
        for (int i = 0; i < Reservations.size(); i++)
        {
            f << Reservations[i];
        }
    }
    else
    {
        cout << "Reservation Deja Paye";
    }
}
bool Reservation::estPaye()
{
    return paye;
}
template <class T>
vector<T> Reservation::dispo(Date debut, Date fin, int capacite)
{
    vector<Emplacement> emplacements_dispo;
    Emplacement E("", 0, 0);
    E.load_emplacements();
    for (int i = 0; i < E.Emplacements.size(); i++)
    {
        if (E.Emplacements[i]->get_cap() == capacite)
        {
            emplacements_dispo.push_back(*(E.Emplacements[i]));
        }
    }
    this->load_reservations();
    for (int i = 0; i < emplacements_dispo.size(); i++)
    {

        for (int j = 0; j < Reservations.size(); j++)
        {
            if (emplacements_dispo[i].get_id() == Reservations[j]->get_emplacement().get_id() && disjoints(date_debut, date_fin, Reservations[j]->get_datedebut(), Reservations[j]->get_datefin()) == false)
            {
                emplacements_dispo.erase(emplacements_dispo.begin() + i);
                i--;
                break;
            }
        }
    }
    return emplacements_dispo;
}
void Reservation::suavegarder()
{
    fstream f("reservations.txt", ios::out | ios::app);
    f << this;
    this->load_reservations();
}
void Reservation::load_reservations()
{
    Reservations.clear();
    fstream f("reservations.txt", ios::in);
    f.seekg(0);
    while (1)
    {
        if (f.eof())
            break;
        Reservation *r = new Reservation();
        f >> r;
        Reservations.push_back(r);
    }
}
void Reservation::afficher_reservations()
{
    this->load_reservations();
    for (int i = 0; i < Reservations.size(); i++)
    {
        cout << *(Reservations[i]);
    }
}
vector<string> Reservation::get_campeurs_cin()
{
    vector<string> cins;
    for (int i = 0; i < nb_campeurs; i++)
    {
        cins.push_back(campeurs[i].getcin());
    }
    return cins;
}
ostream &operator<<(ostream &os, Reservation &r)
{
    os << "Date Debut : " << r.date_debut << "\tDate Fin : " << r.date_fin << endl
       << "Nombre De Jours : " << r.nb_jours << endl
       << "Nombre de campeurs : " << r.nb_campeurs << endl
       << "les CINs des campeurs :" << endl;
    for (int i = 0; i < r.nb_campeurs; i++)
    {
        os << r.campeurs[i].getcin() << endl;
    }
    os << "Id Emplacement : " << r.emplacement.get_id() << "\tAgence : " << r.agence << endl
       << "Total : " << r.total << "\tPaye : ";
    if (r.paye == true)
    {
        os << "Oui" << endl;
    }
    else if (r.paye == false)
    {
        os << "Non" << endl;
    }
    return os;
}
ostream &operator<<(ostream &os, Reservation *r)
{
    os << endl
       << r->nb_jours << "\t" << &(r->date_debut) << "\t" << &(r->date_fin) << "\t" << r->nb_campeurs << "\t";
    for (int i = 0; i < r->nb_campeurs; i++)
    {
        os << r->campeurs[i].getcin() << "\t";
    }
    os << r->emplacement.get_id() << "\t" << r->agence << "\t" << r->total << "\t" << r->paye;
    return os;
}
istream &operator>>(istream &is, Reservation *r)
{
    client c("", "");
    string nCIN;
    string id_E;
    Emplacement E("", 0, 0, false);
    is >> r->nb_jours >> &(r->date_debut) >> &(r->date_fin) >> r->nb_campeurs;
    for (int i = 0; i < r->nb_campeurs; i++)
    {
        is >> nCIN;
        r->campeurs.push_back(*(c.clients[c.chercher_client(nCIN)]));
    }
    is >> id_E;
    r->emplacement = *(E.Emplacements[E.chercher_emplacement(id_E)]);
    is >> r->agence >> r->total >> r->paye;
    return is;
}