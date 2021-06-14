#include <iostream>
#include <string.h>
#include "Date.h"
#pragma once
using namespace std;

class personne
{
protected:
    string nom;
    string prenom;
    string CIN;
    Date date_de_naissance = Date(1, 1, 2000);

public:
    personne();
    personne(string, string, string, Date);
    string getnom() { return nom; }
    string getpernom() { return prenom; }
    string getcin() { return CIN; }
    Date getdate_de_naissance() { return date_de_naissance; }
    string setcin();

    virtual ~personne();
    friend ostream &operator<<(ostream &, personne &);
};