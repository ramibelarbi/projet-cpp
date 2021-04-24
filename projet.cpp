#include <iostream>
#include <string.h>
#include"projet.h"
using namespace std;Date::Date()
{
    jour=00;
    mois=00;
    annee=0000;
}
Date::Date(int a,int b,int c)
{
    jour=a;
    mois=b;
    annee=c;
}
int Date::getjour()
{
    return (jour);
}
int Date::getmois()
{
    return(mois);
}
int Date::getannee()
{
    return(annee);
}
void Date::setjour(int j)
{
    j=this->jour;
}
void Date::setmois(int m)
{
    m=this->mois;
}
void Date::setannee(int a)
{
    a=this->annee;
}
bool cntr_date(int j, int m, int a)
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if ((j > 31) || (j < 1))
        {
            cout<<"jour invalide. Le jour doit etre compris entre 1 et 31. Reesayez "<<endl;
            return false;
        }

        break;
    case 2:
        if (a % 4 == 0)
        {
            if ((j > 29) || (j < 1))
            {
                cout<<"jour invalide. Le jour doit etre compris entre 1 et 29. Reesayez "<<endl;
                return false;
            }
        }
        else
        {
            if ((j > 28) || (j < 1))
            {
                cout<<"jour invalide. Le jour doit etre compris entre 1 et 28. Reesayez "<<endl;
                return false;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if ((j > 30) || (j < 1))
        {
            cout<<"jour invalide. Le jour doit etre compris entre 1 et 30. Reesayez"<<endl;
            return false;
        }
        break;
    default:
        cout<<"mois invalide. Reesayez "<<endl;
        return false;
        break;
    }
    return true;
}
personne::personne()
{
    nom=' ';
    prenom=' ';
    CIN=' ';
}
personne::personne(string nom,string prenom,string CIN,Date date_de_naissance)
{
    this->nom=nom;
    this->prenom=prenom;
    this->CIN=CIN;
    this->date_de_naissance=date_de_naissance;
}
void personne::saisirpersonne()
{
    cout<<"saisir le nom et le prenom du personne :"<<endl;
    cin>>nom>>prenom;
    cout<<"saisir la carte d'identite nationale "<<endl;
    CIN=verificationcin();
    cout<<"saisir la date de naissance :"<<endl;
    cin>>date_de_naissance;

}
void personne::choix()
{
    int choix;
    cout<<"svp choisir le personne a entrer"<<endl;
    cin>>choix;
    switch(choix)
    {
        case 1:
        {
            cout<<"c'est un client"<<endl;
            break;
        }
        case 2:
        {
            cout<<"c'est une chauffeur"<<endl;
            break;
        }
        case 3:
        {
            cout<<"c'est un guide"<<endl;
            break;
        }
        case 4 :
        {
            cout<<"c'est un responsable"<<endl;
            break;
        }
    }
}
personne:: ~personne()
{
        cout<<"destructeur de personne";
}
void client::saisirclient()
{
    personne p;
    p.saisirpersonne();
    cout<<"ce client avait-il un abonnement pour le bus ?"<<endl;
    if(this->bus==true)
    {
        cout<<"oui"<<endl;
    }
    else
    {
        cout<<"non"<<endl;
    }
    cout<<"quelle est l'emplacement?"<<endl;
    cin>>this->destination;
}
/*void client::reserver()
{

}
void client::reserver_bus()
{

}*/
void chauffeur::saisirchauffeur()
{
    personne p;
    p.saisirpersonne();
    cout<<"donner le numero du permis pour ce chauffeur"<<endl;
    cin>>this->num_permis;
    cout<<"quelle est l'agence qu'il travail avec?"<<endl;
    cin>>this->Agence;
}
void guide::saisirguide()
{
    personne p;
    p.saisirpersonne();
    cout<<"donner la specialite de ce guide"<<endl;
    cin>>this->specialite;
    cout<<"donner l'agence"<<endl;
    cin>>this->agence;
    cout<<"quelle est la destination"<<endl;
    cin>>this->destination;
}