#include <iostream>
#include <vector>
#include "emplacement.h"
#include "Date.h"
#include "Client.h"
#include <vector>
#pragma once
using namespace std;

class Reservation
{
    int nb_jours;
    Date date_debut = Date(1, 1, 2000);
    Date date_fin = Date(1, 1, 2000);
    int nb_campeurs;
    vector<client> campeurs;
    Emplacement emplacement = Emplacement(" ", 0, 0, false);
    float total;
    bool reserve;
    bool paye;
    string agence;
    vector<Emplacement> emplacements_dispo;

public:
    static vector<Reservation *> Reservations;
    Reservation(string);
    Reservation();
    Date get_datedebut() { return this->date_debut; };
    Date get_datefin() { return date_fin; }
    Emplacement get_emplacement() { return emplacement; };
    vector<string> get_campeurs_cin();
    bool get_reserve() { return reserve; };
    void suavegarder();
    void load_reservations();
    void afficher_reservations();
    template <class T>
    vector<T> dispo(Date, Date, int);
    float calculTotal();
    void payer();
    bool estPaye();
    friend ostream &operator<<(ostream &os, Reservation &r);
    friend ostream &operator<<(ostream &os, Reservation *r);
    friend istream &operator>>(istream &is, Reservation *r);
    bool operator==(const Reservation &R) const { return (this->emplacement == R.emplacement && this->date_debut == R.date_debut && this->date_fin == R.date_fin); };
};
vector<Reservation *> Reservation::Reservations;