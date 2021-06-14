#include <iostream>
#include <string.h>
#include <vector>
#include "Personne.h"
#pragma once
using namespace std;

class client : public personne
{
protected:
    bool bus;

public:
    static vector<client *> clients;
    client();
    client(bool, string);
    void reserver_bus();
    void sauvegarder();
    void load_clients();
    void afficher_clients();
    int chercher_client(string);
    template <class T>
    vector<T> mes_reservations();
    void afficher_reservations();
    void payer_reservation();
    ~client();
    friend ostream &operator<<(ostream &os, client &c);
    friend ostream &operator<<(ostream &os, client *c);
    friend istream &operator>>(istream &is, client *c);
    void menu();
};
vector<client *> client::clients;