#include <iostream>
#include <string.h>
#include "Personne.h"
#pragma once
using namespace std;

personne::personne()
{
    cout << "saisir le nom et le prenom de la personne :" << endl;
    cin >> nom >> prenom;
    cout << "saisir la carte d'identite nationale " << endl;
    CIN = setcin();
    cout << "saisir la date de naissance :" << endl;
    cin >> date_de_naissance;
}
personne::personne(string nom, string prenom, string CIN, Date date_de_naissance)
{
    this->nom = nom;
    this->prenom = prenom;
    this->CIN = CIN;
    this->date_de_naissance = date_de_naissance;
}
string personne::setcin()
{
    int len, i;
    bool verif = false;
    string aux;
    while (verif == false)
    {
        cin >> aux;
        verif = true;
        len = aux.length();
        if (len != 8)
        {
            cout << "Le numero de CIN doit contenir exactement 8 chiffres. Reesayez" << endl;
            verif = false;
            continue;
        }
        else
        {
            for (i = 0; i < len; i++)
            {
                if ((aux[i] < '0') || (aux[i] > '9'))
                {
                    cout << "Le numero de CIN ne doit contenir que des chiffres. Reesayez" << endl;
                    verif = false;
                    break;
                }
            }
        }
    }
    return aux;
}
personne::~personne()
{
}
ostream &operator<<(ostream &os, personne &p)
{
    os << "nom : " << p.nom << "\t"
       << "prenom : " << p.prenom << endl
       << "num cin : " << p.CIN << "\t"
       << "Date de Naissance : " << p.date_de_naissance << endl;
    return os;
}