#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
    cout << "Donnez une Date :";
    cin >> jour >> mois >> annee;
    while (cntr_date() == false)
    {
        cin >> jour >> mois >> annee;
    }
}
Date::Date(int a, int b, int c)
{
    jour = a;
    mois = b;
    annee = c;
}
int Date::getjour()
{
    return (jour);
}
int Date::getmois()
{
    return (mois);
}
int Date::getannee()
{
    return (annee);
}
void Date::setjour(int j)
{
    j = this->jour;
}
void Date::setmois(int m)
{
    m = this->mois;
}
void Date::setannee(int a)
{
    a = this->annee;
}
bool Date::cntr_date()
{
    switch (mois)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if ((jour > 31) || (jour < 1))
        {
            cout << "jour invalide. Le jour doit etre compris entre 1 et 31. Reesayez " << endl;
            return false;
        }

        break;
    case 2:
        if (annee % 4 == 0)
        {
            if ((jour > 29) || (jour < 1))
            {
                cout << "jour invalide. Le jour doit etre compris entre 1 et 29. Reesayez " << endl;
                return false;
            }
        }
        else
        {
            if ((jour > 28) || (jour < 1))
            {
                cout << "jour invalide. Le jour doit etre compris entre 1 et 28. Reesayez " << endl;
                return false;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if ((jour > 30) || (jour < 1))
        {
            cout << "jour invalide. Le jour doit etre compris entre 1 et 30. Reesayez" << endl;
            return false;
        }
        break;
    default:
        cout << "mois invalide. Reesayez " << endl;
        return false;
        break;
    }
    return true;
}

Date Date::additionDate(int nb_jours)
{

    int jour, mois, an;
    int jours[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    jour = this->jour;
    mois = this->mois;
    an = this->annee;
    jour += nb_jours;
    while (jour > jours[mois - 1])
    {
        jour -= jours[mois - 1];
        if ((an % 4 == 0) && (mois == 2)) //si fevrier 29 jours
        {
            jour--;
        }

        if (mois < 12)
        {
            mois++;
        }
        else
        {
            mois = 1;
            an++;
        }
    }
    Date fin(jour, mois, an);
    return fin;
}
bool Date::operator<(const Date &d)
{
    if (this->annee < d.annee)
    {
        return true;
    }
    else if (this->mois < d.mois)
    {
        return true;
    }
    else if (this->jour < d.jour)
    {
        return true;
    }
    return false;
}
bool disjoints(Date debut1, Date fin1, Date debut2, Date fin2)
{
    if (fin1 < debut2 || fin2 < debut1)
    {
        return true;
    }
    return false;
}
ostream &operator<<(ostream &os, Date &dt)
{
    os << dt.jour << "/" << dt.mois << "/" << dt.annee;
    return os;
}

istream &operator>>(istream &inc, Date &d)
{
    inc >> d.jour >> d.mois >> d.annee;
    while (d.cntr_date() == false)
    {
        inc >> d.jour >> d.mois >> d.annee;
    }
    return inc;
};
istream &operator>>(istream &is, Date *d)
{
    is >> d->jour >> d->mois >> d->annee;
    return is;
}
ostream &
operator<<(ostream &os, Date *d)
{
    os << d->jour << "\t" << d->mois << "\t" << d->annee;
    return os;
}