#pragma once
#include <iostream>
using namespace std;

class Date
{
    int jour;
    int mois;
    int annee;

public:
    Date();
    Date(int, int, int);
    int getjour();
    int getmois();
    int getannee();
    void setjour(int);
    void setmois(int);
    void setannee(int);
    bool cntr_date();
    Date additionDate(int);
    bool operator<(const Date &);
    friend bool disjoints(Date, Date, Date, Date);
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date *);
    friend ostream &operator<<(ostream &, Date *);
    bool operator==(const Date &d) const { return (this->jour == d.jour && this->mois == d.mois && this->annee == d.annee); };
};