#include <iostream>
#include <fstream>
#include "Date.cpp"
#include "Personne.cpp"
#include "Client.cpp"
#include "Chauffeur.cpp"
#include "Responsable.cpp"
#include "emplacement.cpp"
#include "reservation.cpp"
#include "Admin.cpp"
#include <stdlib.h>
using namespace std;

void menu_client();
void menu_responsable();
void menu_admin();
int main()
{
    //DO NOT TOUCH
    client c("", "");
    c.load_clients();
    chauffeur ch("", "");
    ch.load_chauffeurs();
    Emplacement E("", 0, 0);
    E.load_emplacements();
    Responsable resp("", "");
    resp.load_responsables();
    admin A("");
    A.load_admin();
    Reservation R;
    R.load_reservations();
    //DO NOT TOUCH
    int choix;
    while (1)
    {
        cout << "Vous etes? " << endl
             << "1- Un Client" << endl
             << "2- Un Responsable" << endl
             << "3- l'Administrateur" << endl;
        cin >> choix;
        switch (choix)
        {
        case 1:
            system("CLS");
            menu_client();
            break;
        case 2:
            system("CLS");
            menu_responsable();
            break;
        case 3:
            system("CLS");
            menu_admin();
        default:
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
    return 0;
}

void menu_client()
{ //partie login
    client cl(false, "");
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = cl.chercher_client(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    cl = *(cl.clients[indx]);
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == cl.getdate_de_naissance()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    //FIN LOGIN
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher mes reservations" << endl
             << "3- Reserver un bus" << endl
             << "4- Payer une reservation" << endl
             << "0-Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << cl;
        }
        else if (choix == 2)
        {
            cl.afficher_reservations();
        }
        else if (choix == 3)
        {
            cl.reserver_bus();
        }
        else if (choix == 4)
        {
            cl.payer_reservation();
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}
void menu_responsable()
{
    Responsable resp("", "");
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = resp.chercher_responsable(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    resp = *(resp.responsables[indx]);
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == resp.getdate_de_naissance()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher toutes les reservations" << endl
             << "3- Afficher tous les clients" << endl
             << "4- Ajouter un client" << endl
             << "5- Modifier un client" << endl
             << "6- Supprimer un client" << endl
             << "7- Afficher tous les chauffeurs" << endl
             << "8- Ajouter un chauffeur" << endl
             << "9- Modifier un chauffeur" << endl
             << "10- Supprimer un chauffeur" << endl
             << "11- Afficher tous les responsables" << endl
             << "12- Afficher tous les emplacements" << endl
             << "13- Effectuer une reservation" << endl
             << "0- Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << resp;
        }
        else if (choix == 2)
        {
            resp.afficher_reservations();
        }
        else if (choix == 3)
        {
            resp.afficher_clients();
        }
        else if (choix == 4)
        {
            resp.ajouter_client();
        }
        else if (choix == 5)
        {
            resp.modifier_client();
        }
        else if (choix == 6)
        {

            resp.supprimer_client();
        }
        else if (choix == 7)
        {
            resp.afficher_chauffeurs();
        }
        else if (choix == 8)
        {
            resp.ajouter_chauffeur();
        }
        else if (choix == 9)
        {
            resp.modifier_chauffeur();
        }
        else if (choix == 10)
        {
            resp.supprimer_chauffeur();
        }
        else if (choix == 11)
        {
            resp.afficher_responsables();
        }
        else if (choix == 12)
        {
            resp.afficher_emplacements();
        }
        else if (choix == 13)
        {
            resp.effectuer_reservation();
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}
void menu_admin()
{
    //partie login
    admin admn("");
    admn.load_admin();
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    try
    {
        if (admn.getcin() != nCIN)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE n'est pas le numero de CIN de l'administrateur!!" << endl;
    }
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == admn.getdate_de_naissance()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    //FIN LOGIN
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher les responsables" << endl
             << "3- Ajouter un responsable" << endl
             << "4- Modifier un responsable" << endl
             << "5- Supprimer un responsable" << endl
             << "6- Afficher les emplacements" << endl
             << "7- Ajouter un emplacement" << endl
             << "8- Modifier l'administrateur" << endl
             << "0-Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << admn;
        }
        else if (choix == 2)
        {
            admn.afficher_responsables();
        }
        else if (choix == 3)
        {
            admn.ajouter_responsable();
        }
        else if (choix == 4)
        {
            admn.modifier_responsable();
        }
        else if (choix == 5)
        {
            admn.supprimer_responsable();
        }
        else if (choix == 6)
        {
            admn.afficher_emplacements();
        }
        else if (choix == 7)
        {
            admn.ajouter_emplacement();
        }
        else if (choix == 8)
        {
            admn.modifier_admin();
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}