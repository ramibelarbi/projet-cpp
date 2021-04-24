#include <iostream>
#include <string.h>
using namespace std;
class Date
{
    int jour;
    int mois;
    int annee;
public:
    Date();
    Date(int,int,int);
    int getjour();
    int getmois();
    int getannee();
    void setjour(int);
    void setmois(int);
    void setannee(int);
    bool cntr_date(int,int,int);
    friend istream& operator>>(istream&,Date&);

};
class personne
{
    protected:
    string nom;
    string prenom;
    string CIN;
    Date date_de_naissance;
    public :
    personne();
    personne(string,string,string,Date);
    virtual void saisirpersonne();
    virtual void choix();
    virtual ~personne();
};
class client : public personne
{
    protected:
    bool bus;
    string destination;
    public:
    void saisirclient();
    void reserver();
    void reserver_bus();
};
class chauffeur : public personne
{
    protected :
    string num_permis;
    string Agence;
    public:
    void saisirchauffeur();
};
class guide : public personne
{
    protected:
    string specialite;
    string agence;
    string destination;
    public:
    void saisirguide();
};
class responsable : public personne
{
    protected:
    string agence;
    string reponsabilite;
    public:
    void saisirreponsable();
    void ajouter_client();
    void supprimer_client();
};


string verificationcin()
{
    string s;
    cin>>s;
    if(s.size() != 8)
    {
        cout<<"svp donnez un numero d'une carte d'identité nationale valide "<<endl;
        cin>>s;
    }
    else
    {
        return s;
    }
    return 0;
}
istream& operator>>(istream& inc,Date& d )
{
    cout<<"le jour est"<<endl;
    inc>>d.jour;
    cout<<"le mois est"<<endl;
    inc>>d.mois;
    cout<<"l'annee est"<<endl;
    inc>>d.annee;
    return inc;
};
string verificationpermis()
{
    string s;
    cin>>s;
    if((s.size() != 9) && (s[2]!='/'))
    {
        cout<<"svp donnez un numero permis valid"<<endl;
        cin>>s;
    }
    else
    {
        return s;
    }
    return 0;
}

