#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Personne.cpp"
#include "reservation.h"
#pragma once
using namespace std;

client::client()
{
    while (chercher_client(this->CIN) != -1)
    {
        cout << "Ce numero de CIN existe deja. Saisissez un nouveau numero de CIN : ";
        cin >> CIN;
    }
    char c;
    cout << "Est ce que ce client prendra le bus ? Saisir O/N" << endl;
    cin >> c;
    while (true)
    {
        if (c == 'O')
        {
            bus = true;
            break;
        }
        else if (c == 'N')
        {
            bus = false;
            break;
        }
        else
        {
            cout << "Choix invalide Reessayez" << endl;
        }
    }
}

client::client(bool bus, string destination) : personne("", "", "", Date(1, 1, 2000))
{
    this->bus = bus;
}

void client::reserver_bus()
{
    if (bus == true)
    {
        cout << "le client a deja reserve un bus";
    }
    else
    {
        bus = true;
        clients[chercher_client(CIN)]->bus = true;
        fstream f("clients.txt", ios::out | ios::trunc);
        for (int i = 0; i < clients.size(); i++)
        {
            f << clients[i];
        }
        cout << "Bus reservee avec succes";
    }
}

void client::sauvegarder()
{
    fstream f("clients.txt", ios::out | ios::app);
    f << this;
    this->load_clients();
}
void client::load_clients()
{
    clients.clear();
    fstream f("clients.txt", ios::in);
    f.seekg(0);
    while (1)
    {
        client *cl = new client(false, "");
        if (f.eof())
            break;
        f >> cl;
        clients.push_back(cl);
    }
    clients.pop_back();
}
void client::afficher_clients()
{
    this->load_clients();
    for (int i = 0; i < clients.size(); i++)
    {
        cout << *(clients[i]);
    }
}
int client::chercher_client(string nCIN)
{
    this->load_clients();
    for (int i = 0; i < clients.size(); i++)
    {
        if (nCIN == clients[i]->getcin())
        {
            return i;
        }
    }
    return -1;
}
client::~client()
{
}
template <class T>
vector<T> client::mes_reservations()
{
    vector<Reservation> mes_res;
    Reservation r;
    r.load_reservations();
    for (int i = 0; i < r.Reservations.size(); i++)
    {
        for (int j = 0; j < r.Reservations[i]->get_campeurs_cin().size(); j++)
        {
            if (r.Reservations[i]->get_campeurs_cin()[j] == this->CIN)
            {
                mes_res.push_back(*(r.Reservations[i]));
                break;
            }
        }
    }
    return mes_res;
}
void client::afficher_reservations()
{
    vector<Reservation> mes_res;
    mes_res = mes_reservations<Reservation>();
    for (int i = 0; i < mes_res.size(); i++)
    {
        cout << mes_res[i];
    }
}
void client::payer_reservation()
{
    Reservation r;
    vector<Reservation> mes_res;
    mes_res = mes_reservations<Reservation>();
    for (int i = 0; i < mes_res.size(); i++)
    {
        cout << i + 1 << " - " << mes_res[i];
    }
    cout << "Quelle Reservation Voulez vous payez?";
    int choix;
    cin >> choix;
    while (choix > mes_res.size() || choix < 0)
    {
        cout << "Choix invalide. Reessayez!" << endl;
        cin >> choix;
    }
    mes_res[choix - 1].payer();
    r.afficher_reservations();
}
ostream &operator<<(ostream &os, client &c)
{
    string r_bus;
    if (c.bus == true)
    {
        r_bus = "oui";
    }
    else
    {
        r_bus = "non";
    }

    os << "nom : " << c.nom << "\t"
       << "prenom : " << c.prenom << endl
       << "num cin : " << c.CIN << "\t"
       << "Date de Naissance : " << c.date_de_naissance << endl
       << "Bus : " << r_bus << endl;
    return os;
}
ostream &operator<<(ostream &os, client *c)
{
    os << c->nom << "\t"
       << c->prenom << "\t"
       << c->CIN << "\t" << &(c->date_de_naissance) << "\t"
       << c->bus << endl;
    return os;
}
istream &operator>>(istream &is, client *c)
{
    is >> c->nom >> c->prenom >> c->CIN >> &(c->date_de_naissance) >> c->bus;
    return is;
}